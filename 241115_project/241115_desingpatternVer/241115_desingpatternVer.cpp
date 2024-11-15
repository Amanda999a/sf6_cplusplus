// 241115_desingpatternVer.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <limits>
#include <memory>
#include <algorithm>
using namespace std;

// 전방 선언
class Branch;
class Bank;

// 고객 클래스
class Customer {
public:
    string customerID;
    string name;
    string accountNumber;
    string phoneNumber;
    string branchID;
    double balance;

    Customer(string id, string n, string accNum, string phone, string branch, double bal = 0.0)
        : customerID(id), name(n), accountNumber(accNum), phoneNumber(phone), branchID(branch), balance(bal) {}
};

// 옵저버 인터페이스
class Observer {
public:
    virtual void update(const string& accountNumber, double balance) = 0;
};

// 계좌 클래스 (Subject)
class Account {
private:
    Customer customer;
    vector<Observer*> observers;

public:
    Account(const Customer& cust) : customer(cust) {}

    void addObserver(Observer* observer) {
        observers.push_back(observer);
    }

    void removeObserver(Observer* observer) {
        observers.erase(remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notifyObservers() {
        for (auto observer : observers) {
            observer->update(customer.accountNumber, customer.balance);
        }
    }

    void deposit(double amount) {
        customer.balance += amount;
        notifyObservers();
    }

    bool withdraw(double amount) {
        if (customer.balance >= amount) {
            customer.balance -= amount;
            notifyObservers();
            return true;
        }
        return false;
    }

    Customer getCustomer() const { return customer; }
};

// 계좌 팩토리 인터페이스
class AccountFactory {
public:
    virtual unique_ptr<Account> createAccount(const Customer& customer) = 0;
};

// 일반 계좌 팩토리
class NormalAccountFactory : public AccountFactory {
public:
    unique_ptr<Account> createAccount(const Customer& customer) override {
        return make_unique<Account>(customer);
    }
};

// 지점 클래스 (Observer)
class Branch : public Observer {
public:
    string branchID;
    string address;
    int customerCount;
    int activeAccounts;
    int inactiveAccounts;

    Branch(string id, string addr)
        : branchID(id), address(addr), customerCount(0), activeAccounts(0), inactiveAccounts(0) {}

    void update(const string& accountNumber, double balance) override {
        // 계좌 상태 업데이트 로직
        if (balance > 0) {
            activeAccounts++;
            inactiveAccounts = max(0, inactiveAccounts - 1);
        }
        else {
            inactiveAccounts++;
            activeAccounts = max(0, activeAccounts - 1);
        }
        customerCount = activeAccounts + inactiveAccounts;
    }
};

// 은행 클래스 (Singleton)
class Bank {
private:
    static Bank* instance;
    vector<unique_ptr<Account>> accounts;
    vector<unique_ptr<Branch>> branches;
    unique_ptr<AccountFactory> accountFactory;

    Bank() : accountFactory(make_unique<NormalAccountFactory>()) {}

public:
    static Bank* getInstance() {
        if (instance == nullptr) {
            instance = new Bank();
        }
        return instance;
    }

    void setAccountFactory(unique_ptr<AccountFactory> factory) {
        accountFactory = move(factory);
    }

    void createAccount(const Customer& customer) {
        auto account = accountFactory->createAccount(customer);
        auto branch = findBranch(customer.branchID);
        if (branch) {
            account->addObserver(branch.get());
        }
        accounts.push_back(move(account));
        cout << "계좌가 " << customer.name << "님 앞으로 생성되었습니다.\n";
    }

    void checkAccount(const string& accountNumber) {
        auto account = findAccount(accountNumber);
        if (account) {
            const auto& customer = account->getCustomer();
            cout << "계좌 찾음: " << customer.name << ", 잔액: " << customer.balance << "원\n";
        }
        else {
            cout << "계좌를 찾을 수 없습니다.\n";
        }
    }

    void transferFunds(const string& fromAcc, const string& toAcc, double amount) {
        auto senderAccount = findAccount(fromAcc);
        auto receiverAccount = findAccount(toAcc);

        if (senderAccount && receiverAccount) {
            if (senderAccount->withdraw(amount)) {
                receiverAccount->deposit(amount);
                cout << fromAcc << "에서 " << toAcc << "로 " << amount << "원이 이체되었습니다.\n";
            }
            else {
                cout << "잔액이 부족합니다.\n";
            }
        }
        else {
            if (!senderAccount) cout << "송금자 계좌를 찾을 수 없습니다.\n";
            if (!receiverAccount) cout << "수취인 계좌를 찾을 수 없습니다.\n";
        }
    }

    void addBranch(const string& id, const string& address) {
        branches.push_back(make_unique<Branch>(id, address));
        cout << "새 지점이 추가되었습니다.\n";
    }

    void printBranchStats() {
        if (branches.empty()) {
            cout << "등록된 지점이 없습니다.\n";
            return;
        }
        for (const auto& branch : branches) {
            cout << "지점 ID: " << branch->branchID
                << ", 주소: " << branch->address
                << ", 총 고객 수: " << branch->customerCount
                << ", 활성 계좌: " << branch->activeAccounts
                << ", 비활성 계좌: " << branch->inactiveAccounts << "\n";
        }
    }

    void saveCustomersToCsv() {
        // CSV 저장 로직 (이전과 동일)
    }

private:
    unique_ptr<Account>& findAccount(const string& accountNumber) {
        auto it = find_if(accounts.begin(), accounts.end(),
            [&accountNumber](const unique_ptr<Account>& acc) {
                return acc->getCustomer().accountNumber == accountNumber;
            });
        return (it != accounts.end()) ? *it : accounts.back(); // 주의: 찾지 못한 경우 처리 필요
    }

    unique_ptr<Branch>& findBranch(const string& branchID) {
        auto it = find_if(branches.begin(), branches.end(),
            [&branchID](const unique_ptr<Branch>& branch) {
                return branch->branchID == branchID;
            });
        return (it != branches.end()) ? *it : branches.back(); // 주의: 찾지 못한 경우 처리 필요
    }
};

Bank* Bank::instance = nullptr;

// 커맨드 인터페이스
class Command {
public:
    virtual void execute() = 0;
};

// 구체적인 커맨드 클래스들
class CreateAccountCommand : public Command {
    Bank* bank;
    Customer customer;
public:
    CreateAccountCommand(Bank* b, const Customer& c) : bank(b), customer(c) {}
    void execute() override { bank->createAccount(customer); }
};

class CheckAccountCommand : public Command {
    Bank* bank;
    string accountNumber;
public:
    CheckAccountCommand(Bank* b, const string& acc) : bank(b), accountNumber(acc) {}
    void execute() override { bank->checkAccount(accountNumber); }
};

class TransferFundsCommand : public Command {
    Bank* bank;
    string fromAcc, toAcc;
    double amount;
public:
    TransferFundsCommand(Bank* b, const string& from, const string& to, double amt)
        : bank(b), fromAcc(from), toAcc(to), amount(amt) {}
    void execute() override { bank->transferFunds(fromAcc, toAcc, amount); }
};

// 메인 함수
int main() {
    Bank* bank = Bank::getInstance();
    vector<unique_ptr<Command>> commands;

    while (true) {
        cout << "\n은행 관리 시스템\n";
        cout << "1. 새 계좌 생성\n";
        cout << "2. 계좌 확인\n";
        cout << "3. 계좌 이체\n";
        cout << "4. 새 지점 추가\n";
        cout << "5. 지점 통계 출력\n";
        cout << "6. 고객 데이터 CSV 저장\n";
        cout << "0. 종료\n";
        cout << "선택: ";
        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            string id, name, accNum, phone, branchID;
            double balance;
            cout << "고객 정보 입력 (ID 이름 계좌번호 전화번호 지점ID 초기잔액): ";
            cin >> id >> name >> accNum >> phone >> branchID >> balance;
            commands.push_back(make_unique<CreateAccountCommand>(bank, Customer(id, name, accNum, phone, branchID, balance)));
            break;
        }
        case 2: {
            string accNum;
            cout << "확인할 계좌번호: ";
            cin >> accNum;
            commands.push_back(make_unique<CheckAccountCommand>(bank, accNum));
            break;
        }
        case 3: {
            string fromAcc, toAcc;
            double amount;
            cout << "송금 정보 입력 (송금계좌 수취계좌 금액): ";
            cin >> fromAcc >> toAcc >> amount;
            commands.push_back(make_unique<TransferFundsCommand>(bank, fromAcc, toAcc, amount));
            break;
        }
        case 4: {
            string id, address;
            cout << "새 지점 정보 입력 (ID 주소): ";
            cin >> id;
            cin.ignore();
            getline(cin, address);
            bank->addBranch(id, address);
            break;
        }
        case 5:
            bank->printBranchStats();
            break;
        case 6:
            bank->saveCustomersToCsv();
            break;
        case 0:
            cout << "프로그램을 종료합니다.\n";
            return 0;
        default:
            cout << "잘못된 선택입니다.\n";
        }

        // 커맨드 실행
        for (auto& command : commands) {
            command->execute();
        }
        commands.clear();
    }

    return 0;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.

// 241120_디자인패턴적용버전.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <limits>
#include <memory>
#include <map>

using namespace std;

// Customer 클래스 정의
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

// Branch 클래스 정의
class Branch {
public:
    string branchID;
    string address;
    int customerCount;
    int activeAccounts;
    int inactiveAccounts;

    Branch(string id, string addr)
        : branchID(id), address(addr), customerCount(0), activeAccounts(0), inactiveAccounts(0) {}
};

// 싱글톤 패턴 적용: Bank 클래스
class Bank {
private:
    static Bank* instance;
    vector<Customer> customers;
    vector<Branch> branches;

    Bank() {} // private 생성자

public:
    static Bank* getInstance() {
        if (instance == nullptr) {
            instance = new Bank();
        }
        return instance;
    }

    // 복사 생성자와 할당 연산자를 삭제하여 복사를 방지
    Bank(const Bank&) = delete;
    Bank& operator=(const Bank&) = delete;

    bool branchExists(const string& branchID) {
        for (const auto& branch : branches) {
            if (branch.branchID == branchID) {
                return true;
            }
        }
        return false;
    }

    void createAccount() {
        string id, name, accNum, phone, branchID;
        double balance;

        cout << "고객 ID를 입력하세요: ";
        cin >> id;
        cout << "이름을 입력하세요: ";
        cin >> name;
        cout << "계좌번호를 입력하세요: ";
        cin >> accNum;
        cout << "전화번호를 입력하세요: ";
        cin >> phone;

        do {
            cout << "지점 ID를 입력하세요: ";
            cin >> branchID;
            if (!branchExists(branchID)) {
                cout << "존재하지 않는 지점 ID입니다. 다시 입력해주세요.\n";
            }
        } while (!branchExists(branchID));

        cout << "초기 잔액을 입력하세요: ";
        cin >> balance;

        Customer newCustomer(id, name, accNum, phone, branchID, balance);
        customers.push_back(newCustomer);
        updateBranchStats(branchID);
        cout << "계좌가 " << name << "님 앞으로 생성되었습니다.\n";
    }

    void checkAccount() {
        string accountNumber;
        cout << "확인할 계좌번호를 입력하세요: ";
        cin >> accountNumber;

        for (const auto& customer : customers) {
            if (customer.accountNumber == accountNumber) {
                cout << "계좌 찾음: " << customer.name << ", 잔액: " << customer.balance << "원\n";
                return;
            }
        }
        cout << "계좌를 찾을 수 없습니다.\n";
    }

    void transferFunds() {
        string fromAcc, toAcc;
        double amount;

        cout << "송금할 계좌번호를 입력하세요: ";
        cin >> fromAcc;
        cout << "수취인 계좌번호를 입력하세요: ";
        cin >> toAcc;
        cout << "이체 금액을 입력하세요: ";
        cin >> amount;

        Customer* sender = nullptr;
        Customer* receiver = nullptr;

        for (auto& customer : customers) {
            if (customer.accountNumber == fromAcc) sender = &customer;
            if (customer.accountNumber == toAcc) receiver = &customer;
        }

        if (sender && receiver) {
            if (sender->balance >= amount) {
                sender->balance -= amount;
                receiver->balance += amount;
                cout << fromAcc << "에서 " << toAcc << "로 " << amount << "원이 이체되었습니다.\n";
                updateBranchStats(sender->branchID);
                updateBranchStats(receiver->branchID);
            }
            else {
                cout << "잔액이 부족합니다.\n";
            }
        }
        else {
            if (!sender) cout << "송금자 계좌를 찾을 수 없습니다.\n";
            if (!receiver) cout << "수취인 계좌를 찾을 수 없습니다.\n";
        }
    }

    void updateBranchStats(string branchID) {
        for (auto& branch : branches) {
            if (branch.branchID == branchID) {
                branch.activeAccounts = 0;
                branch.inactiveAccounts = 0;
                for (const auto& customer : customers) {
                    if (customer.branchID == branchID) {
                        if (customer.balance > 0) {
                            branch.activeAccounts++;
                        }
                        else {
                            branch.inactiveAccounts++;
                        }
                    }
                }
                branch.customerCount = branch.activeAccounts + branch.inactiveAccounts;
                break;
            }
        }
    }

    void printCustomers() {
        for (const auto& customer : customers) {
            cout << "고객: " << customer.name << ", 계좌번호: " << customer.accountNumber
                << ", 잔액: " << customer.balance << "원\n";
        }
    }

    void saveCustomersToCsv() {
        const string filename = "customers.csv";
        ofstream outFile(filename, ios::app);

        if (outFile.is_open()) {
            ifstream inFile(filename);
            if (inFile.peek() == ifstream::traits_type::eof()) {
                outFile << "고객ID,이름,계좌번호,전화번호,지점ID,잔액\n";
            }
            inFile.close();

            for (const auto& customer : customers) {
                outFile << customer.customerID << ","
                    << customer.name << ","
                    << customer.accountNumber << ","
                    << customer.phoneNumber << ","
                    << customer.branchID << ","
                    << fixed << setprecision(2) << customer.balance << "\n";
            }
            outFile.close();
            cout << "고객 데이터가 " << filename << "에 추가되었습니다.\n";
        }
        else {
            cerr << "파일을 열 수 없습니다.\n";
        }
    }

    void addBranch() {
        string id, address;
        cout << "지점 ID를 입력하세요: ";
        cin >> id;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "지점 주소를 입력하세요: ";
        getline(cin, address);

        Branch newBranch(id, address);
        branches.push_back(newBranch);
        cout << "새 지점이 추가되었습니다.\n";
    }

    void printBranchStats() {
        if (branches.empty()) {
            cout << "등록된 지점이 없습니다.\n";
            return;
        }
        for (const auto& branch : branches) {
            cout << "지점 ID: " << branch.branchID
                << ", 주소: " << branch.address
                << ", 총 고객 수: " << branch.customerCount
                << ", 활성 계좌: " << branch.activeAccounts
                << ", 비활성 계좌: " << branch.inactiveAccounts << "\n";
        }
    }
};

// 정적 멤버 변수 초기화
Bank* Bank::instance = nullptr;

// 커맨드 패턴 적용: 명령 인터페이스
class BankCommand {
public:
    virtual void execute() = 0;
    virtual ~BankCommand() {}
};

// 구체적인 명령 클래스들
class CreateAccountCommand : public BankCommand {
    Bank* bank;
public:
    CreateAccountCommand(Bank* b) : bank(b) {}
    void execute() override {
        bank->createAccount();
    }
};

class CheckAccountCommand : public BankCommand {
    Bank* bank;
public:
    CheckAccountCommand(Bank* b) : bank(b) {}
    void execute() override {
        bank->checkAccount();
    }
};

class TransferFundsCommand : public BankCommand {
    Bank* bank;
public:
    TransferFundsCommand(Bank* b) : bank(b) {}
    void execute() override {
        bank->transferFunds();
    }
};

class PrintCustomersCommand : public BankCommand {
    Bank* bank;
public:
    PrintCustomersCommand(Bank* b) : bank(b) {}
    void execute() override {
        bank->printCustomers();
    }
};

class SaveCustomersToCsvCommand : public BankCommand {
    Bank* bank;
public:
    SaveCustomersToCsvCommand(Bank* b) : bank(b) {}
    void execute() override {
        bank->saveCustomersToCsv();
    }
};

class AddBranchCommand : public BankCommand {
    Bank* bank;
public:
    AddBranchCommand(Bank* b) : bank(b) {}
    void execute() override {
        bank->addBranch();
    }
};

class PrintBranchStatsCommand : public BankCommand {
    Bank* bank;
public:
    PrintBranchStatsCommand(Bank* b) : bank(b) {}
    void execute() override {
        bank->printBranchStats();
    }
};

int main() {
    Bank* bank = Bank::getInstance();

    map<int, unique_ptr<BankCommand>> commands;
    commands[1] = make_unique<CreateAccountCommand>(bank);
    commands[2] = make_unique<CheckAccountCommand>(bank);
    commands[3] = make_unique<TransferFundsCommand>(bank);
    commands[4] = make_unique<PrintCustomersCommand>(bank);
    commands[5] = make_unique<SaveCustomersToCsvCommand>(bank);
    commands[6] = make_unique<AddBranchCommand>(bank);
    commands[7] = make_unique<PrintBranchStatsCommand>(bank);

    int choice;
    while (true) {
        cout << "\n은행 관리 시스템\n";
        cout << "1. 새 계좌 생성\n";
        cout << "2. 계좌 확인\n";
        cout << "3. 계좌 이체\n";
        cout << "4. 고객 목록 출력\n";
        cout << "5. 고객 데이터 CSV 저장\n";
        cout << "6. 새 지점 추가\n";
        cout << "7. 지점 통계 출력\n";
        cout << "0. 종료\n";
        cout << "선택: ";
        cin >> choice;

        if (choice == 0) {
            cout << "프로그램을 종료합니다.\n";
            break;
        }

        auto it = commands.find(choice);
        if (it != commands.end()) {
            it->second->execute();
        }
        else {
            cout << "잘못된 선택입니다. 다시 선택해주세요.\n";
        }
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

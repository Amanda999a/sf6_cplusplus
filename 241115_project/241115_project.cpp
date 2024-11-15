// 241115_project.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <limits>
using namespace std;

// 고객 클래스 정의
class Customer {
public:
    string customerID;
    string name;
    string accountNumber;
    string phoneNumber;
    string branchID;
    double balance;

    // 고객 객체 생성자
    Customer(string id, string n, string accNum, string phone, string branch, double bal = 0.0)
        : customerID(id), name(n), accountNumber(accNum), phoneNumber(phone), branchID(branch), balance(bal) {}
};

// 지점 클래스 정의
class Branch {
public:
    string branchID;
    string address;
    int customerCount;
    int activeAccounts;
    int inactiveAccounts;

    // 지점 객체 생성자
    Branch(string id, string addr)
        : branchID(id), address(addr), customerCount(0), activeAccounts(0), inactiveAccounts(0) {}
};

// 은행 클래스 정의
class Bank {
private:
    vector<Customer> customers;  // 고객 목록
    vector<Branch> branches;     // 지점 목록

public:
    // 지점 존재 여부 확인 함수
    bool branchExists(const string& branchID) {
        for (const auto& branch : branches) {
            if (branch.branchID == branchID) {
                return true;
            }
        }
        return false;
    }

    // 새 계좌 생성 함수
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

        // 유효한 지점 ID 입력 받기
        do {
            cout << "지점 ID를 입력하세요: ";
            cin >> branchID;
            if (!branchExists(branchID)) {
                cout << "존재하지 않는 지점 ID입니다. 다시 입력해주세요.\n";
            }
        } while (!branchExists(branchID));

        cout << "초기 잔액을 입력하세요: ";
        cin >> balance;

        // 새 고객 객체 생성 및 목록에 추가
        Customer newCustomer(id, name, accNum, phone, branchID, balance);
        customers.push_back(newCustomer);
        updateBranchStats(branchID);
        cout << "계좌가 " << name << "님 앞으로 생성되었습니다.\n";
    }

    // 계좌 확인 함수
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

    // 계좌 이체 함수
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

        // 송금자와 수취인 계좌 찾기
        for (auto& customer : customers) {
            if (customer.accountNumber == fromAcc) sender = &customer;
            if (customer.accountNumber == toAcc) receiver = &customer;
        }

        // 이체 처리
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

    // 지점 통계 업데이트 함수
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

    // 고객 목록 출력 함수
    void printCustomers() {
        for (const auto& customer : customers) {
            cout << "고객: " << customer.name << ", 계좌번호: " << customer.accountNumber
                << ", 잔액: " << customer.balance << "원\n";
        }
    }

    // 고객 데이터를 CSV 파일로 저장하는 함수
    void saveCustomersToCsv() {
        const string filename = "customers.csv";

        // 파일을 추가 모드로 엽니다.
        ofstream outFile(filename, ios::app);

        if (outFile.is_open()) {
            // 파일이 비어있다면 헤더를 추가합니다.
            ifstream inFile(filename);
            if (inFile.peek() == ifstream::traits_type::eof()) {
                outFile << "고객ID,이름,계좌번호,전화번호,지점ID,잔액\n";
            }
            inFile.close();

            // 고객 데이터를 CSV 형식으로 파일에 추가
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

    // 새 지점 추가 함수
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

    // 지점 통계 출력 함수
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

// 메인 함수
int main() {
    Bank bank;
    int choice;

    while (true) {
        // 메뉴 출력
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

        // 사용자 선택에 따른 기능 실행
        switch (choice) {
        case 1:
            bank.createAccount();
            break;
        case 2:
            bank.checkAccount();
            break;
        case 3:
            bank.transferFunds();
            break;
        case 4:
            bank.printCustomers();
            break;
        case 5:
            bank.saveCustomersToCsv();
            break;
        case 6:
            bank.addBranch();
            break;
        case 7:
            bank.printBranchStats();
            break;
        case 0:
            cout << "프로그램을 종료합니다.\n";
            return 0;
        default:
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

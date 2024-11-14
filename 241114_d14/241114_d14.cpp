// 241114_d14.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Customer {
public:
    std::string customerID;
    std::string name;
    std::string accountNumber;
    std::string phoneNumber;
    std::string branchID;

    Customer(std::string id, std::string n, std::string accNum, std::string phone, std::string branch)
        : customerID(id), name(n), accountNumber(accNum), phoneNumber(phone), branchID(branch) {}
};

class Branch {
public:
    std::string branchID;
    std::string address;
    int customerCount;
    int activeAccounts;

    Branch(std::string id, std::string addr)
        : branchID(id), address(addr), customerCount(0), activeAccounts(0) {}
};

class Bank {
private:
    std::vector<Customer> customers;
    std::vector<Branch> branches;

public:
    void createAccount(Customer newCustomer) {
        customers.push_back(newCustomer);
        std::cout << "Account created for " << newCustomer.name << "\n";
    }

    void checkAccount(std::string accountNumber) {
        for (const auto& customer : customers) {
            if (customer.accountNumber == accountNumber) {
                std::cout << "Account found: " << customer.name << "\n";
                return;
            }
        }
        std::cout << "Account not found.\n";
    }

    void transferFunds(std::string fromAcc, std::string toAcc, double amount) {
        // 단순한 예시로, 실제로는 잔액 확인 및 업데이트가 필요함.
        std::cout << "Transferred " << amount << " from " << fromAcc << " to " << toAcc << "\n";
    }
};

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.

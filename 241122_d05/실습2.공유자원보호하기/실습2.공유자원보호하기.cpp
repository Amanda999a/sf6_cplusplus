// 실습2.공유자원보호하기.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <thread>
#include <Windows.h>
#include <vector>
#include <string>
#include <chrono>
#include <queue>
#include <mutex>

using namespace std;

class BankAccount {
private:
    int balance;
    mutable std::mutex mtx;
    //std::mutex mtx;

public:
    BankAccount(int initial_balance) : balance(initial_balance) {}


    // 입금
    void deposit(int amount) {
        std::lock_guard<std::mutex> lock(mtx);
        balance += amount;
        std::cout << "Deposited " << amount << ", new balance: " << balance << std::endl;
    }
    // 출금
    void withdraw(int amount) {
        std::lock_guard<std::mutex> lock(mtx);
        if (balance >= amount) {
            balance -= amount;
            std::cout << "Withdrew " << amount << ", new balance: " << balance << std::endl;
        }
        else {
            std::cout << "Failed to withdraw " << amount << ", balance: " << balance << std::endl;
        }
    }

    // 잔액 확인
    int get_balance() const {
        std::lock_guard<std::mutex> lock(mtx);
        return balance;
    }


};

void deposit_task(BankAccount& account, int amount, int times) {
    for (int i = 0; i < times; i++) {
        account.deposit(amount);
    }
}

void withdraw_task(BankAccount& account, int amount, int times) {
    for (int i = 0; i < times; i++) {
        account.withdraw(amount);
    }
}

int main() {
    // 잔고 1000원 초기화
    BankAccount account(1000);

    // 100원을 100번 입금
    thread t1(deposit_task, ref(account), 100, 100);

    // 100원을 100번 출금
    thread t2(withdraw_task, ref(account), 100, 100);

    t1.join();
    t2.join();

    cout << "잔액 조회 : " << account.get_balance() << endl;

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

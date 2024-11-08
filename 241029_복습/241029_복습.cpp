// 241029_복습.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm> // std::max

using namespace std;

// 두 개의 정수를 더하는 함수
int add(int a, int b) {
    return a + b;
}

// 두 개의 정수의 차를 계산하는 함수 (큰 수에서 작은 수를 뺌)
int sub(int a, int b) {
    return max(a, b) - min(a, b);
}

// 두 개의 정수를 곱하는 함수
int mul(int a, int b) {
    return a * b;
}

// 두 개의 정수를 나누는 함수 (실수 결과 반환)
double divide(int a, int b) {
    if (b == 0) {
        cerr << "Error: Division by zero." << endl;
        return 0; // 오류 처리
    }
    return static_cast<double>(a) / b;
}

// 하나의 정수를 받아 짝수/홀수를 출력하는 함수
void checkEvenOdd(int num) {
    if (num % 2 == 0) {
        cout << num << "은 짝수입니다." << endl;
    }
    else {
        cout << num << "은 홀수입니다." << endl;
    }
}

// 세 개의 수 중 가장 큰 수를 반환하는 함수
int findMax(int a, int b, int c) {
    return max({ a, b, c });
}

int main() {
    int x = 10;
    int y = 5;

    // 각 연산 함수 호출 및 결과 출력
    cout << "Add: " << add(x, y) << endl;
    cout << "Sub: " << sub(x, y) << endl;
    cout << "Mul: " << mul(x, y) << endl;
    cout << "Divide: " << divide(x, y) << endl;

    // 짝수/홀수 확인
    checkEvenOdd(x);

    // 세 수 중 가장 큰 수 찾기
    int a = 3, b = 7, c = 5;
    cout << "Max of (" << a << ", " << b << ", " << c << ") is: " << findMax(a, b, c) << endl;

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

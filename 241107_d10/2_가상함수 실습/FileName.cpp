#include <iostream>
using namespace std;

static int count1 = 0; // 파일 내에서만 접근 가능
void incrementCounter() {
    count1++;
    cout << "incrementCounter : " << count1 << endl;
}

void incrementCounter2() {
    count1++;
    cout << "incrementCounter2 : " << count1 << endl;
}
#include <iostream>
using namespace std;

static int count1 = 0; // ���� �������� ���� ����
void incrementCounter() {
    count1++;
    cout << "incrementCounter : " << count1 << endl;
}

void incrementCounter2() {
    count1++;
    cout << "incrementCounter2 : " << count1 << endl;
}
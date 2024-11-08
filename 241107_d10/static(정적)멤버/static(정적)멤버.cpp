// static(정적)멤버.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

class Counter {
private:
    int num;
public:
    static int count; // static 멤버 변수 선언. 

    Counter(int n): num(n){
        count++;
    }

    static void incrementCount(Counter & c) {
        count++;
        // num += 1; //incrementCount() 있을때 접근 불가
        c.num += 1;  //incrementCount(Counter & c)일때 가능
        cout << c.num << endl;
    }
};

int Counter::count = 0; // staic은 클래스 내부에서 선언되었지만 클래스 외부에서만 초기화가 가능
// 하나인데 다른 클래스 애들이 공유하고 있는 것. 한번만 초기화해야하는데 내부에 있으면 여러번 초기화 되기에 외부에서 해줌
// 단 하나의 메모리

int main()
{
    Counter c1(1); 
    Counter c2(2);

    // 전혀 다른 c1, c2 객체가 Counter를 공유
    cout << "count : " << Counter::count << endl;

    Counter::incrementCount(c1);// 객체 없이 호출 가능
    cout << "count : " << Counter::count << endl;

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

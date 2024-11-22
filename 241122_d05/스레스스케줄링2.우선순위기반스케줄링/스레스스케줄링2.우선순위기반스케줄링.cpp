// 스레스스케줄링2.우선순위기반스케줄링.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <thread>
#include <vector>
#include<chrono>
#include <windows.h> 
#include <queue>
using namespace std;

struct Process {
    string name;
    int priority;
    int executionTime;

    //우선순위비교를 위한 연산자 오버로딩
    bool operator< (const Process& other) const {
        return priority < other.priority;
    }
};
void executeProcess(const Process& process) {
    cout << process.name << "실행 중(우선순위 : " << process.priority << ")" << endl;
    this_thread::sleep_for(chrono::seconds(process.executionTime));
    cout << process.name << "완료" << endl;
}
int main()
{
    //우선순위큐 생성
    priority_queue<Process> pq;

    pq.push({ "프로세스 A", 2, 5 });
    pq.push({ "프로세스 B", 1, 3 });
    pq.push({ "프로세스 C", 3, 2 });

    while (!pq.empty()) {
        Process current = pq.top();
        pq.pop();
        executeProcess(current);
    }
    cout << "모든프로세스 완료" << endl;

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

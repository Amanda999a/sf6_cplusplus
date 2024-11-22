// 스레드스케줄링.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <thread>
#include <vector>
#include<chrono>
#include <windows.h> 
using namespace std;

void processTask(string&processesName, int executionTime){
    while (executionTime > 0) {
        // 타임 퀀텀
        int quantum = 2;
        // 남은 시간과 비교
        int timeSlice = min(quantum, executionTime);
        cout << processesName << "실행중 : " << timeSlice << "초" << endl;
        // 실행 시간 대기
        std::this_thread::sleep_for(chrono::seconds(timeSlice));
        executionTime -= timeSlice;
    }
    cout << processesName << "완료\n";
}

int main()
{//작업량을 processes로 설정
    vector<pair<string, int>> processes = {
        {"프로세스 1", 5}, // 5초의 시간이 필요(2씩 뺸다)
        {"프로세스 2", 8}, // 8초의 시간이 필요
        {"프로세스 3", 3} // 3초의 시간이 필요
    };

    while (!processes.empty()) {
        for (auto it = processes.begin(); it != processes.end(); ) {
            // 2초마다 실행(작업시간)
            processTask(it->first, 2);
            it->second -= 2;

            if (it->second <= 0) {
                it = processes.erase(it);
            }// 작업량이 없어지면 삭제
            else {//다음프로세스 적용
                ++it;
            }
        }
    }

    cout << "모든 프로세스 완료" << endl;
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

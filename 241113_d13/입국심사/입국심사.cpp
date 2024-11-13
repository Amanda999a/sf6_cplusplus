// 입국심사.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    //최소 걸리는 시간
    long long start = 1;
    //최대 걸리는 시간
    long long end = *max_element(times.begin(), times.end()) * static_cast<long long>(n); // longlong이 int 보다 더 크다.안전을 위해 n이 아니라 * static_cast<long long>(n) 

    while (start <= end) {
        long long mid = (start + end) / 2;
        long long total = 0; //총 몇명

        for (int time : times) {
                total += mid / time;
                if (total >= n) break;
        }
        if (total >= n) {
            answer = mid;
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
    return answer;
}

int main()
{
    solution(6, { 7, 10 });
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

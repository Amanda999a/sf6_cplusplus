// 문제-타겟넘버.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <string>
#include <vector>
#include <queue>

using namespace std;
//DFS로 풀기
//int dfs(vector<int>&numbers, int target, int index, int currentSum) {
//    if (index == numbers.size()) {
//        return (currentSum == target) ? 1 : 0; //타겟과 커렌트 썸이 같으면 카운트
//    }
//
//    int add = dfs(numbers, target, index + 1, currentSum + numbers[index]); //더하기 연산
//    int subtract = dfs(numbers, target, index + 1, currentSum - numbers[index]); // 빼기 연산
//
//    return add + subtract;
//}

//bfs로 풀기
//BFS는 최단 거리문제에 주로 쓰임
int solution(vector<int> numbers, int target) {
    int answer = 0;
    queue<pair<int, int>> q; //pair 쌍으로 q에 저장한다
    q.push({ 0, 0 }); // {현재까지의 합, 현재 인덱스}

    while (!q.empty()) {
        int currentSum = q.front().first;
        int index = q.front().second;
        q.pop();

        //검사
        if (index == numbers.size()) {
            if (currentSum == target) answer++; //타겟이면 answer가 카운딩됨
        }
        else {
            q.push({ currentSum + numbers[index], index + 1 });
            q.push({ currentSum - numbers[index], index + 1 });
        }
    }
    return answer;
}

int main()
{
    solution({ 1, 1, 1, 1 }, 3);

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

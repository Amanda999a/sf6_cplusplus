// 문제-게임맵최단거리.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int n = maps.size(); // 행
    int m = maps[0].size(); // 열

    vector<vector<bool>> visited(n, vector<bool>(m,false)) ; // 시간 단축용코드

    queue<pair<int, int>> q;
    q.push({ 0,0 });
    visited [0][0] = true;

    int dx[] = { -1, 1, 0, 0 };
    int dy[] = { 0, 0, -1, 1 };

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        int dist = maps[y][x];

        q.pop();

        if (x == m - 1 && y == n - 1) {
            return dist;
        }
        else {
            // 상 하 좌 우 이동
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                //지도를 넘어 갔는지 && 벽인지 구별이 필요
                if (nx >= 0 && ny >= 0 && nx < m && ny < n 
                    && maps[ny][nx] == 1 && !visited[ny][nx]) {
                    maps[ny][nx] = dist + 1;
                    visited[ny][nx] = true;
                    q.push({ nx, ny });
                }
            }
        }
    }
    return answer;

    //for (int i = 0; i < 4; i++) {
    //    //pos={0,0}
    //    //pos.x + dx[i], pos.y + dy[i];
    //    //상하좌우 설정
    //    // 0 일 경우 왼쪽으로 이동
    //    // 1 일 경우 오른쪽으로 이동
    //    // 2 일 경우 위로 이동
    //    // 3 일 경우 아래로 이동
    //}
}


int main()
{
    solution({  {1, 0, 1, 1, 1},
                {1, 0, 1, 1, 1},
                {1, 0, 1, 1, 1},
                {1, 1, 1, 0, 1},
                {0, 0, 0, 0, 1}

        });
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

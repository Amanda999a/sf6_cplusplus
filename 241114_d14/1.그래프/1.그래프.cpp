// 1.그래프.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//자료구조
// 데이터를 효율적으로 관리하기 위한 구조

//그래프
// 

class Graph {
private:
    int vertices; // 정점의 개수
    vector<vector<int>> adjList; //인접리스트
public:
    //그래프 생성자(초기화)
    Graph(int v) : vertices(v) {
        adjList.resize(v);
    }

    //간선 추가(무방향 그래프) - src, dest 양방향으로 해줘야함
    void addEgde(int src, int dest) {
        adjList[src].push_back(dest);
        adjList[dest].push_back(src);
    }
    void print() {
        cout << "정점의 개수 : " << vertices <<endl;
        cout << "간선 : " << endl;
        int i = 0;
        for (vector<int>vec : adjList) {
            cout << i << "번째 [ ";
            for (int num : vec) {
                cout << num<<  ",";
            }
            cout << " ]" << endl;
            i++;
        }
    }
    // DFS 구현(재귀)
    void DFS(int start) { //start : 첫 방문
        //정정 검사. 정점의 개수만큼 false 초기화
        vector<bool> visited(vertices, false);
        cout << "DFS시작" << endl;
        DFSUtil(start, visited);
        cout << endl;
    }
    void DFSUtil(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << v << " "; //잘 나오나 확인
        
        for (int adj : adjList[v]) {
            if (!visited[adj]) {
                DFSUtil(adj, visited); // 방문하지 않았을때 가서 체크
            }// 방문 이미 했으면 그냥 나온다
        }
    }
    // BFS
    void BFS(int start) {
        // 정정 검사.정점의 개수만큼 false 초기화
        vector<bool> visited(vertices, false);
        //정점 저장
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS 시작" << endl;

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            cout << v << " ";

            for (int adj : adjList[v]) {
                if (!visited[adj]) {
                    visited[adj] = true;
                    q.push(adj); // 방문하고 q에 push
                }
            }
        }
        cout << endl;
    }
      
};

int main()
{
    Graph g(6);
    g.addEgde(0, 1);
    g.addEgde(0, 2);
    g.addEgde(1, 3);
    g.addEgde(1, 4);
    g.addEgde(2, 5);


    g.print();
    g.DFS(0);
    g.BFS(0);

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

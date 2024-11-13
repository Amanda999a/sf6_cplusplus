// 3. 힙(heap).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

//힙(heap)
// 완전 이진 트리 구조(왼쪽부터 비운 곳 없이 차례대로 무조건 채우는 것). 부모만 비교
// 레벨이 밑으로 갈수록 높아짐(1레벨 - root, 2레벨 자식, 3레벨 자식의 자식)
// 최대 힙 = 부모 노드 값이 항상 자식 노드의 값보다 크거나 같다. 위로 갈수록 수가 커야함
// 최소 힙 = 부모 노드 값이 항상 자식 노드의 값보다 작거나 같다. 위로 갈수록 수가 작아야함. 

//우선 순위 큐(Priority Queue)
// 우선순위에 따라 삭제 되는 자료 구조

class MaxHeap {
private:
	vector<int> heap;

	//부모 노드 인덱스
	int parent(int i) { return (i - 1) / 2; }

	//왼쪽 자식 노드 인덱스
	int leftChild(int i) { return 2 * i + 1; }

	//오른쪽 자식 노드 인덱스
	int rightChild(int i) { return 2 * i + 2; }

	//힙 재정렬
	void heapifyUp(int i) {
		while (i > 0 && heap[parent(i)]) { //인덱스번호가 0보다 큰가? 부모 인덱스가 작을때 조건
			swap(heap[i], heap[parent(i)]); //스왑해서 재정렬
			i = parent(i); // 가리키는 곳 변경하고 다시 위의 부모와 다시 비교 0번 인덱스에 도달하면 종료
		}
	}
	// 힙 재정렬(삭제)
	void heapifyDown(int i) {
		int largest = i;
		int left = leftChild(i);
		int right = rightChild(i);

		// 최대 인덱스보다 왼쪽 자식 인덱스가 작고
		// 현재 노드 보다 왼쪽 자식 노드가 더 크면
		if (left < heap.size() && heap[left]>heap[largest]) {
			largest = left;
		}
		// 최대 인덱스보다 왼=오른쪽 자식 인덱스가 작고
		// 현재 노드 보다 오른쪽 자식 노드가 더 크면
		if (right < heap.size() && heap[right]>heap[largest]) {
			largest = right;
		}
		if (largest != i) {
			swap(heap[i], heap[largest]);
			heapifyDown(largest);
		}
	}

public:
	MaxHeap() {}

	//요소 삽입
	void insert(int key) {
		heap.push_back(key);
		heapifyUp(heap.size() - 1);
	}

	//최대값을 제거 및 반환
	int extractMax() {
		if (heap.empty()) {
			cout << "힙이 비어 있습니다." << endl;
			return -1;
		}
		int maxValue = heap[0];
		heap[0] = heap.back();
		heap.pop_back();
		heapifyDown(0);
			return maxValue;
	}
}

int main()
{
	MaxHeap maxheap;

	maxheap.insert(20);
	maxheap.insert(30);
	maxheap.insert(40);
	maxheap.insert(5);

	maxheap.extractMax();
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

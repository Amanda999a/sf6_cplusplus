// 2.이진탐색트리.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include<stack>
#include<queue>

using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;

	Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
	Node* root;
public:
	BinaryTree() : root(nullptr) {}

	// 루트 노드를 설정
	void setRoot(int data) {
		root = new Node(data);
	}

	// parent 노드를 찾기 위해 루트 노드를 반환
	Node* getRoot() {
		return root;
	}

	// 보통 왼쪽 자식 노드 먼저 추가
	void addLeft(Node* parent, int data) {
		if (parent->left == nullptr) {
			parent->left = new Node(data);
		}
		else {
			cout << "왼쪽 자식 노드가 이미 존재 합니다" << endl;
		}
	}

	// 오른쪽 자식 노드 추가
	void addRight(Node* parent, int data) {
		if (parent->right == nullptr) {
			parent->right = new Node(data);
		}
		else {
			cout << "오른쪽 자식 노드가 이미 존재 합니다" << endl;
		}
	}
};

//이진 탐색 트리(Binary Search Tree)
// 각 노드가 최대두개의 자식을 가진다
// 왼쪽 서브트리(한덩어리)의 값은 루트 노드보다 작다.
// 오른쪽 서브트리의 값은 루트노드보다 크다.

// 탐색 삽입 삭제가 0(logN)만큼 시간이 걸린다. -> 시간 복잡도에서 성능이 좋다.

class BinarySearchTree {
private:
	Node* root;

	// 노드 삽입(재귀적 구현) 내부함수 insert
	Node* insert(Node* node, int data) {
		if (node == nullptr) {
			return new Node(data); //root 노드가 없는 경우. 새로 만들어서 넘겨주겠다.
		}
		// root 노드가 있는 경우. 있으면 왼쪽에 넣을지 오른쪽에 넣을지 확인해야함
		if (data < node->data) {
			node->left = insert(node->left, data); // 작으면 왼쪽에 재귀함수를 이용해 넣겠다.
		}
		else {
			node->right = insert(node->right, data);// 크면 오른쪽에 재귀함수를 이용해 넣겠다.
		}
		return node;

	}
	bool search(Node* node, int data) {
		if (node == nullptr) return false;
		if (node->data == data) {
			return true;
		}
		else if (data < node->data) {
			return search(node->left, data);
		}// 루트보다 값이 작으니까 왼쪽 서브트리에서만 판별
		else {
			return search(node->right, data); //루트보다 값이 크니까 오른쪽
		}
	}
public:
	//생성자
	BinarySearchTree() : root(nullptr) {}

	//삽입
	void insert(int data) {
		root = insert(root, data);
	}

	bool search(int data) {
		return search(root, data);
	}
};

int main()
{
	BinarySearchTree bst;

	bst.insert(10);
	bst.insert(5);
	bst.insert(15);
	bst.insert(12);
	bst.insert(17);

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

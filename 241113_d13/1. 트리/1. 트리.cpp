// 1. 트리.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

//자료구조

//트리
// 계층 구조를 가지는 비선형 자료구조
// 각 노드는 지식 노드를 가질 수 있으며,
// 루트 노드에서 시작하여 여러 자식 노드를 연결하여 형성

//이진 트리(Binary Tree)
// 각 노드가 최대 두개의 자식 노드를 가지는 트리
// 자식 노드는 왼쪽과 오른쪽으로 나뉘며 자식노드도 이진 트리구조를 따른다.

//순회
// 전위 순회(root 먼저 방분)
//  루트 - 왼쪽 자식 - 오른쪽 자식 순서

// 중위 순회(맨아래 트리에서 왼쪽 - 루트 - 오른쪽 후에 그 상위 트리로 올라감)
//  왼쪽 자식(맨아래) - 루트 - 오른쪽 자식 순서

// 후위 순회(왼쪽 트리하고 오른쪽 트리 후 root으로 감)
//  왼쪽 자식 - 오른쪽 자식 - 루트

#include <iostream>
#include<stack>
#include<queue>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr){}
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
    
    //전위 순회(재귀함수를 사용한)
    void preorderTraversal(Node* node) {
        if (node == nullptr) return;

        cout << node->data << endl; // 위치가 처음
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }

    //중위 순회
    void inorderTraversal(Node* node) {
        if (node == nullptr) return;

        inorderTraversal(node->left);
        cout << node->data << endl; // 위치가 중간
        inorderTraversal(node->right);
    }

    //후위 순회
    void postorderTraversal(Node* node) {
        if (node == nullptr) return;

        postorderTraversal(node->left);
        postorderTraversal(node->right);
        cout << node->data << endl; // 위치가 아래
    }
};


int main()
{
    BinaryTree tree;

    //루트 노드 설정
    tree.setRoot(0);

    Node* root = tree.getRoot();

    //왼쪽 자식 노드 추가
    tree.addLeft(root, 1);

    //오른쪽 자식 노드 추가
    tree.addRight(root, 2);

    tree.addLeft(root->left, 3);
    tree.addRight(root->left, 4); // 비어있는 자리에 들어간다

    tree.addLeft(root->right, 5);
    tree.addRight(root->right, 6);

    //tree.preorderTraversal(root); // 전위
    //tree.inorderTraversal(root); // 중위(트리채 왼쪽부터)
    tree.postorderTraversal(root); // 중위(트리채 왼쪽부터)


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

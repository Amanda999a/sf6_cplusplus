// 2.스택.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;
// 스택(stack)
//후입선출(LIFO) last in First out
// push 데이터를 스택의 맨 위에 추가
// pop 스택의 맨 위에 있는 데이터 삭제
// peek 스택의 맨 위에 있는 데이터 반환(삭제가 아니고 어떤 값이 있는지 확인)

class Stack {
    int arr[100];
    int top;

public:
    //생성자
    Stack() : top(-1) {}
    bool isFull() {
        return top == 100 - 1;
    }
    bool isEmpty() {
        return top == -1;
    }
    // 데이터 삽입
    void push(int data) {
        if (isFull()) {
            cout << "stack이 가득 찼습니다" << endl;
            return;
        }
        arr[++top] = data; //0번째 데이터에 넣겠다.
    }
    // 데이터 삭제
    int pop() {
        if (isEmpty()) {
            cout << "스택이 비어 있습니다" << endl;
            return -1;
        }
        return arr[top--];
    }
    // 데이터 확인
    int peek() {
        if (isEmpty()) {
            cout << "스택이 비어 있습니다" << endl;
            return -1;
        }
        return arr[top];
    }
};
// 큐(Queue) 선입선출(가장 먼저 들어온 데이터가 가장 먼저 삭제된다)
class Queue {
private:
    int arr[100];
    int front;
    int rear;

public:
    // 생성자
    Queue() : front(0), rear(0){}
    bool isFull() {
        return rear == 100;
    }

    bool isEmpty() {
        return rear == front;
    }
    
    void enqueue(int data) {
        if (isFull()) {
            cout << "큐가 가득 찼습니다." << endl;
        }
        arr[rear++] = data;
    }

    //데이터 삭제
    int dequeue() {
        if (isEmpty()) {
            cout << "큐가 비었습니다." << endl;
            return -1;
        }
        return arr[front++];
    }
    //데이터 확인
    int getFront() {
        if (isEmpty()) {
            cout << "큐가 비었습니다." << endl;
            return -1;
        }
        return arr[front];
    }
};

//stack == vector
//queue
#include <queue>

int main()
{
    queue<int> que1;
    que1.push(0);
    que1.push(1);
    que1.pop();
    cout << que1.front() << endl; //1 맨 앞이 빠진다

    Queue queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    cout << "큐의 맨 앞 요소 : " << queue.getFront() << endl;

    cout << "큐의 dequeue : " << queue.dequeue() << endl;
    cout << "큐의 dequeue : " << queue.dequeue() << endl;
    cout << "큐의 dequeue : " << queue.dequeue() << endl;


    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "스택의 최상단 요소 : " << stack.peek() << endl;

    cout << "스택의 pop : " << stack.pop() << endl;
    cout << "스택의 pop : " << stack.pop() << endl;
    cout << "스택의 pop : " << stack.pop() << endl;
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

// 1.자료구조.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
//자료구조
//데이터를 효율적으로 관리하기 위한 구조

//배열
//연속된 메모리 공간에 같은 타입의 데이터를 저장하는 자료 구조
//장점
//인덱스 접근이 가능하다(특정요소에 접근이 빠르다)
//중간 삽입 삭제가 느리다.

//단일 연결리스트(Linked List) - 1번이 2번의 주소값을 가지고 2번이 3번 주소값을 가지는 것
//각 노드가 다음 노드에 대한 포인터를 가지고 있는 자료구조
//장점
//크기가 가변적이고 중간 요소에 삽입 삭제가 빠르다
//단점
//인덱스 접근이 불가
//특정 요소에 접근하려면 처음부터 순회해야함

//? 왜 벡터가 중간 삽입 삭제가 느린가
//>> 데이터는 연속적으로 들어가 있기에 중간 삽입하려면 새로운 것을 만들고 기존의 것을 삭제해야하는 과정(생성-이동-삭제)
//? 왜 노드는 빠른가
//>> 연결된 선만 지워서 연결하면 되서(주소값만 변경 새로 생성하지 않으니까)중간 삽입 삭제가 쉽다.

//이중 연결 리스트(Doubly Linked List)
//차이점 prev 이전 노드를 연결
//단일은 head부터 라면 이중은 처음과 끝부터 탐색을 시작할 수 있다.
//장점
// 처음과 끝 두가지의 선택지가 있기에 중간 삽입 삭제가 조금 더 유연하다
//단점
// 메모리가 더 사용된다

struct Node
{
    int data;
    Node* nextNode;
    Node* prevNode;
};
class DoublyLinkedList{
private:
    Node* head; // 머리(앞)
    Node* tail; // 꼬리(뒤)
public:
    //생성자
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void append(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->nextNode = nullptr; 
        newNode->prevNode = nullptr;
        if (head == nullptr) { //tail 여도 상관 없다. 
            //리스트가 비어 있을때
            head = newNode;
            tail = newNode; 
        }
        
        else {
            //head가 존재 할때
            // append는 원래 뒤에 추가하는 것 new Node 주소값 prev는 그 앞의 주소 값을 넣는다
            tail->nextNode = newNode;
            newNode->prevNode = tail;
            tail = newNode;
            }
        }

    void prepend(int data){ //prepend 앞에 삽입한다
        Node* newNode = newNode;
        newNode->data = data;
        newNode->nextNode = head; // 새로운 노드에 head를 빼어옴
        newNode->prevNode = nullptr;

        if (head != nullptr) {
            //리스트가 비어있을때
            head->prevNode = newNode;
        }
        head = newNode; // 새로운 노드로 변경하곘다

        // 리스트가 비어있을 때만
        if (tail == nullptr) {
            tail = newNode; //비어있다. 생성되자마자 가르키니까
        }
    }
    //소멸자
    ~DoublyLinkedList() {
        Node* temp = head;
        while (temp != nullptr){
            Node* next = temp->nextNode;//next를 지정하고 temp를 지정한 후에 이전 next를 지움
            delete temp;
            temp = next;
    }

}
    
    
};

int main()
{
    std::cout << "Hello World!\n";
    //Big-0 표기법
    //O(1)
    int x = 10;
    //0(n) = O(2n) ; n만큼 시간이 걸린다.
    for (int i = 0; i < n; i++) {

    }
    //0(n**2)
    for (int i = 0; i < n; i++) {
        for (int i = 0; j < n; i++) {

        }
    }
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

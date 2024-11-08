// ConsoleApplication4.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
using namespace std;

class Snack {
	// 접근 제어자 (public, protected, private)
	// public 제어자 : 모든 접근을 허용
	// protected 제어자 : 자식 클래스에서 접근 까지만 허용
	// private 제어자 : 자기 자신에서만 접근 허용
protected:
	int price; // 가격
	string name; // 상품이름
	string manufactuer;// 제조회사
public:
	Snack(int p, string n, string m) :price(p), name(n), manufactuer(m) {}

	virtual string getName() {
		cout << "부모 클래스 함수" << endl;
		return name;
	}
	virutal void show Manufacturer() = 0; 
};

class Candy : public Snack {
private:
	string flavor; // 맛
public:
	Candy(int p, string n, string m, string f) :Snack(p, n, m), flavor(f) {}

	string getName() {
		return name;
		void showManufacturer() {
			cout << "Candy 제조사 : " 
	}
	}
};

class Chocolate : public Snack {
private:
	string shape; // 모양
public:
	Chocolate(int p, string n, string m, string s) :Snack(p, n, m), shape(s) {}

	string getName() {
		return name;
	}
	string getShape() {
		return shape;
	}
};

int main()
{
	Candy candy1;
	Snack* snackPtr = &candy1;

	snackPtr->getName();

	// 자식 부분이 잘리기 때문에 그 개념을 이해해야 하는 부분
	/*Snack snack1 = chocolate1;
	snack1.getName();*/

	// snack 포인터 배열
	Snack* snackBasket[4] = { &candy1, &candy2, &chocolate1, &chocolate1 };

	for (int i = 0; i < 4; i++) {
		cout << "snack " << i << " : " << snackBasket[i]->getName() << endl;
	}

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

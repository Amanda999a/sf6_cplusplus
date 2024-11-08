// 업캐스팅&다운캐스팅.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
using namespace std;

class Animal {
public:
	virtual void sound() {
		cout << "동물 소리" << endl;
	}
};
class Cat : public Animal {
public:
	void sound() {
		cout << "고양이 소리" << endl;
	}
	void bark() {
		cout << "야옹" << endl;
	}
};
//class Dog : public Animal {
//public:
//	void sound() {
//		cout << "강아지 소리" << endl;
//	}
//};
int main()
{
	Cat cat1;
	//Dog dog1;

	//Animal* animalPtr = &dog1;
	Animal* animalPtr = &cat1; // 업 캐스팅(Cat -> Animal); animalPtr은 부모의 값이 아닌 상속관계인 자식의 값을 담았다(안정적)

	animalPtr->sound();// 동적 바인딩으로 연결 (다형성)
	//animatPtr->bark(); // 부모에게 없어서 연결되지 않음
	
	//Cat* catPtr = (Cat*)animalPtr; // 다운캐스팅.Animal인데 cat클래스로 변경. 강제적인 코드라 비추천
	//if (catPtr) {
	//	catPtr->bark();
	//}
	//else {
	//	cout << "다운캐스팅실패" << endl;
	//}

	Cat* catPtr = dynamic_cast<Cat*>(animalPtr); // 다운캐스팅안전성을 위해 dynamic_cast가 쓰인다
	if (catPtr) {
		catPtr->bark();
	}
	else {
		cout << "다운캐스팅실패" << endl;
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

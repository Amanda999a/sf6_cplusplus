// 2_가상함수 실습.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
public:
	virtual void intro() {
		cout << "사람입니다~" << endl;
	}
};
class Student : public Person {
	string name;
public:
	Student(string name) {
		this->name = name;
	}
	void intro() {
		cout << name << "학생입니다." << endl;
	}
	void learn() {
		cout << "배웁니다." << endl;
	}
};

class Teacher : public Person {
	string name;

public:
	Teacher(string name) {
		this->name = name;
	}
	void intro() {
		cout << name << "선생입니다" << endl;
	}
	void teach() {
		cout << "가르칩니다" << endl;
	}
};

int main()
{
	Person* pList[3];
	string names[3];

	cout << "3명의 이름을 입력해주세요.(선생님, 학생, 학생)" << endl;
	cin >> names[0] >> names[1] >> names[2];

	//names[] 배열 이용하여 각 class 생성
	pList[0] = new Teacher(names[0]); // 업캐스팅 되어 "선생입니다"출력
	pList[1] = new Student(names[1]); // 업캐스팅 되어 "학생입니다"출력
	pList[2] = new Student(names[2]); // 업캐스팅 되어 "학생입니다"출력

	// pList의 각 요소에서 intro()호출
	for (auto p : pList) {
		p->intro();
	}

	// 각 class의 고유 함수 실행(다운캐스팅 후 실행)
	for (auto p : pList) {
		if (Teacher* teacher = dynamic_cast<Teacher*>(p)) {
			teacher->teach(); //Teacher의 teach() 호출
		}
		else if (Student* student = dynamic_cast<Student*>(p)) {
			student->learn(); // Student의 learn() 호출
		}

		//apahfl gowp
		for (auto p : pList) {
			delete p;
		}

		return 0;
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

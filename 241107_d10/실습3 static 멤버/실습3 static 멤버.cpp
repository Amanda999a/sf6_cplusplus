// 실습3 static 멤버.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Snack {
protected:
	string flavor; // 맛, 모양
	static int count; // 전체 간식 개수
public:
	// 스낵 생성자
	Snack(string f) : flavor(f) { count++; }
	virtual string getInfo() {
		return flavor;
	}
	// 간식 개수를 반환하는 static 함수
	static int getCount() {
		return count;
	}
	virtual ~Snack() {
		count--;
	}
};
// static 변수 초기화
int Snack::count = 0;

class Candy : public Snack {
private:
public:
	// 초콜릿 생성자
	Candy(string s) : Snack(s) {}
	string getInfo() {
		return flavor + "맛 사탕";
	}
	~Candy() {}

};
class Chocolate : public Snack {
private:
public:
	// 초콜릿 생성자
	Chocolate(string s) : Snack(s) {}

	string getInfo() {
		return flavor + "모양 초콜릿";
	}
	~Chocolate() {}
};

int main()
{
	vector<Snack*> snack;

	int check = 1;

	while (true) {
		cout << "과자 바구니에 추가할 간식을 고르세요. (1. 사탕, 2. 초콜릿, 0: 종료):";
		string input;
		cin >> check;
		if (check == 0) {
			break;
		}
		else if (check == 1) {
			cout << "맛을 입력하세요. : ";
			cin >> input;
			snack.push_back(new Candy(input));
		}
		else if (check == 2) {
			cout << "모양을 입력하세요. : ";
			cin >> input;
			snack.push_back(new Chocolate(input));
		}
		else {
			cout << "다시 입력해 주세요 ";
		}
	}
	cout << endl;

	cout << "과자 바구니에 담긴 간식의 개수는 " << Snack::getCount() << " 개 입니다." << endl;
	cout << "과자 바구니에 담긴 간식 확인하기!" << endl;

	for (auto p : snack) {
		cout << p->getInfo() << endl;
	}

	for (auto p : snack) {
		delete p;
	}
	cout << "과자 바구니에 담긴 간식의 개수는 " << Snack::getCount() << " 개 입니다." << endl;

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

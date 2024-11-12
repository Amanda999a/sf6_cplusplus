// 실습2. 회원명부를 이용한 로그인 기능.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {

	string inputName, inputPw;

	// 사용자 입력
	cout << "사용자 이름을 입력하세요. :";
	cin >> inputName;
	cout << "사용자 패스워드를 입력하세요. :";
	cin >> inputPw;

	// 파일 읽기
	ifstream inFile("member.txt");

	if (!inFile) {
		cout << "파일을 열 수 없습니다." << endl;
		return 0;
	}

	string line;
	bool check = false;

	while (getline(inFile, line)) {
		// 구분자 위치 찾기
		int spacePos = line.find(' ');

		// 이름 확인
		string name = line.substr(0, spacePos);
		// 비밀번호 확인
		string pw = line.substr(spacePos + 1);

		// 입력한 이름과 비밀번호가 일치하는지 확인
		if (inputName == name && inputPw == pw) {
			check = true;
			break;
		}
	}

	// 파일 닫기
	inFile.close();

	// 로그인 성공 여부 확인
	if (check) {
		cout << "로그인 성공" << endl;
	}
	else {
		cout << "로그인 실패" << endl;
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

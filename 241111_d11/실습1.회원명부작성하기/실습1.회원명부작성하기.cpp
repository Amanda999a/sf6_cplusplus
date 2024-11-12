// 실습1.회원명부작성하기.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {

	ofstream outFile("member.txt");

	if (!outFile) {
		cout << "파일을 열 수 없습니다." << endl;
		return 1;
	}

	for (int i = 0; i < 3; i++) {
		string name, pw;
		cout << i << "번째 회원 " << endl;
		cin >> name >> pw;
		outFile << name << " " << pw << endl;
	}

	outFile.close();

	ifstream inFile("member.txt");

	if (!inFile) {
		cout << "파일을 열 수 없습니다." << endl;
		return 1;
	}

	cout << "------- 회원 명부 파일 읽기 ------- " << endl;
	string line;
	while (getline(inFile, line)) {
		cout << line << endl;
	}

	inFile.close();

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

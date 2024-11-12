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

		// 전화번호 입력
		string phone;
		cout << "전화번호를 입력해주세요 : ";
		cin >> phone;

		fstream telFile("member_tel.txt", ios::in | ios::out);

		if (!telFile) {
			cout << "파일을 열 수 없습니다." << endl;
			return 0;
		}

		bool check_phone = false;
		string tel_line;
		while (getline(telFile, tel_line)) {
			long pos = telFile.tellg();// 현재 위치
			int spacePos_tel = tel_line.find(' ');

			// 이름 확인
			string name_tel = tel_line.substr(0, spacePos_tel);
			if (name_tel == inputName) {
				check_phone = true;
				//그 라인의 맨 앞으로 커서 이동
				telFile.seekp(pos - tel_line.length() - 1);
				telFile << inputName << " " << phone << endl;
				break;
			}
		}
		// 사용자가 존재하지 않으면 파일 끝에 추가
		if (!check_phone) {
			telFile.clear(); // EOF 플래그 지우기
			telFile.seekp(0, ios::end); // 파일 끝으로 커서 이동
			telFile << inputName << " " << phone << endl;
		}

		telFile.close(); // 파일 닫기
		cout << "전화번호가 저장되었습니다." << endl;
	}
	else {
		cout << "로그인 실패" << endl;
	}

	return 0;
}
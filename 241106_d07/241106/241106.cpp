// 241106.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

bool isOdd(int value) {
	cout << value << endl;
	//짝수가 참이라 삭제됨
	return !(value % 2); 
}

int main()
{
	list<int> numbers = { 3, 7, 5, 1 };
	list<int> numbers2 = { 2, 4, 6, 8 };
	//요소 2 모두 삭제
	//numbers.remove(2);

	//참값을 삭제
	//numbers.remove_if(isOdd);//참을 지운거 결과가 홀수만 도출됨

	//splice는 정렬없이 붙이기
	//numbers.splice(++numbers.begin(), numbers2);// 맨 앞부분에 두개가 붙는다

	// 병합은 정렬까지해주지만 각 리스트가 미리 정렬되어야 병합할때 다른 리스트와 병합가능
	numbers.sort();
	numbers2.sort();
	//numbers.merge(numbers2);

	for (int num : numbers) {
		cout << num << ", ";
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

#include "user.h"
using namespace std;

// main 구문
int main() {
	User* user; // 객체 생성
	int input; // 입력을 저장받을 변수
	cout << "1은 마법사, 2는 전사입니다." << endl;
	while(1) {
		cout << "선택: ";
		cin >> input;
		if (input == 1) {
			user = new Magician();
			break;
		}
		else if (input == 2) {
			user = new Warrior();
			break;
		}
		else {
			cout << "1 or 2 중 입력하세요." << endl;
			continue;
		} 
	}
	user -> File_Read(); // 지도 생성
    // 처음 시작 시 지도 보여주기
    user -> DisplayMap();
	// 게임 시작 
	while(1) {
		if (user -> Instruction(*user)) {
			break;
		}
	}
	return 0;
}
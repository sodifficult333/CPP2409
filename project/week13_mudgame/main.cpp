#include "user.h"
using namespace std;

// main 구문
int main() {
	// 두 객체 생성
	int input;
	User* user;
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
    // 처음 시작 시 지도 보여주기
    user -> DisplayMap();
	// 게임 시작 
	while(1) {
		if (user -> Instruction(*user)) {
			if(user -> GetHP() > 0) // 체력이 0보다 많을 때 반복문 종료시
				cout << "< 승리! >" << endl; // 승리 조건 만족
			else // 체력이 0보다 적을 때 반복문 종료시
				cout << "사망!" << endl; // 패배 조건 만족
			break;
		}
	}
	return 0;
}
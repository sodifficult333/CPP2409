#include "user.h"
using namespace std;

// main 구문
int main() {
	// 두 객체 생성
	Warrior warrior;
	Magician magician;

    // 처음 시작 시 지도 보여주기
    magician.DisplayMap(warrior); // 첫 차례는 마법사 차례

	// 게임 시작 
	while (1) { // 사용자에게 계속 입력받기 위해 무한 루프
		cout << " [마법사 차례] : ";
		if (magician.Instruction(magician, warrior)) { // current_Player : Magician / OtherPlayer : Warrior
			if(magician.GetHP() > 0) // 체력이 0보다 많을 때 반복문 종료시
				cout << "< 마법사 승리! >" << endl; // 승리 조건 만족
			else // 체력이 0보다 적을 때 반복문 종료시
				cout << "마법사 사망!" << endl; // 패배 조건 만족
			break;
		}
		cout << " [전사 차례] : ";
		if (warrior.Instruction(warrior, magician)) { // current_Player : Warrior / OtherPlayer : Magician
			if(magician.GetHP() > 0) // 체력이 0보다 많을 때 반복문 종료시
				cout << "< 전사 승리! >" << endl; // 승리 조건 만족
			else // 체력이 0보다 적을 때 반복문 종료시
				cout << "전사 사망!" << endl; // 패배 조건 만족
			break;
		}
	}
	return 0;
}
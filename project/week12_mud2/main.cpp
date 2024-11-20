#include "user.h"
using namespace std;

// main 구문
int main() {
	// 두 객체 생성
	Warrior warrior;
	Magician magician;

    // 처음 시작 시 지도 보여주기
    magician.displayMap();

	// 게임 시작 
	while (1) { // 사용자에게 계속 입력받기 위해 무한 루프
		cout << "마법사 차례  ";
		if (magician.instruction(magician)) {
			break;
		}
		cout << "전사 차례  ";
		if (warrior.instruction(warrior)) {
			break;
		}
	}
	return 0;
}
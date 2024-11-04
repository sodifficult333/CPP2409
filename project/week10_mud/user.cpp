#include "user.h"

/* 함수 정의 */
// Print 함수 : 각 상황에 맞는 메세지 출력 + 남은 HP를 반환
int User::print() {
	DecreaseHP(1); // 움직일 때마다 HP 1 감소
	switch(map[user_y][user_x]) { // col, row 순서
		case 0: // 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
			cout << "아무것도 없었습니다." << endl;
			break;
		case 1:
			cout << "아이템을 발견했습니다." << endl;
			break;
		case 2:
			cout << "적과 조우했습니다." << "  " << "체력이 '2'감소합니다." << endl;
			cout << "현재 HP: " << user_hp;
			DecreaseHP(2); // 체력 2 감소
			cout << " -> " << user_hp << endl;
			break;
		case 3:
			cout << "포션을 발견했습니다." << "  " << "체력을 '2'회복합니다." << endl;
			cout << "현재 HP: " << user_hp;
			IncreaseHP(2); // 체력 2 증가
			cout << " -> " << user_hp << endl;
			break;
	}
	return GetHP(); // 남은 체력 반환
}

// HP가 0이 되면 종료를 출력하는 함수
bool User::CheckUser(User user) {
	bool b = true;
	if (user_hp <= 0) {
		cout << "실패";
		b = false;
	}
	return b;
}

// 지도와 사용자 위치 출력하는 함수
void User::displayMap() {
	for (int i = 0; i < mapY; i++) {
		for (int j = 0; j < mapX; j++) {
			if (i == user_y && j == user_x) {
				cout << " USER |"; // 양 옆 1칸 공백
			}
			else {
				int posState = map[i][j];
				switch (posState) {
				case 0:
					cout << "      |"; // 6칸 공백
					break;
				case 1:
					cout << "아이템|";
					break;
				case 2:
					cout << "  적  |"; // 양 옆 2칸 공백
					break;
				case 3:
					cout << " 포션 |"; // 양 옆 1칸 공백
					break;
				case 4:
					cout << "목적지|";
					break;
				}
			}
		}
		cout << endl;
		cout << " -------------------------------- " << endl;
	}
}

// 이동하려는 곳이 유효한 좌표인지 체크하는 함수
bool User::checkXY(int user_x, int user_y) {
	bool checkFlag = false;
	if (user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY) {
		checkFlag = true;
	}
	else {
		cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
	}
	return checkFlag;
}

// 유저의 위치가 목적지인지 체크하는 함수
bool User::checkGoal() {
	// 목적지 도착하면
	if (map[user_y][user_x] == 4) {
		return true;
	}
	return false;
}

// HP가 증가하는 함수
void User::DecreaseHP(int dec_hp) {
    user_hp = user_hp - dec_hp;
}

// HP가 감소하는 함수
void User::IncreaseHP(int inc_hp) {
    user_hp = user_hp + inc_hp;
}

// HP를 반환하는 함수
int User::GetHP() {
    return user_hp;
}

// hp = 20으로 설정하며 생성하는 생성자
User::User() : user_hp(20) {}
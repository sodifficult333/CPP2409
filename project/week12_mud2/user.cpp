#include "user.h"

/* 함수 정의 */
// Print 함수 : 각 상황에 맞는 메세지 출력 + 남은 HP를 반환
int User::Print() {
	DecreaseHP(1); // 움직일 때마다 HP 1 감소
	switch(map[user_y][user_x]) { // col, row 순서
		case 0: // 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
			cout << "아무것도 없었습니다." << endl << endl;
			break;
		case 1:
			ItemCnt(); // 아이템 발견하면 1개씩 증가
			cout << "아이템을 획득했습니다. 현재 획득한 아이템 개수: " << user_item << endl << endl;
			break;
		case 2:
			cout << "적과 조우했습니다." << "  " << "체력이 '2'감소합니다." << endl;
			cout << "현재 HP: " << user_hp;
			DecreaseHP(2); // 체력 2 감소
			cout << " -> " << user_hp << endl << endl;
			break;
		case 3:
			cout << "포션을 발견했습니다." << "  " << "체력을 '2'회복합니다." << endl;
			cout << "현재 HP: " << user_hp;
			IncreaseHP(2); // 체력 2 증가
			cout << " -> " << user_hp << endl << endl;
			break;
	}
	return GetHP(); // 남은 체력 반환
}

// HP가 0이 되면 종료를 출력하는 함수
bool User::CheckUser() {
	bool b = true;
	if (user_hp <= 0) {
		cout << "[실패] 사유: ";
		b = false;
	}
	return b;
}

// 지도와 사용자 위치 출력하는 함수
void User::DisplayMap(User& other_user) {
	for (int i = 0; i < MAPY; i++) {
		for (int j = 0; j < MAPX; j++) {
			if (i == user_y && j == user_x && i == other_user.user_y && j == other_user.user_x) {
				cout << " W  M |"; // 두 유저가 같이 있을 경우
			}
			else if (i == user_y && j == user_x) {
				cout << "   M  |"; // 마법사일 경우
			}
			else if(i == other_user.user_y && j == other_user.user_x) {
				cout << "   W  |"; // 전사일 경우
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
bool User::CheckXY(int user_x, int user_y) {
	bool checkFlag = false;
	if (user_x >= 0 && user_x < MAPX && user_y >= 0 && user_y < MAPY) {
		checkFlag = true;
	}
	else {
		cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
	}
	return checkFlag;
}

// 유저의 위치가 목적지인지 체크하는 함수
bool User::CheckGoal() {
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

// hp = 20, item = 0으로 설정하며 생성하는 생성자
User::User() : user_hp(20), user_item(0) {}

// 아이템 먹은 횟수를 저장하는 변수
int User::ItemCnt() {
	user_item++;
	return user_item;
}

// 각 클래스마다 doAttack함수 구현
void User::DoAttack() {
	cout << "공격합니다." << endl;
}
void Magician::DoAttack() { // 재정의
	cout << "마법 사용" << endl;
}
void Warrior::DoAttack() { // 재정의
	cout << "베기 사용" << endl;
}

// 반복되는 코드를 함수화
bool User::Instruction(User& user, User& other_user) {
	// 사용자의 입력을 저장할 변수
	string user_input = "";
	cout << "[현재 HP: " << user.GetHP() << "]" << endl;
	cout << "명령어를 입력하세요 [상(w), 하(s), 좌(a), 우(d), 지도(map), 종료(exit), 정보(infor)]: ";
	cin >> user_input;

	if (user_input == "w") {
		// 위로 한 칸 올라가기
		if (user.CheckXY(user.user_x, user.user_y - 1)) { // 미리 움직였을 때 map 범위 안에 존재할 경우
			user.user_y -= 1; // 위로 올라가기
			cout << "위로 한 칸 올라갑니다." << endl; // 안내문 출력
			user.DisplayMap(other_user); // 지도 보여주기
			user.Print(); // 목적지 별 메세지 출력 + 체력 감소
		}
	}
	else if (user_input == "s") {
		// TODO: 아래로 한 칸 내려가기
		if (user.CheckXY(user.user_x, user.user_y + 1)) { // 미리 움직였을 때 map 범위 안에 존재할 경우
			user.user_y += 1; // 아래로 내려가기
			cout << "아래로 한 칸 내려갑니다." << endl; // 안내문 출력
			user.DisplayMap(other_user); // 지도 보여주기
			user.Print(); // 목적지 별 메세지 출력 + 체력 감소
		}
	}
	else if (user_input == "a") {
		// TODO: 왼쪽으로 이동하기
		if (user.CheckXY(user.user_x - 1, user.user_y)) { // 미리 움직였을 때 map 범위 안에 존재할 경우
			user.user_x -= 1; // 왼쪽으로 이동하기
			cout << "왼쪽으로 이동합니다." << endl; // 안내문 출력
			user.DisplayMap(other_user); // 지도 보여주기
			user.Print(); // 목적지 별 메세지 출력 + 체력 감소
		}
	}
	else if (user_input == "d") {
		// TODO: 오른쪽으로 이동하기
		if (user.CheckXY(user.user_x + 1, user.user_y)) { // 미리 움직였을 때 map 범위 안에 존재할 경우
			user.user_x += 1; // 오른쪽으로 이동하기
			cout << "오른쪽으로 이동합니다." << endl; // 안내문 출력
			user.DisplayMap(other_user); // 지도 보여주기
			user.Print(); // 목적지 별 메세지 출력 + 체력 감소
		}
	}
	else if (user_input == "map") {
		// TODO: 지도 보여주기 함수 호출
		user.DisplayMap(other_user);
	}
	else if (user_input == "exit") {
		cout << "종료합니다.";
		return true;
	}
	// 출력 연산자 중복 정의 : infor 구현
	else if (user_input == "infor") { // 정보 입력시
		cout << user << endl; // 사용자 정보를 보여줌
	}
	else { // 주어진 단어가 아닐 시 안내문 출력
		cout << "잘못된 입력입니다." << endl;
	}
		// 목적지에 도달했는지 체크
	if (user.CheckGoal() == true) {
		cout << "목적지에 도착했습니다! 축하합니다!" << endl;
		cout << "게임을 종료합니다." << endl;
		return true;
	}
	// CheckUser(user) : HP가 0이 되면 false : 실패를 출력하고 종료
	if (user.CheckUser() == false) {return true;}

	return false; // false를 반환해 턴을 반복
}
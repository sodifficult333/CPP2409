#include <iostream>
#include <string>
using namespace std;

const int mapX = 5;
const int mapY = 5;

// 사용자 정의 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY);
void displayMap(int map[][mapX], int user_x, int user_y);
bool checkGoal(int map[][mapX], int user_x, int user_y);
int Print(int map[][mapX], int user_x, int user_y, int user_hp); // 각 상황에 맞는 메세지를 출력하고 남은 HP를 반환하는 함수
bool HP_Checker(int user_hp); // HP가 0이 되면 종료메세지를 출력하는 함수

// 메인  함수
int main() {
	// 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
	int map[mapY][mapX] = { {0, 1, 2, 0, 4},
					        {1, 0, 0, 2, 0},
					        {0, 0, 0, 0, 0},
					        {0, 2, 3, 0, 0},
					        {3, 0, 0, 0, 2} };


	// 유저의 위치를 저장할 변수
	int user_x = 0; // 가로 번호
	int user_y = 0; // 세로 번호

	// 유저의 체력을 저장할 변수 : 20으로 시작
	int user_hp = 20;
    // 처음 시작 시 지도 보여주기
    displayMap(map, user_x, user_y);

	// 게임 시작 
	while (1) { // 사용자에게 계속 입력받기 위해 무한 루프

		// 사용자의 입력을 저장할 변수
		string user_input = "";
		cout << "현재 HP: " << user_hp << "  ";
		cout << "영어로 명령어를 입력하세요 [상(w), 하(s), 좌(a), 우(d), 지도(map), 종료(exit)]: ";
		cin >> user_input;

		if (user_input == "w") {
			// 위로 한 칸 올라가기
			if (checkXY(user_x, mapX, user_y - 1, mapY)) { // 미리 움직였을 때 map 범위 안에 존재할 경우
				user_y -= 1;
				cout << "위로 한 칸 올라갑니다." << endl;
				displayMap(map, user_x, user_y);
				user_hp = Print(map, user_x, user_y, user_hp); // 목적지 별 메세지 출력 + 체력 감소
			}
		}
		else if (user_input == "s") {
			// TODO: 아래로 한 칸 내려가기
			if (checkXY(user_x, mapX, user_y + 1, mapY)) { // 미리 움직였을 때 map 범위 안에 존재할 경우
				user_y += 1;
				cout << "아래로 한 칸 내려갑니다." << endl;
				displayMap(map, user_x, user_y);
				user_hp = Print(map, user_x, user_y, user_hp); // 목적지 별 메세지 출력 + 체력 감소
			}
		}
		else if (user_input == "a") {
			// TODO: 왼쪽으로 이동하기
			if (checkXY(user_x - 1, mapX, user_y, mapY)) { // 미리 움직였을 때 map 범위 안에 존재할 경우
				user_x -= 1;
				cout << "왼쪽으로 이동합니다." << endl;
				displayMap(map, user_x, user_y);
				user_hp = Print(map, user_x, user_y, user_hp); // 목적지 별 메세지 출력 + 체력 감소
			}
		}
		else if (user_input == "d") {
			// TODO: 오른쪽으로 이동하기
			if (checkXY(user_x + 1, mapX, user_y, mapY)) { // 미리 움직였을 때 map 범위 안에 존재할 경우
				user_x += 1;
				cout << "오른쪽으로 이동합니다." << endl;
				displayMap(map, user_x, user_y);
				user_hp = Print(map, user_x, user_y, user_hp); // 목적지 별 메세지 출력 + 체력 감소
			}
		}
		else if (user_input == "map") {
			// TODO: 지도 보여주기 함수 호출
			displayMap(map, user_x, user_y);
		}
		else if (user_input == "exit") {
			cout << "종료합니다.";
			break;
		}
		else {
			cout << "잘못된 입력입니다." << endl;
			continue;
		}

		// 목적지에 도달했는지 체크
		bool finish = checkGoal(map, user_x, user_y);
		if (finish == true) {
			cout << "목적지에 도착했습니다! 축하합니다!" << endl;
			cout << "게임을 종료합니다." << endl;
			break;
		}

		// HP_Checker : HP가 0이 되면 실패를 출력하고 종료
		if (HP_Checker(user_hp))
			break;
	}
	return 0;
}
// Print 함수 : 각 상황에 맞는 메세지 출력 + 남은 HP를 반환
int Print(int map[][mapX], int user_x, int user_y, int user_hp) {
	user_hp -= 1;
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
			user_hp -= 2; // 체력 2 감소
			cout << " -> " << user_hp << endl;
			break;
		case 3:
			cout << "포션을 발견했습니다." << "  " << "체력을 '2'회복합니다." << endl;
			cout << "현재 HP: " << user_hp;
			user_hp += 2; // 체력 2 증가
			cout << " -> " << user_hp << endl;
			break;
	}
	return user_hp; // 남은 체력 반환
}

// HP가 0이 되면 종료를 출력하는 함수
bool HP_Checker(int user_hp) {
	bool b = false;
	if (user_hp <= 0) {
		cout << "실패";
		b = true;
	}
	return b;
}

// 지도와 사용자 위치 출력하는 함수
void displayMap(int map[][mapX], int user_x, int user_y) {
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
bool checkXY(int user_x, int mapX, int user_y, int mapY) {
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
bool checkGoal(int map[][mapX], int user_x, int user_y) {
	// 목적지 도착하면
	if (map[user_y][user_x] == 4) {
		return true;
	}
	return false;
}

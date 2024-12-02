#include "user.h"

/* 함수 정의 */
User::User() : user_hp(20), user_item(0) {} // hp = 20, item = 0으로 설정하며 생성하는 생성자

// 매지션 클래스 오버라이드
int Magician::Print() { // Print 함수 : 각 상황에 맞는 메세지 출력 + 남은 HP를 반환
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
bool Magician::CheckUser() { // HP가 0이 되면 종료를 출력하는 함수
	bool b = true;
	if (user_hp <= 0) {
		cout << "[실패]";
		b = false;
	}
	return b;
}
void Magician::DisplayMap() { // 지도와 사용자 위치 출력하는 함수
	for (int i = 0; i < MAPY; i++) {
		for (int j = 0; j < MAPX; j++) {
			if (i == user_y && j == user_x) {
				cout << "   M  |"; // 마법사일 경우
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
bool Magician::CheckXY(int user_x, int user_y) { // 맵 유효성 체크하는 함수 : !!!TRY-CATCH!!!
	bool checkFlag = false;
	try {
		if (user_x < 0 || user_x >= MAPX || user_y < 0 || user_y >= MAPY) // 맵을 벗어난 경우
			throw out_of_range(""); // 범위 초과
		else {
			checkFlag = true; // 올바른 움직임
			return checkFlag;
		}
	}
	catch (out_of_range& e) { // 예외 처리
		cerr << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
		return checkFlag; // 잘못된 움직임
	}
}
bool Magician::CheckGoal() { // 목적지인지 체크하는 함수
	// 목적지 도착하면
	if (map[user_y][user_x] == 4) {
		cout << "[성공]";
		return true;
	}
	return false;
}
void Magician::DecreaseHP(int dec_hp) { // HP가 감소하는 함수
    user_hp = user_hp - dec_hp;
}
void Magician::IncreaseHP(int inc_hp) { // HP가 증가하는 함수
    user_hp = user_hp + inc_hp;
}
int Magician::GetHP() { // HP를 반환하는 함수
    return user_hp;
}
int Magician::ItemCnt() { // 아이템 먹은 횟수를 저장하는 변수
	user_item++;
	return user_item;
}
void Magician::DoAttack() { // 마법사 공격 재정의
	cout << "마법 사용" << endl;
}
bool Magician::Instruction(const User& user) { // 전반적 게임 진행 코드를 함수화
	// 사용자의 입력을 저장할 변수
	string user_input = "";
	cout << "[현재 HP: " << GetHP() << "]" << endl;
	cout << "명령어를 입력하세요 [상(w), 하(s), 좌(a), 우(d), 지도(map), 종료(exit), 정보(infor)]: ";
	cin >> user_input;

	if (user_input == "w") {
		// 위로 한 칸 올라가기
		if (CheckXY(user_x, user_y - 1)) { // 미리 움직였을 때 map 범위 안에 존재할 경우
			user_y -= 1; // 위로 올라가기
			cout << "위로 한 칸 올라갑니다." << endl; // 안내문 출력
			DisplayMap(); // 지도 보여주기
			Print(); // 목적지 별 메세지 출력 + 체력 감소
		}
	}
	else if (user_input == "s") {
		// TODO: 아래로 한 칸 내려가기
		if (CheckXY(user_x, user_y + 1)) { // 미리 움직였을 때 map 범위 안에 존재할 경우
			user_y += 1; // 아래로 내려가기
			cout << "아래로 한 칸 내려갑니다." << endl; // 안내문 출력
			DisplayMap(); // 지도 보여주기
			Print(); // 목적지 별 메세지 출력 + 체력 감소
		}
	}
	else if (user_input == "a") {
		// TODO: 왼쪽으로 이동하기
		if (CheckXY(user_x - 1, user_y)) { // 미리 움직였을 때 map 범위 안에 존재할 경우
			user_x -= 1; // 왼쪽으로 이동하기
			cout << "왼쪽으로 이동합니다." << endl; // 안내문 출력
			DisplayMap(); // 지도 보여주기
			Print(); // 목적지 별 메세지 출력 + 체력 감소
		}
	}
	else if (user_input == "d") {
		// TODO: 오른쪽으로 이동하기
		if (CheckXY(user_x + 1, user_y)) { // 미리 움직였을 때 map 범위 안에 존재할 경우
			user_x += 1; // 오른쪽으로 이동하기
			cout << "오른쪽으로 이동합니다." << endl; // 안내문 출력
			DisplayMap(); // 지도 보여주기
			Print(); // 목적지 별 메세지 출력 + 체력 감소
		}
	}
	else if (user_input == "map") {
		// TODO: 지도 보여주기 함수 호출
		DisplayMap();
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
	if (CheckGoal() == true) {
		cout << "목적지에 도착했습니다! 축하합니다!" << endl;
		cout << "게임을 종료합니다." << endl;
		return true;
	}
	// CheckUser(user) : HP가 0이 되면 false : 실패를 출력하고 종료
	if (CheckUser() == false) {return true;}

	return false; // false를 반환해 턴을 반복
}
void Magician::File_Read() { // 파일 읽기 재정의
	char c; // 파일을 하나씩 읽을 변수
	vector<int> row; // 행 벡터 생성 : 줄바꿈으로 행 구분
	ifstream file("map.txt");
	if (!file) { // 파일을 읽을 수 없는 경우
		cerr << "파일을 읽을 수 없습니다." << endl;
		exit(1); // 종료
	}
	else { // 파일을 읽을 수 있는 경우
		while (file.get(c)) { // 하나씩 문자를 가져와서
			row.push_back(c - '0'); // int형변환하여 push back
			if(c == '\n') { // 줄바꿈이 있을 시
				map.push_back(row); // map에 push back
				row.clear(); // row 벡터 초기화
			}
		}
	}
	file.close(); // 파일 닫기
}

// 워리어 클래스 오버라이드 : 위와 동일
int Warrior::Print() {
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
bool Warrior::CheckUser() {
	bool b = true;
	if (user_hp <= 0) {
		cout << "[실패]";
		b = false;
	}
	return b;
}
void Warrior::DisplayMap() {
	for (int i = 0; i < MAPY; i++) {
		for (int j = 0; j < MAPX; j++) {
			if (i == user_y && j == user_x) {
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
bool Warrior::CheckXY(int user_x, int user_y) {
	bool checkFlag = false;
	try {
		if (user_x < 0 || user_x >= MAPX || user_y < 0 || user_y >= MAPY) // 맵을 벗어난 경우
			throw out_of_range(""); // 범위 초과
		else {
			checkFlag = true; // 올바른 움직임
			return checkFlag;
		}
	}
	catch (out_of_range& e) { // 예외 처리
		cerr << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
		return checkFlag; // 잘못된 움직임
	}
}
bool Warrior::CheckGoal() {
	// 목적지 도착하면
	if (map[user_y][user_x] == 4) {
		cout << "[성공]";
		return true;
	}
	return false;
}
void Warrior::DecreaseHP(int dec_hp) {
    user_hp = user_hp - dec_hp;
}
void Warrior::IncreaseHP(int inc_hp) {
    user_hp = user_hp + inc_hp;
}
int Warrior::GetHP() {
    return user_hp;
}
int Warrior::ItemCnt() {
	user_item++;
	return user_item;
}
void Warrior::DoAttack() {
	cout << "베기 사용" << endl;
}
bool Warrior::Instruction(const User& user) {
	// 사용자의 입력을 저장할 변수
	string user_input = "";
	cout << "[현재 HP: " << GetHP() << "]" << endl;
	cout << "명령어를 입력하세요 [상(w), 하(s), 좌(a), 우(d), 지도(map), 종료(exit), 정보(infor)]: ";
	cin >> user_input;

	if (user_input == "w") {
		// 위로 한 칸 올라가기
		if (CheckXY(user_x, user_y - 1)) { // 미리 움직였을 때 map 범위 안에 존재할 경우
			user_y -= 1; // 위로 올라가기
			cout << "위로 한 칸 올라갑니다." << endl; // 안내문 출력
			DisplayMap(); // 지도 보여주기
			Print(); // 목적지 별 메세지 출력 + 체력 감소
		}
	}
	else if (user_input == "s") {
		// TODO: 아래로 한 칸 내려가기
		if (CheckXY(user_x, user_y + 1)) { // 미리 움직였을 때 map 범위 안에 존재할 경우
			user_y += 1; // 아래로 내려가기
			cout << "아래로 한 칸 내려갑니다." << endl; // 안내문 출력
			DisplayMap(); // 지도 보여주기
			Print(); // 목적지 별 메세지 출력 + 체력 감소
		}
	}
	else if (user_input == "a") {
		// TODO: 왼쪽으로 이동하기
		if (CheckXY(user_x - 1, user_y)) { // 미리 움직였을 때 map 범위 안에 존재할 경우
			user_x -= 1; // 왼쪽으로 이동하기
			cout << "왼쪽으로 이동합니다." << endl; // 안내문 출력
			DisplayMap(); // 지도 보여주기
			Print(); // 목적지 별 메세지 출력 + 체력 감소
		}
	}
	else if (user_input == "d") {
		// TODO: 오른쪽으로 이동하기
		if (CheckXY(user_x + 1, user_y)) { // 미리 움직였을 때 map 범위 안에 존재할 경우
			user_x += 1; // 오른쪽으로 이동하기
			cout << "오른쪽으로 이동합니다." << endl; // 안내문 출력
			DisplayMap(); // 지도 보여주기
			Print(); // 목적지 별 메세지 출력 + 체력 감소
		}
	}
	else if (user_input == "map") {
		// TODO: 지도 보여주기 함수 호출
		DisplayMap();
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
	if (CheckGoal() == true) {
		cout << "목적지에 도착했습니다! 축하합니다!" << endl;
		cout << "게임을 종료합니다." << endl;
		return true;
	}
	// CheckUser(user) : HP가 0이 되면 false : 실패를 출력하고 종료
	if (CheckUser() == false) {return true;}

	return false; // false를 반환해 턴을 반복
}
void Warrior::File_Read() {
	char c; // 파일을 하나씩 읽을 변수
	vector<int> row; // 행 벡터 생성 : 줄바꿈으로 행 구분
	ifstream file("map.txt");
	if (!file) { // 파일을 읽을 수 없는 경우
		cerr << "파일을 읽을 수 없습니다." << endl;
		exit(1); // 종료
	}
	else { // 파일을 읽을 수 있는 경우
		while (file.get(c)) { // 하나씩 문자를 가져와서
			row.push_back(c - '0'); // int형변환하여 push back
			if(c == '\n') { // 줄바꿈이 있을 시
				map.push_back(row); // map에 push back
				row.clear(); // row 벡터 초기화
			}
		}
	}
	file.close(); // 파일 닫기
}
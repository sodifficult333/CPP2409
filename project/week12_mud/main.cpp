#include "user.h"
using namespace std;

// main 구문
int main() {
	// 객체 생성 + 체력 생성
	User user;

    // 처음 시작 시 지도 보여주기
    user.displayMap();

	// 게임 시작 
	while (1) { // 사용자에게 계속 입력받기 위해 무한 루프

		// 사용자의 입력을 저장할 변수
		string user_input = "";
		cout << "[현재 HP: " << user.GetHP() << "]" << endl;
		cout << "영어로 명령어를 입력하세요 [상(w), 하(s), 좌(a), 우(d), 지도(map), 종료(exit), 정보(infor)]: ";
		cin >> user_input;

		if (user_input == "w") {
			// 위로 한 칸 올라가기
			if (user.checkXY(user.user_x, user.user_y - 1)) { // 미리 움직였을 때 map 범위 안에 존재할 경우
				user.user_y -= 1; // 위로 올라가기
				cout << "위로 한 칸 올라갑니다." << endl; // 안내문 출력
				user.displayMap(); // 지도 보여주기
				user.print(); // 목적지 별 메세지 출력 + 체력 감소
			}
		}
		else if (user_input == "s") {
			// TODO: 아래로 한 칸 내려가기
			if (user.checkXY(user.user_x, user.user_y + 1)) { // 미리 움직였을 때 map 범위 안에 존재할 경우
				user.user_y += 1; // 아래로 내려가기
				cout << "아래로 한 칸 내려갑니다." << endl; // 안내문 출력
				user.displayMap(); // 지도 보여주기
				user.print(); // 목적지 별 메세지 출력 + 체력 감소
			}
		}
		else if (user_input == "a") {
			// TODO: 왼쪽으로 이동하기
			if (user.checkXY(user.user_x - 1, user.user_y)) { // 미리 움직였을 때 map 범위 안에 존재할 경우
				user.user_x -= 1; // 왼쪽으로 이동하기
				cout << "왼쪽으로 이동합니다." << endl; // 안내문 출력
				user.displayMap(); // 지도 보여주기
				user.print(); // 목적지 별 메세지 출력 + 체력 감소
			}
		}
		else if (user_input == "d") {
			// TODO: 오른쪽으로 이동하기
			if (user.checkXY(user.user_x + 1, user.user_y)) { // 미리 움직였을 때 map 범위 안에 존재할 경우
				user.user_x += 1; // 오른쪽으로 이동하기
				cout << "오른쪽으로 이동합니다." << endl; // 안내문 출력
				user.displayMap(); // 지도 보여주기
				user.print(); // 목적지 별 메세지 출력 + 체력 감소
			}
		}
		else if (user_input == "map") {
			// TODO: 지도 보여주기 함수 호출
			user.displayMap();
		}
		else if (user_input == "exit") {
			cout << "종료합니다.";
			break;
		}
		// 출력 연산자 중복 정의 : infor 구현
		else if (user_input == "infor") { // 정보 입력시
			cout << user << endl; // 사용자 정보를 보여줌
		}
		else { // 주어진 단어가 아닐 시 안내문 출력
			cout << "잘못된 입력입니다." << endl;
			continue;
		}

		// 목적지에 도달했는지 체크
		if (user.checkGoal() == true) {
			cout << "목적지에 도착했습니다! 축하합니다!" << endl;
			cout << "게임을 종료합니다." << endl;
			break;
		}

		// CheckUser(user) : HP가 0이 되면 false : 실패를 출력하고 종료
		if (user.CheckUser() == false)
			break;
	}
	return 0;
}
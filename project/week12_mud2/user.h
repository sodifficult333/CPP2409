#include <iostream>
#include <vector>
using namespace std;

/* 전역 상수 */
const int MAPX = 5; // 지도 가로 크기
const int MAPY = 5; // 지도 세로 크기

/* 클래스 생성 */
class User {
private:
	// 유저의 체력을 저장할 변수
	int user_hp;
	// 아이템 개수를 저장하는 변수
	int user_item;

public:
	/* 지도 */
	// 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
	// 벡터로 지도 생성
	vector<vector <int>> map = { {0, 1, 2, 0, 4},
					        	 {1, 0, 0, 2, 0},
					        	 {0, 0, 0, 0, 0},
					        	 {0, 2, 3, 0, 0},
					        	 {3, 0, 0, 0, 2} };

	/* 유저의 위치를 저장할 변수 */
	int user_x = 0; // 가로 번호
	int user_y = 0;// 세로 번호

	/* 출력 연산자 중복 정의 */
	friend ostream& operator<<(ostream& os, const User& user) {
		os << "(현재 HP는 {" << user.user_hp << "} 이고, 먹은 아이템은 총 {" << user.user_item << "}개 입니다.)" << endl;
		return os;
	}

	/* 멤버 함수 설명 */
	bool CheckXY(int user_x, int user_y); // x, y좌표값이 유효한지 확인하는 함수
	void DisplayMap(User& other_user); // 지도를 보여주는 함수
	bool CheckGoal(); // 목적지에 들어왔는지 확인하는 함수
	int Print(); // 각 상황에 맞는 메세지를 출력하고 남은 HP를 반환하는 함수
	bool CheckUser(); // HP가 0이 되면 false, 그렇지 않으면 true 반환
	void DecreaseHP(int dec_hp); // HP가 감소하는 멤버함수
	void IncreaseHP(int inc_hp); // HP가 증가하는 멤버함수
	int GetHP(); // HP를 반환하는 멤버함수
	User(); // hp = 20으로 설정하며 생성하는 생성자
	int ItemCnt(); // 아이템 먹은 횟수를 저장하는 변수
	void DoAttack(); // 공격출력 함수
	bool Instruction(User& user, User& other_user); // 각 명령어에 대한 처리를 담은 함수
};

class Magician:public User{ // User Class를 상속받은 Magician Class
public:
	Magician():User(){}; // User()의 기본설정으로 게임 시작 : 체력, 아이템, 위치
	void DoAttack(); // 공격출력 재정의
};


class Warrior:public User{ // User Class를 상속받은 Warrior Class
public:
	Warrior():User(){}; // User()의 기본설정으로 게임 시작 : 체력, 아이템, 위치
	void DoAttack(); // 공격출력 재정의
};

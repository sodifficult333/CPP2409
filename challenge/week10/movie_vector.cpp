# include <iostream>
# include <vector>
# include <string>
using namespace std;

class movie { // 클래스 생성
public:
    string t; // 영화 이름을 저장할 변수
    string s; // 영화 평점을 저장할 변수
    movie() {t = ""; s = "";} // 함수 정의 + 각 변수 초기화
    movie(string t, string s) { // 매개변수로 입력받기
        this -> t = t; // 매개변수로 받은 값을 변수에 저장
        this -> s = s; // 매개변수로 받은 값을 변수에 저장
    }
    void Print() { // 출력 함수
        cout << t << ": " << s << endl; // 영화 이름 : 영화 평점 출력
    }
};

int main() {
    vector<movie> array; // 동적 벡터 생성 : array
    array.push_back(movie("titinic", "9.9")); // 값 소매넣기
    array.push_back(movie("gone with the wind", "9.6"));
    array.push_back(movie("terminator", "9.7"));

    for(auto& e: array) { // 벡터 인덱스값을 받아 반복
        e.Print(); // 출력
    }
    return 0;
}
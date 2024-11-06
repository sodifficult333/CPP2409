#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> scores; // 동적 벡터 생성 : scores
    int a = 0, sum = 0, count = 0, average = 0; // 입력받을 점수, 합계, 카운트, 평균을 초기화

    while(1) { // '-1' 입력하면 종료되는 반복문
        cout << "성적을 입력하시오(종료는 -1) : "; // 안내문 출력
        cin >> a; // 입력받은 값을 변수에 저장
        if (a == -1) // '-1'을 입력하면
            break; // 종료
        
        // 종료값은 넣으면 안되기 때문에 if문 밑에 생성
        scores.push_back(a); // 값 소매넣기
        count ++; // 한 번 반복문 실행되면 카운트 1씩 증가 (총 반복수 파악)
    }

    if (!scores.empty()) { // 벡터에 값이 들어있을 때
        for (auto& e:scores) // 벡터 전체 인덱스 값 주기
            sum += e; // 벡터 전체 값을 합산하여 변수에 저장

        average = sum / count; // 평균 계산 : 합산 값 / 입력 수
        cout << "성적 평균 = " << average << endl; // 평균 출력
    }
    else // 벡터에 값이 없을 때
        cout << "입력된 값이 없습니다." << endl;

    return 0;
}
#include <iostream>
#include <time.h>
using namespace std;

int main() {
    srand(time(NULL));

    int answer = rand() %100; //정답
    int tries = 0; //시도 횟수 저장 변수

    int guess; //사용자 입력 저장 변수

    //while / do-while 
    while(true) {
        cout << "정답을 추측하여 보시오:";
        cin >> guess;

        if (guess < answer) { //사용자 입력이 정답보다 작음
            cout << "제시한 정수가 낮습니다." << endl;
            tries ++;
            continue;
        }
        else if (guess > answer) { //사용자 입력이 정답보다 큼
            cout << "제시한 정수가 높습니다." << endl;
            tries ++;
            continue;
        }
        else {
            break;
        }
    }
    cout << "축하합니다. 시도 횟수=" << tries << endl;
    return 0;
}
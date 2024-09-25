#include <iostream>
#include <time.h>
using namespace std;

int main() {
    int i;
    int ans;
    cout << "산수 문제를 자동으로 출제합니다. " << endl;

    while(true) {
        int firstNum = rand()%100;
        int seconNum = rand()%100;

        i = firstNum + seconNum; //정답

        //문제 출력 > 답 입력 받기 > 평가
        cout << firstNum << " + " << seconNum << " = " << " ? " << endl; //문제 출력

        cin >> ans; //답 입력 받기

        if (i == ans) {
            cout << firstNum << "+" << seconNum << "=" << ans << endl;
            cout << "맞았습니다." << endl;
            break;
        }
        else {
            cout << firstNum << "+" << seconNum << "=" << ans << endl;
            cout << "틀렸습니다." << endl;
            continue;
        }
    }
    return 0;
}
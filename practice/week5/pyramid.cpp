#include <iostream>
using namespace std;

int main () {
    int floor;
    cout << "몇 층을 쌓겠습니까? (5 ~ 100):";
    cin >> floor;
    for (int i = 1; i <= floor; i++) { //1~n까지 n회 반복
        for (int j = 0; j < floor - i; j++) { //'-1'을 없애기 위해 j값 변경
            cout << " ";
        }
        for (int k = 0; k < 1 + ((i-1)*2); k++) { //첫 반복문 변경에 따라 수정
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}
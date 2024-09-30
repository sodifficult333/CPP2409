#include <iostream>
using namespace std;

int main() {
    int floor;
    cout << "몇 층을 쌓겠습니까? (5 ~ 100):";
    cin >> floor;
    for (int i = floor; i > 0; i--) {
        for (int j = 0; j < floor -i; j++) { 
            cout << "S";
        }
        for (int k = 1; k < i*2; k++) { //'-1'을 빼기 위해 k값 변경
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}
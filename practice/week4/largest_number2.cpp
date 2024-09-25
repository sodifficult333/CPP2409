#include <iostream>
using namespace std;

int main() {
    int a, b, c, largest;

    cout << "3개의 정수를 입력하시오: ";
    cin >> a >> b >> c;

    largest = a; //가장 큰 수를 a로 지정

    while (b >= largest) { //b가 a보다 크거나 같을 경우
        largest = b;
        while (c >= largest) //정수가 같을 경우를 대비
        largest = c;
        break;
    }

    cout << "가장 큰 정수는" << largest << endl;
    return 0;
}

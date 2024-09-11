#include <iostream>

using namespace std;

int main()
{
    int a = 0;
    cout << "가지고 있는 돈을 입력하시오." << endl;
    cin >> a; // 입력받은 돈
    cout << "현재 가지고 있는 돈:" << a << endl;

    int b = 0;
    cout << "캔디의 가격을 입력하시오." << endl;
    cin >> b; // 입력받은 캔디의 가격
    cout << "캔디의 가격 : " << b << endl;

    int c = 0;
    c = a/b;
    cout << "최대로 살 수 있는 캔디 = " << c << endl;

    int d = a - (b * c);
    cout << "캔디 구입 후 남은 돈 = " << d << endl;
}
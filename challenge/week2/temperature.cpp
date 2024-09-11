#include <iostream>

using namespace std;

int main()
{
    int a = 0;
    cout << "화씨번호를 입력하시오." << endl;
    cin >> a;

    float b = 0;
    b = (5.0/9.0) * (a - 32);

    cout << "섭씨온도 = " << b << endl;
}
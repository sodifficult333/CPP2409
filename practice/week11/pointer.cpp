#include <iostream>
using namespace std;

int main()
{
    int number = 10;
    int *p = &number; // number의 주소를 계산하여 p에 저장

    cout << *p << endl; // p가 가리키는 공간에 저장된 값을 출력
    return 0;
}
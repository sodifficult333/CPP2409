#include <iostream>
using namespace std;

class Complex {
    public:
        double real, imag;
        Complex(double r = 0.0, double i = 0.0) {
            real = r;
            imag = i;
            cout << "생성자 호출";
            Print();
        }
        ~Complex() {
            cout << "소멸자 호출";
            Print();
        }
        void Print() {
            cout << real << "+" << imag << "i" << endl;
        }
};

// Add가 캐스팅되지 않음. 일반 함수로 작용
Complex Add(Complex const a, Complex const b) { // 복사 생성자 자동 호출
    Complex test; // 사용할 클래스 생성
    test.real = a.real + b.real; 
    test.imag = a.imag + b.imag;
    return test; // 반환타입이 Class
}
// a,b 생성한 것을 소멸하면서 소멸자 호출이 3번 일어남 : a, b, test
// 포인터를 사용하면 소멸자 1번만 호출 : test
// 값을 변경하지 못하도록 const를 사용할 수 있음

int main() {
    Complex c1{1,2}, c2{3,4};
    Complex t;
    t = Add(c1, c2);
    t.Print();
    return 0;
}
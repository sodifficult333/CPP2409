#include <iostream>
using namespace std;

class A {
    public:
        friend class B; // A와 B는 친구
        A(string s ="") : secret{s} {}
    private:
        string secret; // B도 private에 접근가능
};

class B {
    public:
        B() {}
        void print(A obj) {
            cout << obj.secret << endl;
        }
};

int main() {
    A a("이것은 기밀 정보입니다.");
    B b;
    b.print(a);
    return 0;
}
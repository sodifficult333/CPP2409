#include <iostream>
using namespace std;

class Person {
    string name; // 기본 private
protected:
    string address;
    friend class Student; // 친구만들기 : 접근 권한을 준다.
};

class Student : Person {
public:
    void SetAddress(string add) {
        address = add;
    }
    string GetAddress() {
        return address;
    }
    string GetName() { // 이름 반환 함수 추가
        return name;
    }
    void SetName(string name) {this -> name = name;}
};

int main() {
    Student obj;
    obj.SetName("미수");
    obj.SetAddress("서울시 종로구 1번지");
    cout << obj.GetName() << endl; // 이름 반환
    cout << obj.GetAddress() << endl;
    return 0;
}
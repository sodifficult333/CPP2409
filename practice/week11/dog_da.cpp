#include <iostream>
using namespace std;

class Dog {
    private:
        int *pWeight;
        int *pAge;
    public:
        Dog() {
            pAge = new int(1); // 기본값 1
            pWeight = new int(10); // 기본값 10
        }
        ~Dog() {
            delete pAge;
            delete pWeight;
        }
        int GetAge() {return *pAge;}
        void SetAge(int age) {*pAge = age;}
        int GetWeight() {return *pWeight;}
        void SetWeight(int weight) {*pWeight = weight;}
};

int main() {
    Dog *pDog = new Dog;
    cout << "강아지 나이: " << pDog -> GetAge() << endl; // 포인터가 가리키는 객체의 멤버에 접근할 때 (->) 사용

    pDog -> SetAge(5); // 강아지 나이를 5로 변경
    cout << "강아지 나이: " << pDog -> GetAge() << endl;

    delete pDog; // 동적 메모리 반납
    return 0;
}
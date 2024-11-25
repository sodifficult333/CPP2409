#include <iostream>
using namespace std;

class RemoteControl {
public:
    virtual void TurnON() = 0;
    virtual void TurnOFF() = 0;
};

class Television:public RemoteControl {
    void TurnON() override { // 오버라이드 키워드 : 가상 함수를 재정의
        cout << "TV를 켭니다." << endl;
    }
    void TurnOFF() override {
        cout << "TV를 끕니다." << endl;
    }
};

class Refrigerator:public RemoteControl {
    void TurnON() override { // 가상 함수를 재정의
        cout << "냉장고를 켭니다." << endl;
    }
    void TurnOFF() override {
        cout << "냉장고를 끕니다." << endl;
    }
};

int main() {
    RemoteControl* remoteTV = new Television();
    remoteTV -> TurnON();
    remoteTV -> TurnOFF();

    RemoteControl* remoteRefrigerator = new Refrigerator();
    remoteRefrigerator -> TurnON();
    remoteRefrigerator -> TurnOFF();

    delete remoteTV, remoteRefrigerator;
    return 0;
}
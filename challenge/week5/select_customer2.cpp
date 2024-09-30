#include <iostream>
#include <string>
using namespace std;

int main() {
    const int maxPeople = 5;
    string names[maxPeople];
    int ages[maxPeople];

    cout << maxPeople << "명의 회원 정보를 입력해주세요." << endl;

    for (int i = 0; i < maxPeople; i++) {
        cout << "사람 " << i+1 << "의 이름: ";
        cin >> names[i];
        cout << "사람 " << i+1 << "의 나이: ";
        cin >> ages[i];
    }

//받은 정보를 가지고 Index 파악

    int max = ages[0]; //최대값 비교용
    int min = ages[0];

    int max_Index = 0; //Index 파악용
    int min_Index = 0;

    for(int k = 0; k < 5; k++) { //최대 나이 Index 파악
        if(max <= ages[k]) {
            max = ages[k];
            max_Index = k;
        }
    }
    for(int j = 0; j < 5; j++) { //최소 나이 Index 파악
        if(ages[j] <= min) {
            min = ages[j];
            min_Index = j;
        }
    }

//선택권 제시
    int choice;

    cout << "1. 가장 나이가 많은 사람 출력" << endl;
    cout << "2. 가장 나이가 적은 사람 출력" << endl;
    cout << "3. 종료" << endl;

    cin >> choice;

    while(choice == 1) { //1번 선택
        cout << "가장 나이가 많은 사람: " << names[max_Index] << endl;
        break;
    }

    while(choice == 2) { //2번 선택
        cout << "가장 나이가 적은 사람: " << names[min_Index] << endl;
        break;
    }

    while(choice == 3) { //3번 선택
        cout << "종료" << endl;
        break;
    }

    while(choice<1) { //1~3번이 아닐때
        cout << "잘못 입력하셨습니다." << endl;
        break;
    }
    
    while(3<choice) {
        cout << "잘못 입력하셨습니다." << endl;
        break;
    }
}
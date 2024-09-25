#include <iostream>
using namespace std;

int main() {
    int vowel = 0;
    int consonant = 0;
    cout << "영문자 입력하고 ctrl+z를 치세요" << endl;

    char ch;

    //while + switch
    while(true) {
        cin >> ch;

        if (cin.fail()) { //'Ctrl + Z' 입력 시 루프 종료
            break;
        }

        if(ch < 'a' || ch > 'z') { //잘못 입력 받았을 시
            cout << "잘못 입력했습니다." << endl;
            continue;
        }

        switch (ch) { //옳게 입력 받았을 시
            case 'a' : //모음 +1
                vowel ++;
                break;
            case 'e' : 
                vowel ++;
                break;
            case 'i' : 
                vowel ++;
                break;
            case 'o' : 
                vowel ++;
                break;
            case 'u' : 
                vowel ++;
                break;
            default : //자음 +1
                consonant ++;
                break;
        }
    }

    cout << "모음: " << vowel << endl;
    cout << "자음: " << consonant << endl;
    return 0;

}
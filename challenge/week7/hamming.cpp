#include <iostream>
#include <string>
using namespace std;

string toLowerStr(string str) { //소문자로 바꿔주는 함수
    for (char &c : str) {
        c = tolower(c);
    }
    return str; //바꾼 문자열을 반환
}

string toUpperStr(string str) { //대문자로 바꿔주는 함수
    for (char &c : str) {
        c = toupper(c);
    }
    return str; //바꾼 문자열을 반환
}

int calcHammingDist(string s1, string s2) { //해밍거리를 계산하는 함수
    int count = 0;
    if(s1.length() != s2.length()) { //길이가 다를 때 오류를 출력
        cout << "오류 : 길이가 다름" << endl;
        return 0;
    }
    else {
        for(int i = 0; i < s1.length(); i++) { //길이가 같을 때 해밍거리를 계산
            if(s1[i] != s2[i])
            count += 1;
        }
    }
    return count; //count를 반환
}

int main() {
    string s1, s2;

    cout << "DNA1: ";
    cin >> s1;
    cout << "DNA2: ";
    cin >> s2;

    string a; //소문자로 바꾼 문자열을 저장할 스트링 변수
    string b; 
    a = toLowerStr(s1);
    b = toLowerStr(s2);

    cout << "해밍 거리는 " << calcHammingDist(a, b) << endl; //소문자로 바꾼 문자열을 비교해서 해밍거리 계산
    return 0;
}
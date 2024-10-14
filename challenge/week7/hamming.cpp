#include <iostream>
#include <string>
using namespace std;

string toLowerStr(string str) {
    for (int i = 0; i<str.length(); i++)
        tolower(str[0]);
    return str;
}

string toUpperStr(string str) {
    for (int i = 0; i<str.length(); i++)
    toupper(str[0]);
    return str;
}

int calcHammingDist(string s1, string s2) {
    int count = 0;
    if(s1.length() != s2.length()) {
        cout << "오류 : 길이가 다름" << endl;
        return 0;
    }
    else {
        for(int i = 0; i < s1.length(); i++) {
            if(s1[i] != s2[i])
            count += 1;
        }
    }
    return count;
}

int main() {
    string s1, s2;

    cout << "DNA1: ";
    cin >> s1;
    cout << "DNA2: ";
    cin >> s2;

    toLowerStr(s1);
    toUpperStr(s2);

    cout << "해밍 거리는 " << calcHammingDist(s1, s2) << endl;
    return 0;
}
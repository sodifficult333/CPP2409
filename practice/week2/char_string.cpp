#include <iostream>
#include <string>
using namespace std;

int main()
{
    char ch = '1'; //char ch = "1"; (X)
    string s1 = "Good";
    string s2 = "Morning";
    string s3 = s1 + " " + s2 + "!"; //문자열끼리만 가능
    cout << s3 << endl;
    return 0;
}
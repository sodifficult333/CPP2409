#include <iostream>
using namespace std;

int main() {
    const int ST = 5;
    int scores[ST];
    int sum = 0;
    int i, average;

    for (i = 0; i < ST; i++) {
        cout << "성적을 입력하시오: ";
        cin >> scores[i];
    }
    for (i = 0; i < ST; i++)
        sum += scores[i];

    average = sum / ST;
    cout << "성적 평균= " << average << endl;
    return 0;
}
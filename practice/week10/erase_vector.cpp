#include <vector>
#include <iostream>
using namespace std;

int main(void) {
    vector<int> v;
    for (int i = 0; i < 10; ++i) { // i = 0~9
        v.push_back(i); // i값 벡터에 추가
    }

    cout << "현지의 v = ";
    for (auto& e: v)
        cout << e << " ";
    cout << endl;

    v.erase(v.begin()+5); // 5번째 값을 erase(지운다).

    cout << "5번 인덱스를 제거한 후 v = ";
    for (auto& e:v)
        cout << e << " ";
    cout << endl;

    return 0;
}
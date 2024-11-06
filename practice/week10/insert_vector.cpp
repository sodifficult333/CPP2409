#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }

    cout << "현재의 v = ";
    for (auto& e:v)
        cout << e << " ";
    cout << endl;

    auto it = v.begin() + 5; // it에 5번 인덱스 위치 저장 
    v.insert(it, 100); // 5번 인덱스에 100 추가

    cout << "5번 인덱스에 값을 추가한 후 v = ";
    for (auto& e:v)
        cout << e << " ";
    cout << endl;

    return 0;
}
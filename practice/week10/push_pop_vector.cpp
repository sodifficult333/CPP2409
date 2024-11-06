#include <vector>
#include <iostream>
using namespace std;

int main(void) {
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i); // 벡터에 값 삽입
    }

    cout << "현재의 v = ";
    for(auto& e:v)
        cout << e << " ";
    cout << endl;

    cout << "삭제 요소 = ";
    while (!v.empty()) { // 벡터가 빌때까지 반복
        cout << v.back() << " "; // 벡터 맨 뒤 값을 출력
        v.pop_back(); // 맨 뒤의 값을 제거
    }
    cout << endl;
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
T add(T x, T y) {
    return x + y;
}

vector<int> add(vector<int>& vec1, vector<int>& vec2) {
    vector<int> result;
    result.reserve(vec1.size() + vec2.size()); // 벡터의 크기를 미리 예약

    // 첫 벡터의 모든 아이템을 결과 벡터에 추가
    for (const int& i : vec1) {
        result.push_back(i);
    }

    // 둘 벡터의 모든 아이템을 결과 벡터에 추가
    for (const int& i : vec2) {
        result.push_back(i);
    }
    return result;
}

int main() {
    int x = 100, y = 200;
    cout << add(x, y) << endl;

    vector<int> s1 = {1, 2, 3};
    vector<int> s2 = {4, 5, 6};
    vector<int> s3 = add(s1, s2);
    for (auto& i : s3) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
#include <iostream>
#include <memory>
using namespace std;

int main() {
    unique_ptr<int[]>buf(new int[10]); // 스마트 포인터 = 메모리 할당 후 자동으로 동적 메모리 삭제

    for(int i = 0; i < 10; i++) {
        buf[i] = i;
    }

    for(int i = 0; i < 10; i++) {
        cout << buf[i] << " ";
    }
    cout << endl;
    return 0;
}
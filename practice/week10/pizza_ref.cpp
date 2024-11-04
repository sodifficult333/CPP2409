#include <iostream>
using namespace std;

class Pizza {
    public:
        Pizza(int s) {size = s;}
        int size;
};

// &를 사용하지 않으면 객체 내용이 복사될 뿐 원본이 전달되지 않는다.
void MakeDouble(Pizza &p) {
    p.size *= 2;
}

int main() {
    Pizza pizza(10);
    MakeDouble(pizza);
    cout << pizza.size << "인치 피자" << endl;
    return 0;
}
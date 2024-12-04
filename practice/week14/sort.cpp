#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> data = { 5, 2, 4, 1, 3, 8, 9, 6, 7 };
    sort(data.begin(), data.end());
    for (int n : data) {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}
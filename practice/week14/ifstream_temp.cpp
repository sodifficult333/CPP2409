#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream file { "temp.txt" };
    if (!file) {
        cerr << "파일 오픈에 실패하였습니다." << endl;
        exit(1);
    }
    int time;
    double temperature;
    while (file >> time >> temperature) {
        cout << time << "시: 온도" << temperature << endl;
    }
    return 0;
}
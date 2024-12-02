#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream os{ "numbers.txt" }; // 출력 파일 스트림. 파일에 데이터를 쓴다.
    if (!os) {
        cerr << "파일 오픈에 실패하였습니다." << endl;
        exit(1);
    }
    for (int i = 0; i < 100; i++)
        os << i << " ";
    return 0;
}
// ofstream은 기본적으로 ios::out모드가 탑재.
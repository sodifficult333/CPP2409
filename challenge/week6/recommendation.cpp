#include <iostream>
using namespace std;

//전역변수
const int N_Users = 3;
const int N_Items = 3;
int userPreferences[N_Users][N_Items];

//함수 원형 선언
void initializePreferences(int preferences[N_Users][N_Items]);
void findRecommendedItems(const int preferences[N_Users][N_Items]);

//메인 함수
int main() {

    initializePreferences(userPreferences);
    findRecommendedItems(userPreferences);

    return 0;
}

// 사용자와 항목 간의 선호도를 입력 받아 2차원 배열 초기화
void initializePreferences(int preferences[N_Users][N_Items]) {
    for(int i=0; i < N_Users; ++i) {
        cout << "사용자 " << (i+1) << "의 선호도를 입력하세요 (";
        cout << N_Items << "개의 항목에 대해 ): ";
        for (int j=0; j < N_Items; ++j) {
            cin >> preferences[i][j];
        }
    }
}

// 사용자에 대한 추천 항목 찾기
void findRecommendedItems(const int preferences[N_Users][N_Items]) {
    for(int i=0; i < N_Users; ++i) {
        int maxPreferenceIndex = 0;
        for(int j=1; j < N_Items; ++j) {
            if (preferences[i][j] > preferences[i][maxPreferenceIndex]) {
                maxPreferenceIndex = j;
            }
        }
        cout << "사용자 " << (i + 1) << "에게 추천하는 항목: ";
        cout << (maxPreferenceIndex + 1) << std::endl;
    }
}
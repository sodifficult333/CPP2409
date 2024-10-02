#include <iostream>
using namespace std;

int main() {
    const int numCell = 3;
    char board[numCell][numCell]{}; //보드판
    int x, y;

//보드판 초기화
    for (x=0; x<numCell; x++) {
        for (y=0; y<numCell; y++) {
            board[x][y] = ' ';
        }
    }

//게임 코드
    int k = 0; //차례 변수
    char currentUser = 'X'; //돌 저장 변수

//차례 출력
    while(true) {
        switch(k%3) {
            case 0:
                cout << "첫번째 유저(X)의 차례입니다 -> ";
                currentUser = 'X';
                break;
            case 1:
                cout << "두번째 유저(O)의 차례입니다 -> ";
                currentUser = 'O';
                break;
            case 2:
                cout << "세번째 유저(V)의 차례입니다 -> ";
                currentUser = 'V';
                break;
        }

//좌표 유효성 체크
        cout << "(x,y) 좌표를 입력하세요: ";
        cin >> x >> y;

        if (x >= numCell || y >= numCell) {
            cout << x << ", " << y << ": ";
            cout << "x와 y 둘 중 하나가 칸을 벗어납니다." << endl;
            continue;
        }
        if (board[x][y] != ' ') {
            cout << x << ", " << y << ": 이미 돌이 차있습니다." << endl;
            continue;
        }

//입력받은 좌표에 돌 넣기
        board[x][y] = currentUser;

//보드판 출력
        for(int i = 0; i < numCell; i++) {
            cout << "---|---|---" << endl;
            for(int j = 0; j < numCell; j++) {
                cout << " " << board[i][j];
                if (j == numCell-1) {
                    break;
                }
                cout << " |";
            }
            cout << endl;
        }
        cout << "---|---|---" << endl;

//종료 조건 

//가로, 세로, 대각선이 같으면 종료
        int m = 0; //가로줄 or 세로줄 or 대각선 검사 변수
        bool exit = true; //true = 종료 / false = 진행
        
        for(int n = 0; n < numCell; n++) {
            if(board[n][m] == currentUser && board[n][m+1] == currentUser && board[n][m+2] == currentUser) { //가로가 같을 시 승리
                cout << currentUser << " 승리" << endl;
                return 0;
            }
        }
        for(int n = 0; n < numCell; n++) {
            if(board[m][n] == currentUser && board[m+1][n] == currentUser && board[m+2][n] == currentUser) { //세로가 같을 시 승리
                cout << currentUser << " 승리" << endl;
                return 0;
            }
        }
        if(board[m][m] == currentUser && board[m+1][m+1] == currentUser && board[m+2][m+2] == currentUser || board[m][m+2] == currentUser && board[m+1][m+1] == currentUser && board[m+2][m] == currentUser) { //대각이 같을 시 승리
            cout << currentUser << " 승리" << endl;
            return 0;
        }

//모든 칸이 찼으면 종료
        for(int n = 0; n < numCell; n++) { //공백 검사기
            for(int m = 0; m < numCell; m++) {
                if(board[n][m] == ' ') {
                    exit = false;
                    break;
                }
            }
            if (!exit) break;
        }

        if(exit) { //공백이 없으면 종료
            cout << "칸이 부족하여 종료";
            return 0;
        }

        k++;
    }
    return 0;
}


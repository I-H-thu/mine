#include <iostream>

#define LOOP(val,times) for(val=0;val<(times);val++)
using namespace std;

//グローバル変数置き場
int board[8][8];

void hyouzi () {
    int hyouzi_i,hyouzi_j;
    cout << "    1 2 3 4 5 6 7 8" <<endl;
    cout << "   +-+-+-+-+-+-+-+-+" <<endl;
    LOOP(hyouzi_i,8){
        cout << "  " << hyouzi_i+1 << "|";
        LOOP(hyouzi_j,8){
            switch(board[hyouzi_i][hyouzi_j]){
                case 0:
                    cout << " " << "|";
                    break;
                case 1:
                    cout << "0" << "|";
                    break;
                case 2:
                    cout << "@" << "|";
                    break;
            }
        }
        cout << "\n"
               <<"   +-+-+-+-+-+-+-+-+" <<endl;
    }
}


int main (){
    int i,j;
    //タイトル表示
    cout << "OTHELLO GAME" << endl;
    //盤面の初期化
    LOOP(i,8){
        LOOP(j,8){
            board[i][j] = 0;
        }
    }
    board[3][3] = board[4][4] = 1;
    board[3][4] = board[4][3] = 2;
    hyouzi ();
    return 0;
}

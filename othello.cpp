#include <iostream>

#define LOOP(val,times) for(val=0;val<(times);val++)
using namespace std;

//グローバル変数置き場
bool first = true;//先手の番か
bool player = true;//プレイヤーは先手か
int board[8][8];//盤面
char name[32];//プレイヤーの名前

void title (){//タイトル表示
    cout << "\n"
    << "    OOOOO TTTTT H   H EEEEE L     L     OOOOO   GGGGG   A   M   M EEEEE\n"
    << "    O   O   T   H   H E     L     L     O   O   G      A A  MM MM E    \n"  
    << "    O   O   T   HHHHH EEEEE L     L     O   O   G GGG A   A M M M EEEEE\n"  
    << "    O   O   T   H   H E     L     L     O   O   G   G AAAAA M   M E    \n"  
    << "    OOOOO   T   H   H EEEEE LLLLL LLLLL OOOOO   GGGGG A   A M   M EEEEE\n\n\n\n"
    << "    名前を入れてください(<32 words)" << endl;
    cin >> name;
    cout << "ようこそ" << name << "\n\n\n";    
}

void b_reset(){//盤面の初期化
    int b_i,b_j;
    LOOP(b_i,8){
        LOOP(b_j,8){
            board[b_i][b_j] = 0;
        }
    }
    board[3][3] = board[4][4] = 1;
    board[3][4] = board[4][3] = 2;
}


void hyouzi () {//盤面表示
    int hyouzi_i,hyouzi_j;
    cout << "    1 2 3 4 5 6 7 8" <<endl;
    cout << "   +-+-+-+-+-+-+-+-+" <<endl;
    LOOP(hyouzi_i,8){
        cout << "  " << hyouzi_i+1 << "|";
        LOOP(hyouzi_j,8){
            switch(board[hyouzi_i][hyouzi_j]){
                case 0:
                    cout << " " ;
                    break;
                case 1:
                    cout << "0" ;
                    break;
                case 2:
                    cout << "@" ;
                    break;
            }
            cout << "|";
        }
        cout << "\n"
               <<"   +-+-+-+-+-+-+-+-+" <<endl;
    }
    cout << "\n    >>" <<((first)? "0" : "@" ) << "の番です。" << "<<\n" <<endl;
}

int judge (int judge_t,int judge_y){
    int judge_i,judge_j;
    if(judge_t < 1 || judge_t > 8 || judge_y < 1 || judge_y >8){
        cout << "座標は1~8で指定してください" << endl;
        return 0;
    }
    LOOP(judge_i,3){
        LOOP(judge_j,3){
            
        }
    }
}

void input (){//入力と置けるかどうかの判断
    int input_t,input_y;
    do{
        cout << "石を置く座標を入力してください(1~8)" << endl;
        cin >> tate >> yoko;
    }while( judge(tate,yoko) == 0);


int main (){
    title();
    b_reset();
    hyouzi ();
    return 0;
}



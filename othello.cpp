#include <iostream>
using namespace std;

#define LOOP(val,times) for(val=0;val<(times);val++)

#define LIMIT 8


//グローバル変数置き場
bool first = true;//先手の番か
bool player = true;//プレイヤーは先手か
bool pass = false;//直前にパスしたか
int board[LIMIT][LIMIT];//盤面
char name[32];//プレイヤーの名前

void title (){
//タイトル表示
    cout << "\n"
    << "  ######################################################################\n"
    << "  # OOOOO TTTTT H   H EEEEE L     L     OOOOO  GGGGG   A   M   M EEEEE #\n"
    << "  # O   O   T   H   H E     L     L     O   O  G      A A  MM MM E     #\n"  
    << "  # O   O   T   HHHHH EEEEE L     L     O   O  G GGG A   A M M M EEEEE #\n"  
    << "  # O   O   T   H   H E     L     L     O   O  G   G AAAAA M   M E     #\n"  
    << "  # OOOOO   T   H   H EEEEE LLLLL LLLLL OOOOO  GGGGG A   A M   M EEEEE #\n"
    << "  ######################################################################\n\n"
    << "    名前を入れてください(<32 words)" << endl;
    cin >> name;
    cout << "    ようこそ" << name << "\n\n\n";    
}

void b_reset(){
//盤面の初期化
    int b_i,b_j;
    LOOP(b_i,LIMIT){
        LOOP(b_j,LIMIT){
            board[b_i][b_j] = 0;
        }
    }
    board[3][3] = board[4][4] = 1;
    board[3][4] = board[4][3] = 2;
}


void hyouzi () {
//盤面表示
    int hyouzi_i,hyouzi_j;
    cout << "    1 2 3 4 5 6 7 8" <<endl;
    cout << "   +-+-+-+-+-+-+-+-+" <<endl;
    LOOP(hyouzi_i,LIMIT){
        cout << "  " << hyouzi_i+1 << "|";
        LOOP(hyouzi_j,LIMIT){
            switch(board[hyouzi_i][hyouzi_j]){
                case 0:
                    cout << " " ;
                    break;
                case 1:
                    cout << "○" ;
                    break;
                case 2:
                    cout << "●" ;
                    break;
            }
            cout << "|";
        }
        cout << "\n"
               <<"   +-+-+-+-+-+-+-+-+" <<endl;
    }
}

int judge_dir(int jd_t,int jd_y,int d_t,int d_y){
//置けるかどうかの判断(一方向のみ)
//置けるとき1,置けないとき0
    jd_t += d_t;
    jd_y += d_y;
    if ( jd_t < 0 || jd_t >7 || jd_y < 0 || jd_y >7 || board[jd_t][jd_y] == 0 ){
        return 0;
    }
    if (first){
        if(board[jd_t][jd_y] == ((first)? 1:2)){return 0;}
    }
    while(1){
        jd_t += d_t;
        jd_y += d_y;
        if ( jd_t < 0 || jd_t >7 || jd_y < 0 || jd_y >7 || board[jd_t][jd_y] == 0 ){
            return 0;
        }
        if (board[jd_t][jd_y] == ((first)? 1:2)){
        return 1;}
    }
}

int turn (int turn_t,int turn_y,int turn_dt,int turn_dy){
//裏返し処理（一方向）
    while(1){
        turn_t += turn_dt;
        turn_y += turn_dy;
        if(board[turn_t][turn_y] == ((first)? 1:2)){return 0;}
        board[turn_t][turn_y] = ((first)? 1:2);
    }
}

int judge (int judge_t,int judge_y){
//おけるかどうかのチェック全般&裏返し
    bool judge_b = false;
    int judge_i,judge_j;
    if(judge_t < 0 || judge_t > 7 || judge_y <0 || judge_y >7){
        cout << "座標は1~8で指定してください" << endl;
        return 0;
    }
    if ( !board[judge_t][judge_y] == 0){
        cout << "既に石があります" << endl;
        return 0;
    }
    LOOP(judge_i,3){
        LOOP(judge_j,3){
            if(judge_dir(judge_t, judge_y, judge_i-1, judge_j-1)){
                turn(judge_t,judge_y,judge_i-1,judge_j-1);
                judge_b = true;
            }
        }
    }
    if(judge_b){return 1;}
    else{
        cout << "その場所には置けません" << endl;
        return 0;
    }
}

void input (){
//入力と配置と手番処理
    int input_t,input_y;
    cout << "\n    >>" <<((first)? "0" : "@" ) << "の番です。" << "<<\n" <<endl;
    do{
        cout << "石を置く座標を入力してください(1~8)" << endl;
        cin >> input_t >> input_y;
        input_t --;//配列座標に変換
        input_y --;
    }while(judge(input_t,input_y) == 0);
    board[input_t][input_y] = ((first)? 1:2);
    first = !first;//手番入れ替え
    pass = false;//パスしてないよ
}

int cheack(){
//終了判断(2人がパスする状況になったら)
    int cheack_i,cheack_j,cheack_t,cheack_y;
    LOOP(cheack_i,8){
        LOOP(cheack_j,8){
            if(board[cheack_i][cheack_j]==0){
                LOOP(cheack_t,3){
                    LOOP(cheack_y,3){
                        if(judge_dir(cheack_i,cheack_j,cheack_t-1,cheack_y-1)){return 1;}
                    }
                }
            }
        }
    }
    if(pass){return 0;}
    pass = true;
    first != first;
    return 1;
}

void ending (){
//結果表示
    int ending_i,ending_j,ending_white,ending_black;
    ending_white = ending_black =0;
    LOOP(ending_i,8){
        LOOP(ending_j,8){
            switch(board[ending_i][ending_j]){
                case 1:
                    ending_white ++;
                    break;
                
                case 2:
                    ending_black ++;
                    break;
                
                default:
                    break;
            }
        }
    }
    hyouzi();
    cout << "0:" << ending_white <<"個\n"
         << "@:" << ending_black <<"個\n\n";
    if (ending_white == ending_black){cout << "引き分けです\n";}
    else{cout << ((ending_white > ending_black)? "0":"@") << "の勝ちです\n";}
}

int main (){
    title();
    b_reset();
    while ( cheack() ){
        if(cheack() == 0) {break;}
        hyouzi ();
        input ();
    }
    ending();
    return 0;
}


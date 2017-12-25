#include <bits/stdc++.h>
using namespace std;

#define REP(i,j) for(int i=0;i<j;i++)
#define REPR(i,j) for(int i=j;i>=0;i--)
#define FOR(i,j,k) for(int i=j;i<k;i++)


int main (){
    double sum, tmp, absmax;
    int N ,imax;
//入力
    cin >> N;
    double a[N][N];
    REP(i,N){
        REP(j,N){
            cin >> a[i][j];
       }
    }
//入力終了

//前進消去
    REP(k,N-1){
  //部分ピポット選択
        imax = k;
        absmax = fabs(a[k][k]);
        FOR(i,k+1,N){
            if( fabs(a[i][k]) > absmax ){
                absmax = fabs(a[i][k]);
                imax = i;
            }
        }
    if(imax != k){
        FOR(j,k,N){
            tmp = a[k][j];
            a[k][j] = a[imax][j];
            a[imax][j] = tmp;
        }
    }
  //部分ピポット選択終了
        FOR(i,k+1,N){
            FOR(j,k+1,N){
                a[i][j] = a[i][j]-a[k][j]*a[i][k]/a[k][k];
            }
             a[i][k] = 0.0;
        }
    }
//前進消去終了

//行列式の計算
    double answer = 1.0;
    REP(i,N){
        answer *= a[i][i];
    }
//行列式終了
    cout << answer << endl;
    return 0;
}
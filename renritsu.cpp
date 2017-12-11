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
    double a[N][N], b[N];
    REP(i,N){
        REP(j,N){
            cin >> a[i][j];
       }
    }
   REP(i,N){
       cin >> b[i];
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
        tmp = b[k];
        b[k] = b[imax];
        b[imax] = tmp;
    }
  //部分ピポット選択終了

        FOR(i,k+1,N){
            FOR(j,k+1,N){
                a[i][j] = a[i][j]-a[k][j]*a[i][k]/a[k][k];
            }
            b[i] = b[i]-b[k]*a[i][k]/a[k][k];
        }
    }

//後退代入
    REPR(i,N-1){
        sum = b[i];
        FOR(j,i+1,N){
            sum = sum-b[j]*a[i][j];
        }
        b[i] = sum/a[i][i];
    }
//解の表示
    REP(i,N){
        cout << setprecision(16) << b[i] << endl;
    }
    return 0;
}
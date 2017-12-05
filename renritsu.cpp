#include <bits/stdc++.h>
using namespace std;

#define REP(i,j) for(int i=0;i<j;i++)
#define REPR(i,j) for(int i=j;i>=0;i--)
#define FOR(i,j,k) for(int i=j;i<k;i++)

const int N = 3;//n元連立方程式
double a[N][N]={
                   {3.0, 1.0, 2.0},
                   {5.0, 1.0, 3.0},
                   {4.0, 2.0, 1.0}
                };
double b[N]={13.0, 20.0, 13.0};//2.1.3

int main (){
   double sum = 0.0;
//前進消去
    REP(k,N-1){
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
        cout << setprecision(17) << b[i] << endl;
    }
    return 0;
}

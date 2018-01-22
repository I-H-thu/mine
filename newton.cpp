#include <bits/stdc++.h>
using namespace std;

#define REP(i,j) for(int i=0;i<j;i++)
#define REPR(i,j) for(int i=j;i>=0;i--)
#define FOR(i,j,k) for(int i=j;i<k;i++)



double f(double x){
    return pow(x,5)-5*x*x*x+4*x;
}

double df(double x){
    return 5*pow(x,4)-5*3*x*x+4;
}

int main(){
    double x,y;
    int i, n = 30;
    double epsilon = pow(2.0,-52);
    cin >> x;
    REP(i,n){
        y = f(x)/df(x);
        if(fabs(y) < epsilon){
            break;
        }
        x = x-y;
    }
    cout << "answer is " << x <<"\nthe number of loop is " << i <<"\n";
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define REP(i,j) for(int i=0;i<j;i++)
#define REPR(i,j) for(int i=j;i>=0;i--)
#define FOR(i,j,k) for(int i=j;i<k;i++)

#define LIMIT 10000 //newton法の繰り返し最大回数


double f(double x){
    return pow(x,5)-5*x*x*x+4*x;
    //return x-log10(x)-1;
    //return sin(x) ;
}

double df(double x){
    return 5*pow(x,4)-5*3*x*x+4;
    //return 1 - 1/(x*log(10));
    //return cos(x);
}

int main(){
    double x,y;
    int i, n = LIMIT;
    const double epsilon = pow(2.0,-52);
    cout << "初期値:";
    cin >> x;
    for (i=0;i<n;i++){
        y = f(x)/df(x);
        if(fabs(y) < epsilon){
            break;
        }
        x = x-y;
    }
    cout << "解は" << setprecision(16) << x <<"です    繰り返し回数は" << i <<"回です\n";
    return 0;
}
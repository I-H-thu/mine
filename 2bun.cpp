#include <bits/stdc++.h>
using namespace std;

#define REP(i,j) for(int i=0;i<j;i++)
#define REPR(i,j) for(int i=j;i>=0;i--)
#define FOR(i,j,k) for(int i=j;i<k;i++)

double f(double x){
    return x-log10(x)-1;
}

int main (){
    double a,b,c;
    const double alpha = pow(2.0,-20);
    cin >> a >> b;
    if( f(a)* f(b) < 0.0){
        while( fabs(a - b) > alpha){
            c = (a+b)/2.0;
            if(f(a)*f(c) < 0.0){
                b = c;  
            }else{
                a = c;
            }
        }
        cout << "the answer is " << (a+b)/2.0 << "\n";
    }else{
        cout << "answer is not found\n";
    }
    return 0;
}
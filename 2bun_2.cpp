#include <bits/stdc++.h>
using namespace std;

#define REP(i,j) for(int i=0;i<j;i++)
#define REPR(i,j) for(int i=j;i>=0;i--)
#define FOR(i,j,k) for(int i=j;i<k;i++)

bool found = false;
const double alpha = pow(2.0,-20);

double f(double x){
    return pow(x,5)-5*x*x*x+4*x;
}

void search(double a,double b){
    double c;
    if( f(a)* f(b) < 0.0){
        while( fabs(a - b) > alpha){
            c = (a+b)/2.0;
            if(f(a)*f(c) < 0.0){
                b = c;  
            }else{
                a = c;
            }
        }
        cout << "the answer is " << setprecision(16) <<(a+b)/2.0 << "\n";
        found = true;
    }else{
    }
}

int main (){
    int n;
    double a,b,h;
    cout << "範囲a~b,分割回数n:";
    cin >> a >> b >> n;
    h = fabs(a-b)/n;
    REP(i,n){
        search(a+h*i, a+h*(i+1));
    }
    if(! found){
        cout << "answer is not found\n";
    }
    return 0;
}

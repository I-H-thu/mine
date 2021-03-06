#include <bits/stdc++.h>
using namespace std;

#define REP(i,j) for(int i=0;i<j;i++)
#define REPR(i,j) for(int i=j;i>=0;i--)
#define FOR(i,j,k) for(int i=j;i<k;i++)

#define LIMIT 10000 //newton法の繰り返し最大回数

vector<double> ans;

bool found = false;
const double alpha = pow(2.0,-20);

double f(double x){
    //return pow(x,5)-5*x*x*x+4*x;
    //return x-log10(x)-1;
    return sin(x) ;
}

double df(double x){
    //return 5*pow(x,4)-5*3*x*x+4;
    //return 1 - 1/(x*log(10));
    return cos(x);
}

void search(double a,double b){
    double c;
    if( f(a)* f(b) <= 0.0){
        while( fabs(a - b) > alpha){
            c = (a+b)/2.0;
            if(f(a)*f(c) < 0.0){
                b = c;
            }else{
                a = c;
            }
        }
        ans.push_back((a+b)/2.0);
        found = true;
    }
}


int newton(double x){
    double y;
    int i, n = LIMIT;
    double epsilon = pow(2.0,-52);
    for(i = 0;i < n;i++){
        y = f(x)/df(x);
        if(fabs(y) < epsilon){
            break;
        }
        x = x-y;
    }
    if(!found && i == LIMIT){
        cout << "解が見つかりません\n";
        return 1;
    }else{
        cout << "解は" << setprecision(16) << x <<"です    繰り返し回数は" << i <<"回です\n";
        return 0;
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
        cout <<"二分法で解が見つかりませんでした。初期値0でニュートン法を実行します。\n";
        newton(0.);
    }
    REP(i,ans.size()){
        newton(ans[i]);
        cout << "    初期値:" << setprecision(16) << ans[i] <<"\n";
    }
    return 0;
}
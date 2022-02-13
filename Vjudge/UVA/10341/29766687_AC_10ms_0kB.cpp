#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e3+10,M=2e4+7,OO=0x3f3f3f3f;
const double eps=1e-9;

int p,q,r,s,t,u;

double f(double x){
    return p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;
}

double bi(){
    double lo=0,hi=1;
    for(int i=0;i<100;++i){
        double md=(lo+hi)/2;
        if(f(md)<=0) hi=md;
        else lo=md;
    }
    return lo;
}

int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    while(~scanf("%d%d%d%d%d%d",&p,&q,&r,&s,&t,&u)){
        if(f(0)*f(1)>0){
            puts("No solution");
        }
        else{
            printf("%.4lf\n",bi());
        }
    }

    return 0;
}

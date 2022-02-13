#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e3+10,M=2e4+7,OO=0x3f3f3f3f;
const double eps=1e-9;

double f(double curX,vector<double> &x,vector<double> &y){
    double mx=0;
    for(int i=0;i<x.size();++i){
        mx=max(mx,hypot(curX-x[i],y[i]));
    }
    return mx;
}

int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    int n;
    while(~scanf("%d",&n),n){
        vector<double> x(n),y(n);
        for(int i=0;i<n;++i)
            scanf("%lf%lf",&x[i],&y[i]);

        double lo=-200000,sz=400000;
        for(;sz>1e-10;sz*=2.0/3){
            double g=lo+sz/3,h=g+sz/3;
            if(f(g,x,y)>f(h,x,y)) lo=g;
        }

        printf("%.6lf %.6lf\n",lo,f(lo,x,y));
    }

    return 0;
}

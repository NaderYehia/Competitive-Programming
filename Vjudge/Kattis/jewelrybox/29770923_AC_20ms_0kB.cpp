#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e3+10,M=2e4+7,OO=0x3f3f3f3f;
const double eps=1e-9;


double f(double curH,double x,double y){
    return curH*(x-2*curH)*(y-2*curH);
}

int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    int t;
    scanf("%d",&t);
    while(t--){
        int x,y;
        scanf("%d%d",&x,&y);
        double lo=0,sz=min(x/2.0,y/2.0);
        for(;sz>1e-10;sz*=2.0/3){
            double g=lo+sz/3,h=g+sz/3;
            if(f(g,x,y)<f(h,x,y)) lo=g;
        }
        printf("%.6lf\n",f(lo,x,y));
    }

    return 0;
}

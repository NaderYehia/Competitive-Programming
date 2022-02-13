#include<bits/stdc++.h>

using namespace std;

int cur[]={10000,5000,2000,1000,500,200,100,50,20,10,5};
long long mem[15][300005];

long long solve(int money,int lst){
    if(lst==-1)
        return 0;
    if(money==0)    return 1;
    if(mem[lst][money]!=-1) return mem[lst][money];
    return mem[lst][money]=solve(money,lst-1)+(money-cur[lst]>=0?solve(money-cur[lst],lst):0);
}

int main() {
    int x,y;
    memset(mem,-1,sizeof mem);
    while(scanf("%d.%d",&x,&y),(x||y)){
        int mon=x*100+y;
        printf("%3d.%02d%17lld\n",x,y,solve(mon,10));
    }
	return 0;
}

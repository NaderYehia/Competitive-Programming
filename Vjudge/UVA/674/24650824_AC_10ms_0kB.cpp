#include<bits/stdc++.h>

using namespace std;

int cur[]={50,25,10,5,1};
long long mem[15][30005];

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
    while(~scanf("%d",&x)){
        printf("%lld\n",solve(x,4));
    }
	return 0;
}

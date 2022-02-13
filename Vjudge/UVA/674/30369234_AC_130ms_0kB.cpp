#include <bits/stdc++.h>

using namespace std;

const int N=2e4+10;

long long mem[5][N];

int coins[]={1,5,10,25,50};

long long solve(int i,int rem){
    if(i==5) return (rem==0);

    if(mem[i][rem]!=-1) return mem[i][rem];

    int ret=0;
    for(int j=0;j*coins[i]<=rem;++j){
        ret+=solve(i+1,rem-j*coins[i]);
    }

    return mem[i][rem]=ret;
}


int main()
{

    memset(mem,-1,sizeof mem);

    int n;
    while(~scanf("%d",&n)){

        printf("%lld\n",solve(0,n));

    }

    return 0;
}

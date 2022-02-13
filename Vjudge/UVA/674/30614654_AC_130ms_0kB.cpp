#include <bits/stdc++.h>

using namespace std;

const int N=2e4+10;

int arr[]={50,25,10,5,1};

long long mem[6][N];

long long solve(int i,int rem){
    if(i==5) return rem==0;
    if(mem[i][rem]!=-1) return mem[i][rem];

    long long ret=0;
    for(int j=0;j*arr[i]<=rem;++j){
        ret+=solve(i+1,rem-arr[i]*j);
    }

    return mem[i][rem]=ret;
}

int main()
{
    int n;
    memset(mem,-1,sizeof mem);
    while(~scanf("%d",&n)){
        printf("%lld\n",solve(0,n));
    }

    return 0;
}

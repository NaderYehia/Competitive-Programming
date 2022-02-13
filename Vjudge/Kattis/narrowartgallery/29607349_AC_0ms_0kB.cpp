#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=2e2+10,M=2e4+7,OO=0x3f3f3f3f;

int arr[2][N];

int mem[N][N][3];

int solve(int i,int rem,int bck){
    if(i<=-1) return (rem==0)?0:OO;
    int &ret=mem[i][rem][bck];
    if(~ret) return ret;
    ret=solve(i-1,rem,2);
    if(bck==2){
        ret=min(ret,solve(i-1,rem-1,0)+arr[0][i]);
        ret=min(ret,solve(i-1,rem-1,1)+arr[1][i]);
    }
    else{
        ret=min(ret,solve(i-1,rem-1,bck)+arr[bck][i]);
    }
    return ret;
}

int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    int n,k;
    while(~scanf("%d%d",&n,&k),n||k){
        int sum=0;
        for(int i=0;i<n;++i)
            scanf("%d%d",arr[0]+i,arr[1]+i),sum+=arr[i&1][i],sum+=arr[(i+1)&1][i];
        memset(mem,-1,sizeof mem);
        printf("%d\n",sum-solve(n-1,k,2));
    }


    return 0;
}

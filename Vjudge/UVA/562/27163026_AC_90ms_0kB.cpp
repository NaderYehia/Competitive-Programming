#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=1e5+5,M=1e9+7,SEGM=4*N,OO=0x3f3f3f3f;
int t,n,mxSum;
int arr[105];
int mem[105][105*505];

int solve(int i=0,int sum=0){
    if(i==n) return abs((mxSum-sum)-sum);
    int &ret=mem[i][sum];
    if(~ret) return mem[i][sum];
    ret=min(solve(i+1,sum),solve(i+1,sum+arr[i]));
    return ret;
}

int main(){
    //freopen("myfile.txt","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        mxSum=0;
        for(int i=0;i<n;++i)
            scanf("%d",arr+i),mxSum+=arr[i];
        memset(mem,-1,sizeof mem);
        printf("%d\n",solve());
    }
    return 0;
}

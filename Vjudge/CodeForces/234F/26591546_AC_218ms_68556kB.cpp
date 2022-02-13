#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e5+5,M=1e9+7,OO=0x3f3f3f3f;
const double eps=1e-6,pi=acos(-1);
int t,n,k,a,b,m;
int arr[205];
int mem[205][40005][2];

int solve(int i,int a,int b,int bck){
    if(i==n)
        return 0;
    int &ret=mem[i][a][bck];
    if(ret!=-1) return ret;
    if(bck){
        ret=b-arr[i]>=0?solve(i+1,a,b-arr[i],1):(int)1e9;
        ret=min(ret,a-arr[i]>=0?solve(i+1,a-arr[i],b,0)+min(arr[i],arr[i-1]):(int)1e9);
    }
    else{
        ret=a-arr[i]>=0?solve(i+1,a-arr[i],b,0):(int)1e9;
        ret=min(ret,b-arr[i]>=0?solve(i+1,a,b-arr[i],1)+min(arr[i],arr[i-1]):(int)1e9);
    }
    return ret;
}

int main(){
    freopen("output.txt","w",stdout);
    freopen("input.txt","r",stdin);
    scanf("%d%d%d",&n,&a,&b);
    for(int i=0;i<n;++i)
        scanf("%d",arr+i);
    memset(mem,-1,sizeof mem);
    int mn=(a-arr[0]>=0)?solve(1,a-arr[0],b,0):(int)1e9;
    mn=min(mn,b-arr[0]>=0?solve(1,a,b-arr[0],1):(int)1e9);
    cout<<(mn==(int)1e9?-1:mn);
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e5+5,OO=0x3f3f3f3f;
const double eps=1e-6,pi=3.14159265359;
int t,n,k,m,x,y,M,C;
int arr[N];
int ans[N];
int mem[N];

int solve(int i){
    if(i>=m)
        return 0;
    int &ret=mem[i];
    if(ret!=-1) return ret;
    ret=max(solve(i+1),arr[i]+solve(i+2));
    return ret;
}

int solve1(int i){
    if(i>=n)
        return 0;
    int &ret=mem[i];
    if(ret!=-1) return ret;
    ret=max(solve1(i+1),ans[i]+solve1(i+2));
    return ret;
}

int main(){
    //freopen("myfile.txt","w",stdout);
    while(~scanf("%d%d",&n,&m),(n+m)){
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j)
                scanf("%d",arr+j);
            memset(mem,-1,sizeof mem);
            ans[i]=solve(0);
        }
        memset(mem,-1,sizeof mem);
        printf("%d\n",solve1(0));
    }
    return 0;
}

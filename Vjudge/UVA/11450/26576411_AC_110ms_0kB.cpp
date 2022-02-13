#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e4+5,OO=0x3f3f3f3f;
const double eps=1e-6,pi=3.14159265359;
int t,n,k,m,x,y,M,C;
int arr[25][25];
int mem[25][300];

int solve(int i,int rem){
    if(i==C){
        return M-rem;
    }
    int &ret=mem[i][rem];
    if(ret!=-1) return ret;
    for(int j=1;j<=arr[i][0];++j){
        ret=max(ret,rem-arr[i][j]>=0?solve(i+1,rem-arr[i][j]):(int)-1e9);
    }
    return ret;
}

int main(){
    //freopen("myfile.txt","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&M,&C);
        for(int i=0;i<C;++i){
            scanf("%d",arr[i]+0);
            for(int j=1;j<=arr[i][0];++j)
                scanf("%d",arr[i]+j);
        }
        memset(mem,-1,sizeof mem);
        int ans=solve(0,M);
        if(ans!=-1) printf("%d\n",ans);
        else printf("no solution\n");
    }
    return 0;
}

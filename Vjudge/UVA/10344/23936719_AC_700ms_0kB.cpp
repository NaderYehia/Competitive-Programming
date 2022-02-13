#include<bits/stdc++.h>

using namespace std;

const int N = 1e3+6,M=1e9+7,OO=0x3f3f3f3f;

int t,n,m,k,sum;
int arr[10];
bool suc;
bool vis[5];

void solve(){
    if(vis[0]&&vis[1]&&vis[2]&&vis[3]&&vis[4]){
        if(sum==23)
            suc=1;
        return;
    }
    for(int i=0;i<5;++i){
        if(!vis[i]){
            vis[i]=1;
            sum+=arr[i];
            solve();
            sum-=arr[i];
            sum-=arr[i];
            solve();
            sum+=arr[i];
            sum*=arr[i];
            solve();
            sum/=arr[i];
            vis[i]=0;
        }
    }
}

int main(){
    while(scanf("%d%d%d%d%d",arr+0,arr+1,arr+2,arr+3,arr+4),arr[0]||arr[1]||arr[2]||arr[3]||arr[4]){
        suc=0;
        memset(vis,0,sizeof vis);
        for(int i=0;i<5;++i){
            sum=arr[i];
            vis[i]=1;
            solve();
            vis[i]=0;
        }
        if(suc)
            printf("Possible\n");
        else
            printf("Impossible\n");
    }
    return 0;
}

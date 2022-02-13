#include<bits/stdc++.h>

using namespace std;

int t,n,m,mx,sum;
int arr[10][10];
bool vis[10][10];

bool legal(int u,int v){
    return u>-1&&v>-1&&u<8&&v<8;
}

bool valid(int u,int v){
    for(int i=u-1,j=1;i>-1;--i,++j){
        if(vis[i][v]||(legal(i,v-j)&&vis[i][v-j])||(legal(i,v+j)&&vis[i][v+j]))
            return 0;
    }
    return 1;
}

void solve(int i){
    if(i==8){
        mx=max(mx,sum);
        return;
    }
    for(int j=0;j<8;++j){
        if(valid(i,j)){
            sum+=arr[i][j];
            vis[i][j]=1;
            solve(i+1);
            sum-=arr[i][j];
            vis[i][j]=0;
        }
    }
}

int main() {
    scanf("%d",&t);
    while(t--){
        for(int i=0;i<8;++i)
            for(int j=0;j<8;++j)
                scanf("%d",arr[i]+j);
        mx=0;
        solve(0);
        printf("%5d\n",mx);
    }
	return 0;
}

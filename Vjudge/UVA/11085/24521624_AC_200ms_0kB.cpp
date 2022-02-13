#include<bits/stdc++.h>

using namespace std;

int t,n,m,mn,sum,k;
int arr[10];
int tmp[10];
bool vis[10][10];
vector<int>v;

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

int getMn(){
    int sum=0;
    for(int i=0;i<8;++i){
        for(int j=0;j<8;++j){
            if(vis[j][i])
                if(arr[i]!=j+1)
                    ++sum;
        }
    }
    return sum;
}

void solve(int i){
    if(i==8){
        mn=min(mn,getMn());
        return;
    }
    for(int j=0;j<8;++j){
        if(valid(i,j)){
                vis[i][j]=1;
            solve(i+1);
            vis[i][j]=0;
        }
    }
}

int main() {
    while(~scanf("%d%d%d%d%d%d%d%d",arr+0,arr+1,arr+2,arr+3,arr+4,arr+5,arr+6,arr+7)){
        mn=0x3f3f3f3f;
        solve(0);
        printf("Case %d: %d\n",++k,mn);
    }
	return 0;
}

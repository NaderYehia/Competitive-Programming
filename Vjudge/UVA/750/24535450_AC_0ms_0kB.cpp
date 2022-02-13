#include<bits/stdc++.h>

using namespace std;

int t,k,n,m,x,y;
vector<int> v;
bool vis[10][10];

void print(){
    if(k<9)
        printf(" %d      ",++k);
    else
        printf("%d      ",++k);
    for(int i=0;i<v.size();++i)
        printf("%d%c",v[i]+1," \n"[i+1==v.size()]);
}

bool legal(int u,int v){
    return u>-1&&v>-1&&u<8&&v<8;
}

bool valid(int u,int v){
    for(int i=v-1,j=1;i>-1;--i,++j){
        if(vis[u][i]||(legal(u-j,i)&&vis[u-j][i])||(legal(u+j,i)&&vis[u+j][i]))
            return 0;
    }
    for(int i=v+1,j=1;i<8;++i,++j){
        if(vis[u][i]||(legal(u-j,i)&&vis[u-j][i])||(legal(u+j,i)&&vis[u+j][i]))
            return 0;
    }
    return 1;
}

void solve(int j){
    if(j==y){
        v.push_back(x);
        solve(j+1);
        v.pop_back();
        return;
    }
    if(j==8){
        print();
        return;
    }
    for(int i=0;i<8;++i){
        if(valid(i,j)){
            v.push_back(i);
            vis[i][j]=1;
            solve(j+1);
            v.pop_back();
            vis[i][j]=0;
        }
    }
}

int main() {
    scanf("%d",&t);
    while(t--){
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        scanf("%d%d",&x,&y);
        --x,--y;
        vis[x][y]=1;
        solve(0);
        vis[x][y]=0;
        k=0;
        if(t)
            printf("\n");
    }
	return 0;
}

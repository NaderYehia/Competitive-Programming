#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e2+10,M=2e4+7,OO=0x3f3f3f3f;

int n;
string target="ICPCASIASG";

char s[N*N];

int to_idx(int r,int c){
    return r*n+c;
}

bool valid(int r,int c){
    return r>-1&&c>-1&&r<n&&c<n;
}

bool vis[N][N][15];

bool dfs(int r,int c,int cur){
    if(cur==9) return 1;
    vis[r][c][cur]=1;
    bool ret=0;
    for(int i=-1;i<2;i+=2){
        for(int j=-1;j<2;j+=2){
            for(int ii=2,jj=1,k=0;k<2;swap(ii,jj),++k){
                int di=ii*i,dj=jj*j;
                if(valid(r+di,c+dj)&&s[to_idx(r+di,c+dj)]==target[cur+1]&&!vis[r+di][c+dj][cur+1])
                    ret|=dfs(r+di,c+dj,cur+1);
            }
        }
    }
    return ret;
}

int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    scanf("%d",&n);
    scanf("%s",s);
    bool found=0;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(s[to_idx(i,j)]=='I')
                found|=dfs(i,j,0);
        }
    }
    if(found) printf("YES\n");
    else printf("NO\n");

    return 0;
}

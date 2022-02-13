#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e3+10,M=98765431,OO=0x3f3f3f3f;

int dis[10][10];

bool valid(int r,int c){
    return r>-1&&c>-1&&r<8&&c<8;
}

int bfs(int sr,int sc,int tr,int tc){
    memset(dis,'?',sizeof dis);
    queue<pair<int,int> > q;
    dis[sr][sc]=0;
    q.push({sr,sc});
    while(q.size()){
        int r=q.front().first;
        int c=q.front().second;
        q.pop();
        for(int i=-1;i<2;i+=2){
            for(int j=-1;j<2;j+=2){
                for(int k=0,ii=1,jj=2;k<2;++k,swap(ii,jj)){
                    int di=ii*i,dj=jj*j;
                    if(valid(r+di,c+dj)&&dis[r+di][c+dj]==OO){
                        dis[r+di][c+dj]=dis[r][c]+1;
                        q.push({r+di,c+dj});
                    }
                }
            }
        }
    }
    return dis[tr][tc];
}


int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    char s[3],t[3];
    while(~scanf("%s%s",s,t)){
        int srcR=s[0]-'a';
        int srcC=s[1]-'1';
        int trgR=t[0]-'a';
        int trgC=t[1]-'1';
        printf("To get from %s to %s takes %d knight moves.\n",s,t,bfs(srcR,srcC,trgR,trgC));
    }

    return 0;
}

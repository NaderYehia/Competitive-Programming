#include<bits/stdc++.h>

using namespace std;

const int N=1e6+5,OO=0x3f3f3f3f;
int n,m,k;
int dism[105][105];
int disc[105][105];

bool valid(int x,int y){
    return x>-1&&y>-1&&x<n&&y<m;
}

void bfsm(int x,int y){
    queue<pair<int,int> > q;
    q.push({x,y});
    dism[x][y]=0;
    while(q.size()){
        int r=q.front().first;
        int c=q.front().second;
        q.pop();
        for(int i=-1;i<2;++i){
            for(int j=-1;j<2;++j){
                if(abs(i)==abs(j))continue;
                if(valid(r+i,c+j)&&dism[r+i][c+j]==-1)
                    dism[r+i][c+j]=dism[r][c]+1,q.push({r+i,c+j});
            }
        }
    }
}

void bfsc(int x,int y,int u,int v){
    queue<pair<int,int> > q;
    q.push({x,y}),q.push({u,v});
    disc[x][y]=0,disc[u][v]=0;
    while(q.size()){
        int r=q.front().first;
        int c=q.front().second;
        q.pop();
        for(int i=-1;i<2;++i){
            for(int j=-1;j<2;++j){
                if(abs(i)==abs(j))continue;
                if(valid(r+i,c+j)&&disc[r+i][c+j]==-1)
                    disc[r+i][c+j]=disc[r][c]+1,q.push({r+i,c+j});
            }
        }
    }
}

int main() {
    scanf("%d%d%d",&m,&n,&k);
    while(k--){
        int mx,my,c1x,c1y,c2x,c2y;
        scanf("%d%d%d%d%d%d",&mx,&my,&c1x,&c1y,&c2x,&c2y);
        memset(disc,-1,sizeof disc);
        memset(dism,-1,sizeof dism);
        bfsm(mx-1,my-1);
        bfsc(c1x-1,c1y-1,c2x-1,c2y-1);
        int ok=0;
        for(int i=0;i<n;++i){
            if(dism[0][i]<disc[0][i])
                ok=1;
            if(dism[m-1][i]<disc[m-1][i])
                ok=1;
        }
        for(int i=0;i<m;++i){
            if(dism[i][0]<disc[i][0])
                ok=1;
            if(dism[n-1][i]<disc[n-1][i])
                ok=1;
        }
        if(ok)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}

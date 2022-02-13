#include <bits/stdc++.h>

using namespace std;

const int N=1e3+5,OO=0x3f3f3f3f;
int t,n,m,k,q;
char grid[N][N];
char srid[N][N];

bool valid(int u,int v){
    return u<n&&v<n&&u>-1&&v>-1;
}

bool checkUpdown(int u,int v){
    for(int i=0;i<m;++i){
        for(int j=0;j<m;++j){
            if(!valid(u-i,v-j)||srid[i][j]!=grid[u-i][v-j])
                return false;
        }
    }
    return true;
}

int updown(){
    int cnt=0;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(checkUpdown(i,j))
                ++cnt;
        }
    }
    return cnt;
}

bool checkRightie(int u,int v){
    //if(m-1>v||n-u<m) return false;
    for(int i=0;i<m;++i){
        for(int j=0;j<m;++j){
            if(!valid(u+j,v-i)||srid[i][j]!=grid[u+j][v-i])
                return false;
        }
    }
    return true;
}

int rightie(){
    int cnt=0;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(checkRightie(i,j))
                ++cnt;
        }
    }
    return cnt;
}

bool checkLeftie(int u,int v){
    //if(m-1>u||n-v<m) return false;
    for(int i=0;i<m;++i){
        for(int j=0;j<m;++j){
            if(!valid(u-j,v+i)||srid[i][j]!=grid[u-j][v+i])
                return false;
        }
    }
    return true;
}

int leftie(){
    int cnt=0;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(checkLeftie(i,j))
                ++cnt;
        }
    }
    return cnt;
}

bool checkNormie(int u,int v){
    //if(n-u<m||n-v<m) return false;
    for(int i=0;i<m;++i){
        for(int j=0;j<m;++j){
            if(!valid(u+j,v+i)||grid[u+i][v+j]!=srid[i][j])
                return false;
        }
    }
    return true;
}

int normie(){
    int cnt=0;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(checkNormie(i,j))
                ++cnt;
        }
    }
    return cnt;
}

int main(){
    while(~scanf("%d%d",&n,&m)&&(n+m)){
        for(int i=0;i<n;++i){
            scanf("%s",grid[i]);
        }
        for(int i=0;i<m;++i){
            scanf("%s",srid[i]);
        }
        printf("%d %d %d %d\n",normie(),rightie(),updown(),leftie());
    }
    return 0;
}

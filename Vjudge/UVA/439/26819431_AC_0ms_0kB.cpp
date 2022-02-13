#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=1e5+5,M=1e9+7,OO=0x3f3f3f3f;
int t,n,m,k;
int dis[10][10];

bool valid(int u,int v){
    return u>-1&&v>-1&&u<8&&v<8;
}

void bfs(int r,int c,int rr,int cc){
    memset(dis,-1,sizeof dis);
    queue<pair<int,int> > q;
    q.push(make_pair(r,c));
    dis[r][c]=0;
    while(q.size()){
        int u=q.front().first;
        int v=q.front().second;
        q.pop();
        if(u==rr&&v==cc){
            printf("To get from %c%c to %c%c takes %d knight moves.\n",(char)r+'a',(char)'0'+1+c,(char)rr+'a',(char)cc+'0'+1,dis[u][v]);
            return;
        }
        if(valid(u+2,v+1)&&!(~dis[u+2][v+1]))
            q.push(make_pair(u+2,v+1)),dis[u+2][v+1]=dis[u][v]+1;
        if(valid(u+2,v-1)&&!(~dis[u+2][v-1]))
            q.push(make_pair(u+2,v-1)),dis[u+2][v-1]=dis[u][v]+1;
        if(valid(u-2,v+1)&&!(~dis[u-2][v+1]))
            q.push(make_pair(u-2,v+1)),dis[u-2][v+1]=dis[u][v]+1;
        if(valid(u-2,v-1)&&!(~dis[u-2][v-1]))
            q.push(make_pair(u-2,v-1)),dis[u-2][v-1]=dis[u][v]+1;
        if(valid(u+1,v+2)&&!(~dis[u+1][v+2]))
            q.push(make_pair(u+1,v+2)),dis[u+1][v+2]=dis[u][v]+1;
        if(valid(u+1,v-2)&&!(~dis[u+1][v-2]))
            q.push(make_pair(u+1,v-2)),dis[u+1][v-2]=dis[u][v]+1;
        if(valid(u-1,v+2)&&!(~dis[u-1][v+2]))
            q.push(make_pair(u-1,v+2)),dis[u-1][v+2]=dis[u][v]+1;
        if(valid(u-1,v-2)&&!(~dis[u-1][v-2]))
            q.push(make_pair(u-1,v-2)),dis[u-1][v-2]=dis[u][v]+1;
    }
}

int main(){
    //freopen("myfile.txt","w",stdout);
    char s1[N],s2[N];
    while(~scanf("%s %s",s1,s2)){
        bfs(s1[0]-'a',s1[1]-'0'-1,s2[0]-'a',s2[1]-'0'-1);
    }
    return 0;
}

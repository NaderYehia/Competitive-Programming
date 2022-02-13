#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e6+10,M=2e9+7,OO=0x3f3f3f3f;

int f,s,g,u,d;
int dis[N];

int bfs(){
    memset(dis,-1,sizeof dis);
    queue<int> q;
    dis[s]=0;
    q.push(s);

    while(q.size()){
        int cur=q.front();
        q.pop();
        if(cur==g) return dis[g];
        if(cur+u<=f&&dis[cur+u]==-1){
            dis[cur+u]=dis[cur]+1;
            q.push(cur+u);
        }
        if(cur-d>0&&dis[cur-d]==-1){
            dis[cur-d]=dis[cur]+1;
            q.push(cur-d);
        }
    }
    return -1;
}

int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    scanf("%d%d%d%d%d",&f,&s,&g,&u,&d);

    int ans=bfs();
    if(~ans) printf("%d\n",ans);
    else printf("use the stairs\n");

    return 0;
}

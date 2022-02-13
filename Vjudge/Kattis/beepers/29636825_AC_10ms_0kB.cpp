#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e3+10,M=1e3+7,OO=0x3f3f3f3f;


int n,m,ss,se,p;
int mem[12][1<<11];
vector<pair<int,int> > v;

int dis(int i,int j){
    return abs(v[i].first-v[j].first)+abs(v[i].second-v[j].second);
}

int solve(int cur,int msk){
    if(msk==(1<<p)-1) return dis(0,cur);
    int &ret=mem[cur][msk];
    if(~ret) return ret;
    ret=OO;
    for(int i=0;i<p;++i){
        if((1<<i)&msk) continue;
        ret=min(ret,solve(i,msk|(1<<i))+dis(i,cur));
    }
    return ret;
}

int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        scanf("%d%d%d",&ss,&se,&p);
        v.resize(p+1);
        v[0].first=ss,v[0].second=se;
        ++p;
        for(int i=1;i<p;++i){
            int r,c;
            scanf("%d%d",&r,&c);
            v[i].first=r;
            v[i].second=c;
        }
        memset(mem,-1,sizeof mem);
        printf("%d\n",solve(0,1));
    }

    return 0;
}

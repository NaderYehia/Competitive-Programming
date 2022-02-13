#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e6+10,M=1e9+7,OO=0x3f3f3f3f;
const double eps=1e-6;

int n,m;
int x[25],y[26];
char str[25][30];

map<string,int> mp;

int mem[30][1<<20];

int dis(int i,int j){
    return abs(x[i]-x[j])+abs(y[i]-y[j]);
}

int solve(int bk,int msk){
    if(msk==((1<<m)-1)) return dis(n,bk);
    int &ret=mem[bk][msk];
    if(~ret) return ret;
    ret=OO;
    for(int i=0;i<n;++i){
        int j=mp[str[i]];
        if(msk&(1<<j)) continue;
        ret=min(ret,solve(i,msk|(1<<j))+dis(bk,i));
    }
    return ret;
}

int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    memset(mem,-1,sizeof mem);
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d%d%s",x+i,y+i,str[i]),mp[str[i]];
    x[n]=y[n]=0;

    m=0;
    for(map<string,int>::iterator it=mp.begin();it!=mp.end();++it) (*it).second=m++;

    printf("%d\n",solve(n,0));

    return 0;
}

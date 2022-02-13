#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=1e2+5,M=1e9+7,SEGM=4*N,OO=0x3f3f3f3f;
int t,n,m,v1,v2;
int mem[105][2005];

int solve(int i,int cur){
    //cout<<i<<" "<<cur<<endl;
    if(cur<v1) return -OO;
    if(i>=n) return cur==v2?cur:-OO;
    int &ret=mem[i][cur];
    if(~ret) return ret;
    ret=solve(i+1,cur)+cur;
    for(int j=1;j<=m;++j){
        ret=max(ret,solve(i+1,cur-j)+cur);
        ret=max(ret,solve(i+1,cur+j)+cur);
    }
    return ret;
}

int main(){
    //freopen("myfile.txt","w",stdout);
    scanf("%d%d%d%d",&v1,&v2,&n,&m);
    if(v1>v2) swap(v1,v2);
    memset(mem,-1,sizeof mem);
    cout<<solve(1,v1);
    return 0;
}

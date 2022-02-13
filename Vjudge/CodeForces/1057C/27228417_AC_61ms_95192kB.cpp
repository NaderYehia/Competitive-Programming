#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=5e3+5,M=1e9+7,SEGM=4*N,OO=0x3f3f3f3f;
int t,n,m,k;
int arr[55];
char s[55];
int mem[55][2005][55][4];
map<char,int>mp;

int solve(int i,int remK,int prval,int prcal){
    if(remK<=0) return 0;
    int &ret=mem[i][remK][prval][prcal];
    if(~ret) return ret;
    ret=OO;
    if(arr[i]>prval&&prcal!=mp[s[i]]) ret=min(ret,solve(i,remK-arr[i],arr[i],mp[s[i]]));
    if(i+1<n) ret=min(ret,solve(i+1,remK,prval,prcal)+1);
    if(i-1>-1) ret=min(ret,solve(i-1,remK,prval,prcal)+1);
    return ret;
}

int main(){
    //freopen("myfile.txt","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;++i)
        scanf("%d",arr+i);
    scanf("%s",s);
    mp['R']=1;
    mp['G']=2;
    mp['B']=3;
    memset(mem,-1,sizeof mem);
    if(solve(m-1,k,0,0)==OO) printf("-1");
    else printf("%d",solve(m-1,k,0,0));
    return 0;
}

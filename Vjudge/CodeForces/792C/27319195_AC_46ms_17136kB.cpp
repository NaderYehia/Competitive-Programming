#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=1e5+5,M=1e9+7,SEGM=4*N,OO=0x3f3f3f3f;
int t,n;
char s[N];
int mem[N][3][5];

int solve(int i,int tk,int rem){
    if(i==n) return (rem==0&&tk)?0:OO;
    int &ret=mem[i][tk][rem];
    if(~ret) return ret;
    ret=1+solve(i+1,tk,rem);
    if(tk||s[i]!='0'){
        int nxt=rem*10+(s[i]-'0');
        ret=min(ret,solve(i+1,1,nxt%3));
    }
    return ret;
}

void dfs(int i,int tk,int rem){
    if(i==n) return;
    int ret=mem[i][tk][rem];
    if(ret==1+solve(i+1,tk,rem)){
        dfs(i+1,tk,rem);
    }
    else{
        printf("%c",s[i]);
        int nxt=rem*10+(s[i]-'0');
        dfs(i+1,1,nxt%3);
    }
}

int main(){
    //freopen("myfile.txt","w",stdout);
    scanf("%s",s);
    bool hasZero=0;n=strlen(s);
    for(int i=0;s[i];++i)
        hasZero|=(s[i]=='0');
    memset(mem,-1,sizeof mem);
    int ans=solve(0,0,0);
    if(ans>=OO) printf("%d",hasZero?0:-1);
    else dfs(0,0,0);
    return 0;
}

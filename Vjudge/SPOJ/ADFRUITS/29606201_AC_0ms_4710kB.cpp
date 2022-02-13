#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e2+10,M=2e4+7,OO=0x3f3f3f3f;

char s[N],t[N];
int mem[N][N],lens,lent;

int solve(int i,int j){
    if(i==lens) return lent-j;
    if(j==lent) return lens-i;
    int &ret=mem[i][j];
    if(~ret) return ret;
    ret=solve(i+1,j+1)+(s[i]==t[j]?1:2);
    ret=min(ret,min(solve(i+1,j)+1,solve(i,j+1)+1));
    return ret;
}

void dfs(int i,int j){
    if(i==lens){
        for(int p=j;p<lent;++p)
            printf("%c",t[p]);
        return;
    }
    if(j==lent){
        for(int p=i;p<lens;++p)
            printf("%c",s[p]);
        return;
    }
    int ret=solve(i,j);
    if(ret==solve(i+1,j+1)+(s[i]==t[j]?1:2)){
        if(s[i]==t[j])
            printf("%c",s[i]);
        else
            printf("%c%c",s[i],t[j]);
        dfs(i+1,j+1);
        return;
    }
    if(ret==solve(i+1,j)+1){
        printf("%c",s[i]);
        dfs(i+1,j);
        return;
    }
    printf("%c",t[j]);
    dfs(i,j+1);
}

int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    while(~scanf("%s%s",s,t)){
        lens=strlen(s);
        lent=strlen(t);
        memset(mem,-1,sizeof mem);
        dfs(0,0);
        puts("");
    }


    return 0;
}

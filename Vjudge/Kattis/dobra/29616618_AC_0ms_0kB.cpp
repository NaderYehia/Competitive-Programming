#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=2e2+10,M=2e4+7,OO=0x3f3f3f3f;

int n;
char s[N];
ll mem[N][3][3][3];

bool con(char c){
    return c=='A'||c=='E'||c=='I'||c=='O'||c=='U';
}

ll solve(int i,int bk,int bbk,int putL){
    if(i==n) return putL;
    ll &ret=mem[i][bk][bbk][putL];
    if(~ret) return ret;
    if(s[i]!='_'){
        if(con(s[i])==1&&bk==1&&bbk==1) return 0;
        if(con(s[i])==0&&bk==0&&bbk==0) return 0;
        return solve(i+1,con(s[i]),bk,putL|(s[i]=='L'));
    }
    ret=0;
    for(int j=0;j<26;++j){
        char cur=char('A'+j);
        if(con(cur)==1&&bk==1&&bbk==1) continue;
        if(con(cur)==0&&bk==0&&bbk==0) continue;
        ret+=solve(i+1,con(cur),bk,putL|(cur=='L'));
    }
    return ret;
}

int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    scanf("%s",s);
    n=strlen(s);
    memset(mem,-1,sizeof mem);
    printf("%lld\n",solve(0,2,2,0));

    return 0;
}

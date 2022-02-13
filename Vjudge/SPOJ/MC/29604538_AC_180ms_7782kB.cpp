#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e3+10,M=2e4+7,OO=0x3f3f3f3f;

char s[N],t[N];

int mem[N][N];

int solve(int i,int j){
    if(i==-1) return (j+1)*30;
    if(j==-1) return (i+1)*15;
    int &ret=mem[i][j];
    if(~ret) return ret;
    ret=solve(i-1,j-1)+(s[i]==t[j]?0:45);
    ret=min(ret,min(solve(i-1,j)+15,solve(i,j-1)+30));
    return ret;
}

int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);


    while(~scanf("%s",s),s[0]!='#'){
        scanf("%s",t);

        memset(mem,-1,sizeof mem);
        printf("%d\n",solve(strlen(s)-1,strlen(t)-1));

    }

    return 0;
}

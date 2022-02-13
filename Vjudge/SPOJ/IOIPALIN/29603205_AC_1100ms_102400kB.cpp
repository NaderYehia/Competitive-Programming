#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=5e3+10,M=2e4+7,OO=0x3f3f3f3f;

char s[N];

int mem[N][N];

int solve(int i,int j){
    if(i>=j) return 0;
    int &ret=mem[i][j];
    if(~ret) return ret;
    if(s[i]==s[j]) return solve(i+1,j-1);
    ret=min(solve(i+1,j),solve(i,j-1))+1;
    return ret;
}

int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    int n;
    scanf("%d",&n);
    scanf("%s",s);

    memset(mem,-1,sizeof mem);
    printf("%d\n",solve(0,n-1));

    return 0;
}
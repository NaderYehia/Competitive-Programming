#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=1e4+5,M=1e9+7,SEGM=4*N,OO=0x3f3f3f3f;
int t,n,m;
string s1,s2;
int mem[105][105];

int solve(int i=0,int j=0){
    if(i>=s1.length()||j>=s2.length()) return 0;
    int &ret=mem[i][j];
    if(~ret) return mem[i][j];
    if(s1[i]==s2[j]) return 1+solve(i+1,j+1);
    ret=max(solve(i+1,j),solve(i,j+1));
    return ret;
}

int main(){
    //freopen("myfile.txt","w",stdout);
    int tc=1;
    while(getline(cin,s1)&&getline(cin,s2)){
        memset(mem,-1,sizeof mem);
        printf("Case #%d: you can visit at most %d cities.\n",tc++,solve());
    }
    return 0;
}

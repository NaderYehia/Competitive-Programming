#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=1e3+5,M=1e9+7,SEGM=4*N,OO=0x3f3f3f3f;
int t,n,m;
string s;
ll mem[100][100];


ll solve(int i,int j){
    if(i==j) return 1;
    if(j<i) return 0;
    ll &ret=mem[i][j];
    if(~ret) return ret;
    if(s[i]==s[j]) ret=1+solve(i+1,j-1)+solve(i+1,j)+solve(i,j-1)-solve(i+1,j-1);
    else ret=solve(i+1,j)+solve(i,j-1)-solve(i+1,j-1);
    return ret;
}

int main(){
    //freopen("myfile.txt","w",stdout);
    scanf("%d\n",&t);
    while(t--){
        getline(cin,s);
        memset(mem,-1,sizeof mem);
        printf("%lld\n",solve(0,s.length()-1));
    }
    return 0;
}

#include<bits/stdc++.h>

using namespace std;

const int N=1e5;
int t,n;
string s;
int mem[1001][1001];

int solve(int i,int j){
    if(i>=j) return 0;
    if(mem[i][j]!=-1) return mem[i][j];
    if(s[i]==s[j])
        return solve(i+1,j-1);
    int op1=solve(i+1,j)+1;
    int op2=solve(i,j-1)+1;
    int op3=solve(i+1,j-1)+1;
    return mem[i][j]=min(op1,min(op2,op3));
}
int main() {
    int tc=1;
    scanf("%d\n",&t);
    while(t--){
        getline(cin,s);
        memset(mem,-1,sizeof mem);
        printf("Case %d: %d\n",tc++,solve(0,s.length()-1));
    }
    return 0;
}

#include<bits/stdc++.h>

using namespace std;

const int N=1e6+5;
int t,n,k;
int mem[1005][1005];
string s;

int solve(int i,int j){
    if(i>=j)
        return 0;
    if(mem[i][j]!=-1) return mem[i][j];
    if(s[i]==s[j])
        return solve(i+1,j-1);
    int op1=1+solve(i+1,j-1);
    int op2=1+solve(i,j-1);
    int op3=1+solve(i+1,j);
    return mem[i][j]=min(op1,min(op2,op3));
}

int main() {
    int c=1;
    scanf("%d\n",&t);
    while(t--){
        getline(cin,s);
        memset(mem,-1,sizeof mem);
        printf("Case %d: %d\n",c++,solve(0,s.length()-1));
    }
    return 0;
}

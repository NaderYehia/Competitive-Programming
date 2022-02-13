#include<bits/stdc++.h>

using namespace std;

const int N=2e5+5;
int n,k;
int mem[1005][1005];
string s1,s2;

int solve(int i,int j){
    if(i==s1.length()||j==s2.length())
        return 0;
    if(mem[i][j]!=-1) return mem[i][j];
    if(s1[i]==s2[j])
        return 1+solve(i+1,j+1);
    int op1=solve(i+1,j);
    int op2=solve(i,j+1);
    return mem[i][j]=max(op1,op2);
}

int main() {
    while(getline(cin,s1)&&getline(cin,s2)){
        memset(mem,-1,sizeof mem);
        printf("%d\n",solve(0,0));
    }
    return 0;
}

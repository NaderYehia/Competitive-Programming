#include<bits/stdc++.h>

using namespace std;

const int N=1e6+5;
int t,n,k;
int mem[1005][1005];
string s;

int solve(int i,int j){
    if(i>j)
        return 0;
    if(i==j)
        return 1;
    if(mem[i][j]!=-1) return mem[i][j];
    int ret=0;
    if(s[i]==s[j])
        ret=2+solve(i+1,j-1);
    else
        ret=max(solve(i+1,j),solve(i,j-1));
    return mem[i][j]=ret;
}

int main() {
    scanf("%d",&t);
    cin.ignore();
    while(t--){
        getline(cin,s);
        memset(mem,-1,sizeof mem);
        printf("%d\n",solve(0,s.length()-1));
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

const int N=1e3+10;

string s,t;

int mem[N][N];

int solve(int i,int j){
    if(i==s.length()||j==t.length()) return 0;

    if(mem[i][j]!=-1) return mem[i][j];

    if(s[i]==t[j]) return 1+solve(i+1,j+1);

    int op1=solve(i+1,j);

    int op2=solve(i,j+1);

    return mem[i][j]=max(op1,op2);

}


int main()
{

    while(getline(cin,s)&&getline(cin,t)){

        memset(mem,-1,sizeof mem);
        printf("%d\n",solve(0,0));
    }

    return 0;
}

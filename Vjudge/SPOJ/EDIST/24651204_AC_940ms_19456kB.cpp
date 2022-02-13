#include<bits/stdc++.h>

using namespace std;

int mem[2005][2005];
string a,b;

int solve(int i,int j){
    if(i==a.length())   return b.length()-j;
    if(j==b.length())   return a.length()-i;
    if(mem[i][j]!=-1) return mem[i][j];
    if(a[i]==b[j])  return mem[i][j]=solve(i+1,j+1);
    return mem[i][j]=min(1+solve(i+1,j),min(1+solve(i,j+1),1+solve(i+1,j+1)));
}

int main() {
    int t;scanf("%d",&t);
    while(t--){
        cin>>a>>b;
        memset(mem,-1,sizeof mem);
        printf("%d\n",solve(0,0));
    }
	return 0;
}

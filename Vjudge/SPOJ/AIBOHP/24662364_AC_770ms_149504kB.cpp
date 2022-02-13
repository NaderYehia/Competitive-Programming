#include<bits/stdc++.h>

using namespace std;

int mem[6101][6101];
string a;

int solve(int i,int j){
    if(i>=j)    return 0;
    if(mem[i][j]!=-1) return mem[i][j];
    if(a[i]==a[j])  return mem[i][j]=solve(i+1,j-1);
    return mem[i][j]=min(1+solve(i+1,j),1+solve(i,j-1));
}

int main() {
    int t;scanf("%d",&t);
    while(t--){
        cin>>a;
        memset(mem,-1,sizeof mem);
        printf("%d\n",solve(0,a.length()-1));
    }
	return 0;
}

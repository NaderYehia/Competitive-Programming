#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=2e3+5,M=1e9+7,SEGM=4*N,OO=0x3f3f3f3f;
int t,n,arr[N];
int mem[N][N];

int solve(int i,int j){
    if(i>j) return 0;
    int &ret=mem[i][j];
    if(~ret) return ret;
    int a=n-j+i;
    ret=max(solve(i+1,j)+a*arr[i],solve(i,j-1)+a*arr[j]);
    return ret;
}

int main(){
    //freopen("myfile.txt","w",stdout);
    scanf("%d\n",&n);
    for(int i=0;i<n;++i)
        scanf("%d",arr+i);
    memset(mem,-1,sizeof mem);
    printf("%d",solve(0,n-1));
    return 0;
}

#include<bits/stdc++.h>

using namespace std;

const int N=2e5+5;
int t,n,s;
int arr[20];
int mem[50][721];

bool solve(int i,int deg){
    if(i==n){
        if(deg==0)
            return 1;
        return 0;
    }
    if(mem[i][deg]!=-1) return mem[i][deg];
    return mem[i][deg]=solve(i+1,(deg+arr[i]))%360||solve(i+1,(deg-arr[i]+360)%360);
}

int main() {
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",arr+i);
    memset(mem,-1,sizeof mem);
    if(solve(0,0))
        printf("YES");
    else
        printf("NO");
    return 0;
}

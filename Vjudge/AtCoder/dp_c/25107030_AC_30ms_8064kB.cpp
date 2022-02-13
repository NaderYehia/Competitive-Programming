#include<bits/stdc++.h>

using namespace std;

const int N=1e5;
int n;
int a[N],b[N],c[N];
int mem[N][5];

int solve(int i,int lst){
    if(i==n)
        return 0;
    if(mem[i][lst]!=-1) return mem[i][lst];
    int op1=lst!=0?solve(i+1,0)+a[i]:-1000000000;
    int op2=lst!=1?solve(i+1,1)+b[i]:-1000000000;
    int op3=lst!=2?solve(i+1,2)+c[i]:-1000000000;
    return mem[i][lst]=max(op1,max(op2,op3));
}

int main() {
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d%d%d",a+i,b+i,c+i);
    memset(mem,-1,sizeof mem);
    printf("%d",max(solve(0,0),max(solve(0,1),solve(0,2))));
    return 0;
}

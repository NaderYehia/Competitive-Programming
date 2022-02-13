#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=2e3+5,M=1e9+7,OO=0x3f3f3f3f;
const double eps=1e-6,pi=acos(-1);
int t,n,q,d,m;
int arr[205];
int mem[205][25][15][2];

int solve(int i,int sum,int picked,int tkn){
    if(picked==m) return (tkn&&(sum==0));
    if(i==n) return 0;
    int &ret=mem[i][sum][picked][tkn];
    if(~ret) return ret;
    int op1=solve(i+1,sum,picked,tkn);
    int op2=solve(i+1,((sum+arr[i])%d+d)%d,picked+1,1);
    ret=op1+op2;
    return ret;
}

int main(){
    //freopen("myfile.txt","w",stdout);
    int tc=1;
    while(~scanf("%d%d",&n,&q),(n+q)){
        printf("SET %d:\n",tc++);
        for(int i=0;i<n;++i)
            scanf("%d",arr+i);
        int qc=1;
        while(q--){
            memset(mem,-1,sizeof mem);
            scanf("%d%d",&d,&m);
            printf("QUERY %d: %d\n",qc++,solve(0,0,0,0));
        }
    }
    return 0;
}

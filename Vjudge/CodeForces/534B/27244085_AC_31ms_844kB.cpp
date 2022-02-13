#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=1e2+5,M=1e9+7,SEGM=4*N,OO=0x3f3f3f3f;
int t,n,m,v1,v2;
int mem[105][2005];


int main(){
    //freopen("myfile.txt","w",stdout);
    scanf("%d%d%d%d",&v1,&v2,&n,&m);
    if(v1>v2) swap(v1,v2);
    memset(mem,-OO,sizeof mem);
    mem[0][v1]=v1;
    for(int i=1;i<n;++i){
        for(int cur=v1;cur<2005;++cur){
            for(int j=0;j<=m;++j){
                if(cur+j<2005) mem[i][cur+j]=max(mem[i][cur+j],cur+j+mem[i-1][cur]);
                if(cur-j>-1)   mem[i][cur-j]=max(mem[i][cur-j],cur-j+mem[i-1][cur]);
            }
        }
    }
    cout<<mem[n-1][v2];
    return 0;
}

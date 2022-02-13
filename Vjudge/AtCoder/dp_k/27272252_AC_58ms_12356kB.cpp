#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=1e5+5,M=1e9+7,SEGM=4*N,OO=0x3f3f3f3f;
int t,n,m,k;
int a[N];
int mem[N][2];

int solve(int rem,bool p){
    if(rem==0) return !p;
    int &ret=mem[rem][p];
    if(~ret) return ret;
    ret=!p;
    for(int i=0;i<n;++i){
        if(rem-a[i]>=0){
            if(solve(rem-a[i],!p)==p){
                ret=p;
                break;
            }
        }
    }
    return ret;
}

int main(){
    //freopen("myfile.txt","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;++i)
        scanf("%d",a+i);
    memset(mem,-1,sizeof mem);
    if(!solve(k,0)) printf("First\n");
    else printf("Second\n");
    return 0;
}

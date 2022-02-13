#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=1e5+5,M=1e9+7,SEGM=4*N,OO=0x3f3f3f3f;
int n,m,a[30];
int mem[105];


int main(){
    //freopen("myfile.txt","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",a+i);
    memset(mem,-1,sizeof mem);
    int ans=1;
    for(int i=0;i<n;++i){
        int ret=1;
        for(int j=0;j<i;++j)
            if(a[i]>a[j])
                ret=max(ret,mem[j]+1);
        mem[i]=ret;
        ans=max(ans,ret);
    }
    printf("%d",ans);
    return 0;
}

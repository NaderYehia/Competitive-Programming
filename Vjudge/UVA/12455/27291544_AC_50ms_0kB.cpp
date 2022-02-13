#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=1e5+5,M=1e9+7,SEGM=4*N,OO=0x3f3f3f3f;
int t,n,sum,a[30];

int main(){
    //freopen("myfile.txt","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&sum,&n);
        for(int i=0;i<n;++i)
            scanf("%d",a+i);
        bool found=0;
        for(int i=0;i<(1<<n);++i){
            int x=0;
            for(int j=0;j<n;++j){
                if(i&(1<<j)){
                    x+=a[j];
                }
            }
            if(x==sum)
                found=1;
        }
        if(found) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}

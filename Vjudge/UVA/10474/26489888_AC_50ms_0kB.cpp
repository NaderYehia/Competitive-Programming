#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e4+5,OO=0x3f3f3f3f;
const double eps=1e-6,pi=3.14159265359;
int t,n,m,q;
int arr[N];


int main(){
    //freopen("myfile.txt","w",stdout);
    int tc=1;
    while(scanf("%d%d",&n,&q),(n+q)){
        printf("CASE# %d:\n",tc++);
        for(int i=0;i<n;++i)
            scanf("%d",arr+i);
        sort(arr,arr+n);
        while(q--){
            int tmp;scanf("%d",&tmp);
            int idx=lower_bound(arr,arr+n,tmp)-arr;
            if(arr[idx]==tmp) printf("%d found at %d\n",tmp,idx+1);
            else printf("%d not found\n",tmp);
        }
    }
    return 0;
}

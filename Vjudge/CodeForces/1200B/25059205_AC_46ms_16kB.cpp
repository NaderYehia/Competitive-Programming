#include<bits/stdc++.h>

using namespace std;

const int N=2e5+5;
int t,n,m,k;
int arr[200];


int main() {
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&m,&k);
        for(int i=0;i<n;++i)
            scanf("%d",arr+i);
        int i;
        for(i=1;i<n;++i){
            int ed=arr[i]-k;
            ed=max(0,ed);
            m+=arr[i-1]-ed;
            if(m<0){
                break;
            }
        }
        if(i==n)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

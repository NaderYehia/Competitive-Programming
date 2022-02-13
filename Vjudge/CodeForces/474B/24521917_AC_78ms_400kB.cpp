#include<bits/stdc++.h>

using namespace std;

int t,k,n,m,cows;
int arr[100006];

int main() {
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",arr+i);
    for(int i=1;i<n;++i)
        arr[i]+=arr[i-1];
    scanf("%d",&m);
    while(m--){
        scanf("%d",&k);
        printf("%d\n",lower_bound(arr,arr+n,k)-arr+1);
    }
	return 0;
}

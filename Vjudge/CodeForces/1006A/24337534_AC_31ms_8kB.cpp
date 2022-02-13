#include<bits/stdc++.h>

using namespace std;

const int N=2e5+5;
int t,n,k;

int main() {
	scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&k);
        if(k&1)
            printf("%d ",k);
        else
            printf("%d ",k-1);
    }
	return 0;
}

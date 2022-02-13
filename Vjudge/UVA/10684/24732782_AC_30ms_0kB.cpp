#include<bits/stdc++.h>

using namespace std;

int n;
int arr[200005];

int main() {
    while(scanf("%d",&n),n){
        for(int i=0;i<n;++i)
            scanf("%d",arr+i);
        int mx=0,mxhere=0;
        for(int i=0;i<n;++i){
            mxhere+=arr[i];
            mx=max(mx,mxhere);
            if(mxhere<0)
                mxhere=0;
        }
        if(mx)
            printf("The maximum winning streak is %d.\n",mx);
        else
            printf("Losing streak.\n");
    }
	return 0;
}

#include<bits/stdc++.h>

using namespace std;

const int N=2e3+5;
int t,n,m;
int arr[16];

int main() {
    while(~scanf("%d",&n),n){
        if(t)
           printf("\n");
        ++t;
        for(int i=0;i<n;++i)
            scanf("%d",arr+i);
        for(int i=0;i<n-5;++i){
            for(int j=i+1;j<n-4;++j){
                for(int k=j+1;k<n-3;++k){
                    for(int u=k+1;u<n-2;++u){
                        for(int w=u+1;w<n-1;++w){
                            for(int l=w+1;l<n;++l){
                                printf("%d %d %d %d %d %d\n",arr[i],arr[j],arr[k],arr[u],arr[w],arr[l]);
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}

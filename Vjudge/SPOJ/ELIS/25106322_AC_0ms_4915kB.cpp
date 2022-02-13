#include<bits/stdc++.h>

using namespace std;

int n,W;
int arr[100];
int mem[100];


int main() {
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",arr+i);
    memset(mem,-1,sizeof mem);
    for(int i=0;i<n;++i){
        int ret=1;
        for(int j=0;j<i;++j){
            if(arr[j]<arr[i]){
                ret=max(ret,1+mem[j]);
            }
        }
        mem[i]=ret;
    }
    printf("%d",*max_element(mem,mem+n));
    return 0;
}

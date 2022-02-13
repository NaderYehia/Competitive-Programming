#include<bits/stdc++.h>

using namespace std;

int arr[10005];

int main(){
    int i=0,x;
    while(~scanf("%d",arr+i++)){
        sort(arr,arr+i);
        if(i&1)
            printf("%d\n",arr[i/2]);
        else
            printf("%d\n",(arr[i/2]+arr[i/2-1])/2);
    }
    return 0;
}

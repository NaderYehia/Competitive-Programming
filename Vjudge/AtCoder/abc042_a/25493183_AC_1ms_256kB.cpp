#include<bits/stdc++.h>

using namespace std;

const int N=2e5+5,OO=0x3f3f3f3f,M=1e9+7;
int t,n,m,k;


int main() {
    int arr[5];
    scanf("%d%d%d",&arr[0],&arr[1],&arr[2]);
    sort(arr,arr+3);
    if(arr[0]==5&&arr[1]==5&&arr[2]==7)
        printf("YES");
    else
        printf("NO");
    return 0;
}

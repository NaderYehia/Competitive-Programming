#include<bits/stdc++.h>

using namespace std;

const int N=2e5+5;
int t,n,c;
int arr[N];


int main() {
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",arr+i);
    int cnt=1,mx=1,lst=0;
    for(int i=0;i<n;++i){
        if(lst*2>=arr[i])
            ++cnt,mx=max(mx,cnt);
        else
            cnt=1;
        lst=arr[i];
    }
    printf("%d",mx);
    return 0;
}

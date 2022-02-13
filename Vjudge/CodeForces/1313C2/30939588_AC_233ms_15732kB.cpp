#include <bits/stdc++.h>

using namespace std;

const int N=5e5+10;

int arr[N];
long long ltr[N],rtl[N];



int main(){

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",arr+i);

    stack<int> temp;
    for(int i=0;i<n;++i){
        while(!temp.empty()&&arr[temp.top()]>arr[i]) temp.pop();
        if(temp.empty()) ltr[i]=(i+1)*arr[i];
        else ltr[i]=ltr[temp.top()]+(i-temp.top())*1ll*arr[i];
        temp.push(i);
    }
    while(!temp.empty()) temp.pop();
    for(int i=n-1;~i;--i){
        while(!temp.empty()&&arr[temp.top()]>arr[i]) temp.pop();
        if(temp.empty()) rtl[i]=(n-i)*arr[i];
        else rtl[i]=rtl[temp.top()]+(temp.top()-i)*1ll*arr[i];
        temp.push(i);
    }

    long long best=-1,idx=-1;
    for(int i=0;i<n;++i){
        if(best<ltr[i]+rtl[i]-arr[i]){
            best=ltr[i]+rtl[i]-arr[i];
            idx=i;
        }
    }

    for(int i=idx-1;~i;--i)
        if(arr[i]>arr[i+1]) arr[i]=arr[i+1];
    for(int i=idx+1;i<n;++i)
        if(arr[i]>arr[i-1]) arr[i]=arr[i-1];
    for(int i=0;i<n;++i) printf("%d ",arr[i]);

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

const int N=1<<20;

int arr[N],ltrMax[N],ltrMin[N],rtlMax[N],rtlMin[N];

int main(){

    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",arr+i);
        
    stack<int> monoMax;
    stack<int> monoMin;
    
    for(int i=0;i<n;++i){
        while(!monoMax.empty()&&arr[monoMax.top()]<arr[i]) monoMax.pop();
        if(monoMax.empty()) ltrMax[i]=-1;
        else ltrMax[i]=monoMax.top();
        monoMax.push(i);
        while(!monoMin.empty()&&arr[monoMin.top()]>arr[i]) monoMin.pop();
        if(monoMin.empty()) ltrMin[i]=-1;
        else ltrMin[i]=monoMin.top();
        monoMin.push(i);
    }
    
    while(monoMax.size()) monoMax.pop();
    while(monoMin.size()) monoMin.pop();
    
    for(int i=n-1;~i;--i){
        while(!monoMax.empty()&&arr[monoMax.top()]<=arr[i]) monoMax.pop();
        if(monoMax.empty()) rtlMax[i]=n;
        else rtlMax[i]=monoMax.top();
        monoMax.push(i);
        while(!monoMin.empty()&&arr[monoMin.top()]>=arr[i]) monoMin.pop();
        if(monoMin.empty()) rtlMin[i]=n;
        else rtlMin[i]=monoMin.top();
        monoMin.push(i);
    }
    
    long long sumMax=0,sumMin=0;
    
    for(int i=0;i<n;++i){
        int lf=i-ltrMin[i],rt=rtlMin[i]-i;
        sumMin+=(lf*1ll*rt)*arr[i];
        lf=i-ltrMax[i],rt=rtlMax[i]-i;
        sumMax+=(lf*1ll*rt)*arr[i];
    }
    
    printf("%lld\n",sumMax-sumMin);
    
    return 0;
}

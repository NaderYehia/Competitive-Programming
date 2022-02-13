#include<bits/stdc++.h>

using namespace std;

const int N = 2e5+6,M=1e9+7;

int n,k,sum;
int a[N];
int b[N];
set<pair<int,int> >v;

int main(){
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;++i)
        scanf("%d",a+i);
    for(int i=0;i<n;++i)
        scanf("%d",b+i);
    for(int i=0;i<n;++i)
        v.insert({a[i]-b[i],i});
    for(pair<int,int> p : v){
        if(k)
            sum+=a[p.second],--k;
        else
            sum+=min(a[p.second],b[p.second]);
    }
    printf("%d",sum);
    return 0;
}

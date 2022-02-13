#include<bits/stdc++.h>

using namespace std;

const int N = 2e5+6,M=1e9+7;

int n,k,boo,sum;
int a[N];
int b[N];
set<pair<int,int> >v;

int main(){
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;++i){
        scanf("%d",&boo);
        boo>k?sum+=2:sum+=1;
    }
    printf("%d",sum);
    return 0;
}

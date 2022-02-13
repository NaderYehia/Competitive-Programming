#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=2e5+5,M=1e9+7,OO=0x3f3f3f3f;
int t,n,m,k;
int cities[N];
int towers[N];

bool can(int x){
    int coverdUntill=-2e9,j=0,i=0;
    while(i<n&&j<m){
        if(cities[i]>=towers[j]-x&&cities[i]<=towers[j]+x) ++i;
        else ++j;
    }
    return i==n&&j<m;
}

int main(){
    //freopen("myfile.txt","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)
        scanf("%d",cities+i);
    for(int i=0;i<m;++i)
        scanf("%d",towers+i);
    int lo=0,hi=2e9,mid;
    while(lo<hi){
        mid=lo+(hi-lo)/2;
        if(can(mid)) hi=mid;
        else lo=mid+1;
    }
    printf("%d",lo);
    return 0;
}

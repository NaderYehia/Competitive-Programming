#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e4+5,OO=0x3f3f3f3f;
const double eps=1e-6,pi=3.14159265359;
int t,n,m,f;
int arr[N];

bool can(double x){
    int cnt=0;
    for(int i=0;i<n;++i){
        double ar=pi*arr[i]*arr[i];
        cnt+=ar/x;
    }
    return cnt>=f;
}

double bs(){
    double lo=0,hi=10000*10000*pi,mid;
    while(hi-lo>eps){
        mid=(lo+hi)/2;
        if(can(mid)) lo=mid;
        else hi=mid;
    }
    return lo;
}

int main(){
    //freopen("myfile.txt","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&f);++f;
        for(int i=0;i<n;++i)
            scanf("%d",arr+i);
        printf("%.4f\n",bs());
    }
    return 0;
}
#include<bits/stdc++.h>

using namespace std;

int n;
int homes[200005];

bool can(long long d){
    long long mxvis=0,sta=3;
    for(int i=0;i<n;++i){
        if(homes[i]>mxvis){
            if(sta<1)
                return false;
            mxvis=homes[i]+2*d;
            --sta;
        }
    }
    return true;
}

long long bs(){
    long long lo=0,hi=2000000005,mid;
    while(lo<hi){
        mid=(lo+hi)/2;
        if(can(mid))
            hi=mid;
        else
            lo=mid+1;
    }
    return lo;
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",homes+i),homes[i]*=2;
    sort(homes,homes+n);
    long long d=bs();
    printf("%6f\n",(double)d/2);
    int mxvis=0,sta=3;
    for(int i=0;i<n;++i){
        if(homes[i]>mxvis&&sta){
            printf("%6f ",(double)(homes[i]+d)/2),--sta,mxvis=homes[i]+2*d;
        }
    }
    while(sta)
        printf("%6f ",(double)homes[n-1]),--sta;
    return 0;
}

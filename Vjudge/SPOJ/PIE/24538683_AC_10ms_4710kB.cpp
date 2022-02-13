#include<bits/stdc++.h>

using namespace std;

int t,n,f;
int arr[10005];
double pi=3.14159265359;

bool can(double x){
    int tmp=f+1;
    for(int i=0;i<n;++i){
        double pie=arr[i]*arr[i]*pi;
        tmp-=(int)(pie/x);
    }
    if(tmp>0)
        return 0;
    return 1;
}

double bs(){
    double lo=0,hi=100005*100005*pi,mid;
    while(hi-lo>=1e-6){
        mid=(lo+hi)/2;
        if(can(mid))
            lo=mid;
        else
            hi=mid;
    }
    return lo;
}


int main() {
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&f);
        for(int i=0;i<n;++i)
            scanf("%d",arr+i);
        printf("%.4f\n",bs());
    }
	return 0;
}

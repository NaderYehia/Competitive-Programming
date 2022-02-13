#include<bits/stdc++.h>

using namespace std;

double E=2.71828182845904523536;
double PI=3.14159265358979323846;

int n,m,mx;
int arr[1005];


bool can(int x){
    int tmp=m,cont=-1;
    for(int i=0;i<n;++i){
        if(arr[i]>x) return 0;
        if(arr[i]>cont){
            --tmp;
            cont=x-arr[i];
        } else{
            cont-=arr[i];
        }
    }
    if(tmp<0)
        return 0;
    return 1;
}

int bs(){
    int lo=1,hi=1000000000,mid;
    while(hi-lo>0){
        mid=(hi+lo)/2;
        if(can(mid))
            hi=mid;
        else
            lo=mid+1;
    }
    return lo;
}

int main() {
    while(~scanf("%d%d",&n,&m)){
        for(int i=0;i<n;++i)
            scanf("%d",arr+i);
        printf("%d\n",bs());
    }
	return 0;
}

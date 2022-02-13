#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=2e5+5,M=1e9+7,OO=0x3f3f3f3f;

int arr[10];

bool solve(int sum,int msk){
    if(msk==(1<<5)-1){
        return sum==23;
    }
    bool ret=0;
    for(int i=0;i<5;++i){
        if((1<<i)&msk) continue;
        msk|=(1<<i);
        bool op1=solve(sum*arr[i],msk);
        bool op2=solve(sum+arr[i],msk);
        bool op3=solve(sum-arr[i],msk);
        msk&=~(1<<i);
        ret|=op1|op2|op3;
    }
    return ret;
}

int main(){

    //freopen("myfile.txt","w",stdout);

    while(1){
        bool ter=1;
        for(int i=0;i<5;++i){
            scanf("%d",arr+i);
            if(arr[i]>0) ter=0;
        }
        if(ter) break;
        bool ret=0;
        for(int i=0;i<5;++i)
            ret|=solve(arr[i],1<<i);
        if(ret) printf("Possible\n");
        else printf("Impossible\n");

    }

    return 0;
}

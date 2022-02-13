#include<bits/stdc++.h>

using namespace std;

const int N = 1e3+6,M=1e9+7,OO=0x3f3f3f3f;

int t,n,m,k,sum;
int arr[10][10];
bool ex[10][10];

bool vvalid(int i,int j){
    return i>-1&&j>-1&&i<8&&j<8;
}

bool valid(int i,int j){
    for(int h=i-1,c=1;h>-1;--h,++c){
        if(ex[h][j])
            return false;
        if(vvalid(h,j+c)&&ex[h][j+c])
            return false;
        if(vvalid(h,j-c)&&ex[h][j-c])
            return false;
    }
    return true;
}

void solve(int i){
    if(i==8){
        sum=max(sum,k);
        return;
    }
    for(int j=0;j<8;++j){
        if(valid(i,j)){
            k+=arr[i][j];
            ex[i][j]=1;
            solve(i+1);
            k-=arr[i][j];
            ex[i][j]=0;
        }
    }
}

int main(){
    scanf("%d",&t);
    while(t--){
        for(int i=0;i<8;++i)
            for(int j=0;j<8;++j)
                scanf("%d",&arr[i][j]);
        memset(ex,0,sizeof ex);
        sum=0;
        solve(0);
        printf("%5d\n",sum);
    }
    return 0;
}

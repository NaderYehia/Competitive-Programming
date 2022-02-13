#include<bits/stdc++.h>

using namespace std;

const int N=2e5+5,OO=0x3f3f3f3f,M=1e9+7;
int t,n,m,k;
int forb[15];

bool cool(int x){
    while(x){
        if(forb[x%10])
            return 0;
        x/=10;
    }
    return 1;
}

int main() {
    cin>>n>>k;
    for(int i=0,a;i<k;++i)
        scanf("%d",&a),++forb[a];
    for(int i=n;;++i){
        if(cool(i)){
            cout<<i;
            return 0;
        }
    }
    return 0;
}

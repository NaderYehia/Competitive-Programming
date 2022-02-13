#include<bits/stdc++.h>

using namespace std;

const int N=1e4+5,OO=0x3f3f3f3f,M=1e9+7;
int t,n,k;
int d[N];

int main() {
    scanf("%d",&n);
    for(int i=0,a;i<n;++i)
        scanf("%d",&a),++d[a];
    int mx=1;
    for(int i=1;i<N;++i){
        if(d[i])
            mx=max(mx,i);
    }
    cout<<mx<<" ";
    --d[1],--d[mx];
    for(int i=2;i<=mx/i;++i){
        if(mx%i==0){
            --d[i];
            if(mx/i!=i)
                --d[mx/i];
        }
    }
    mx=1;
    for(int i=1;i<N;++i)
        if(d[i])
            mx=max(mx,i);
    cout<<mx;
    return 0;
}

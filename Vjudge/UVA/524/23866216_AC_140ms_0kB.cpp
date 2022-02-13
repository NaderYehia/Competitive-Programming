#include<bits/stdc++.h>

using namespace std;

const int N = 1e3+6,M=1e9+7,OO=0x3f3f3f3f;

int t,n,m,k,sum;
bitset<500>isPrime;
int arr[15];
bool vis[20];
vector<int> v;

void print(){
    for(int i=0;i<v.size();++i)
        printf("%d%c",v[i]," \n"[i==v.size()-1]);
}

void solve(int i,int prev){
    if(i==n&&isPrime[prev+1])
        print();
    for(int in=2;in<=n;++in){
        if(!vis[in]&&isPrime[in+prev]){
            v.push_back(in);
            vis[in]=1;
            solve(i+1,in);
            v.pop_back();
            vis[in]=0;
        }
    }
}

void sieve(){
    isPrime.set();
    for(int i=2;i<=500/i;++i)
        if(isPrime[i])
            for(int j=i*i;j<=500;j+=i)
                isPrime[j]=0;
}

int main(){
    sieve();
    while(~scanf("%d",&n)){
        if(t!=0)
            puts("");
        printf("Case %d:\n",++t);
        memset(vis,0,sizeof vis);
        v.push_back(1);
        solve(1,1);
        v.pop_back();
    }
    return 0;
}

#include<bits/stdc++.h>

using namespace std;

int n,k;
bitset<50>isPrime;
int vis[20];
vector<int> v;

void sieve(){
    isPrime.set();
    isPrime[1]=0;
    for(int i=2;i<=50/i;++i){
        if(isPrime[i])
            for(int j=i*i;j<50;j+=i)
                isPrime[j]=0;
    }
}

bool allVis(){
    for(int i=1;i<=n;++i)
        if(!vis[i])
            return 0;
    return 1;
}

void print(){
    for(int i=0;i<v.size();++i)
        printf("%d%c",v[i]," \n"[i+1==v.size()]);
}

void solve(){
    if(allVis()){
        if(isPrime[v.back()+1])
            print();
        return;
    }
    for(int i=1;i<=n;++i){
        if(!vis[i]&&isPrime[i+v.back()]){
            v.push_back(i);
            vis[i]=1;
            solve();
            v.pop_back();
            vis[i]=0;
        }
    }
}

int main() {
    sieve();
    while(~scanf("%d",&n)){
        if(k)
            printf("\n");
        printf("Case %d:\n",++k);
        v.push_back(1);
        vis[1]=1;
        solve();
        v.pop_back();
        vis[1]=0;
    }
	return 0;
}

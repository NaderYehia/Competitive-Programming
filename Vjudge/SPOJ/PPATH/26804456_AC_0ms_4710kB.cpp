#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=1e5+5,M=1e9+7,OO=0x3f3f3f3f;
int t,n,m,k;
bitset<N> isPrime;
bool vis[N];

void sieve(){
    isPrime.set();
    isPrime[0]=isPrime[1]=0;
    for(int i=2;i<=N/i;++i){
        if(isPrime[i])
            for(int j=i*i;j<N;j+=i)
                isPrime[j]=0;
    }
}

int combine(int d1,int d2,int d3,int d4){
    return d4+d3*10+d2*100+d1*1000;
}

int bfs(int a,int b){
    queue<pair<int,int> > q;
    q.push({a,0});
    vis[a]=1;
    while(q.size()){
        int cur=q.front().first;
        int lvl=q.front().second;
        q.pop();
        if(cur==b) return lvl;
        int d4=cur%10; cur/=10;
        int d3=cur%10; cur/=10;
        int d2=cur%10; cur/=10;
        int d1=cur%10; cur/=10;
        for(int i=1;i<10;++i){
            int tmp=combine(i,d2,d3,d4);
            if(!vis[tmp]&&isPrime[tmp])
                q.push({tmp,lvl+1}),vis[tmp]=1;
        }
        for(int i=0;i<10;++i){
            int tmp=combine(d1,i,d3,d4);
            if(!vis[tmp]&&isPrime[tmp])
                q.push({tmp,lvl+1}),vis[tmp]=1;
        }
        for(int i=0;i<10;++i){
            int tmp=combine(d1,d2,i,d4);
            if(!vis[tmp]&&isPrime[tmp])
                q.push({tmp,lvl+1}),vis[tmp]=1;
        }
        for(int i=0;i<10;++i){
            int tmp=combine(d1,d2,d3,i);
            if(!vis[tmp]&&isPrime[tmp])
                q.push({tmp,lvl+1}),vis[tmp]=1;
        }
    }
    return -1;
}

int main(){
    //freopen("myfile.txt","w",stdout);
    sieve();
    scanf("%d\n",&t);
    while(t--){
        int a,b;
        memset(vis,0,sizeof vis);
        scanf("%d%d",&a,&b);
        printf("%d\n",bfs(a,b));
    }
    return 0;
}

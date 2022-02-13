#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const double eps=1e-6,pi=acos(-1);
const int N=1e5+5,M=1e9+7,OO=0x3f3f3f3f;
int t,n,m,k;
bitset<N> isPrime;
map<string,bool> mp;

void sieve(){
    isPrime.set();
    isPrime[0]=isPrime[1]=0;
    for(int i=2;i<=N/i;++i){
        if(isPrime[i])
            for(int j=i*i;j<N;j+=i)
                isPrime[j]=0;
    }
}

int toInt(string s){
    int ret=0;
    for(int i=0;s[i];++i)
        ret=ret*10+s[i]-'0';
    return ret;
}

int bfs(string a,string b){
    queue<pair<string,int> > q;
    q.push({a,0});
    while(q.size()){
        string cur=q.front().first;
        int lvl=q.front().second;
        q.pop();
        if(cur==b) return lvl;
        for(int i=0;i<4;++i){
            string tmp=cur;
            for(int j=0;j<10;++j){
                if(i==0&&j==0) continue;
                tmp[i]=(char)('0'+j);
                if(tmp==cur) continue;
                if(isPrime[toInt(tmp)]&&mp.find(tmp)==mp.end())
                    q.push({tmp,lvl+1}),mp[tmp]=1;
            }
        }
    }
    return -1;
}

int main(){
    //freopen("myfile.txt","w",stdout);
    sieve();
    scanf("%d\n",&t);
    while(t--){
        string a,b; mp.clear();
        cin>>a>>b;
        printf("%d\n",bfs(a,b));
    }
    return 0;
}

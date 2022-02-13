#include<bits/stdc++.h>

using namespace std;

const int N=1e3+5,OO=0x3f3f3f3f;
int t,n,m,k;
int dis[10000];

bitset<10000> isPrime;
void sieve(){
    isPrime.set();
    for(int i=2;i<10000/i;++i){
        if(isPrime[i])
            for(int j=i*i;j<10000;j+=i)
                isPrime[j]=0;
    }
}

int to_num(string s){
    int ret=0;
    for(int i=0;s[i];++i)
        ret=ret*10+s[i]-'0';
    return ret;
}

int bfs(int st,int en){
    memset(dis,-1,sizeof dis);
    queue<int> q;
    q.push(st);
    dis[st]=0;
    while(q.size()){
        int n=q.front();
        if(n==en)
            return dis[n];
        q.pop();
        string s=to_string(n);
        char ch=s[0];
        for(int i=1;i<10;++i){
            s[0]=(char)('0'+i);
            int nw=to_num(s);
            if(isPrime[nw]&&dis[nw]==-1){
                q.push(nw),dis[nw]=dis[n]+1;
            }
        }
        s[0]=ch;
        ch=s[1];
        for(int i=0;i<10;++i){
            s[1]=(char)('0'+i);
            int nw=to_num(s);
            if(isPrime[nw]&&dis[nw]==-1){
                q.push(nw),dis[nw]=dis[n]+1;
            }
        }
        s[1]=ch;
        ch=s[2];
        for(int i=0;i<10;++i){
            s[2]=(char)('0'+i);
            int nw=to_num(s);
            if(isPrime[nw]&&dis[nw]==-1){
                q.push(nw),dis[nw]=dis[n]+1;
            }
        }
        s[2]=ch;
        ch=s[3];
        for(int i=0;i<10;++i){
            s[3]=(char)('0'+i);
            int nw=to_num(s);
            if(isPrime[nw]&&dis[nw]==-1){
                q.push(nw),dis[nw]=dis[n]+1;
            }
        }
        s[3]=ch;
    }
    return -1;
}


int main() {
    sieve();
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        int ans=bfs(n,m);
        if(!~ans) printf("Impossible.\n");
        else printf("%d\n",ans);
    }
    return 0;
}

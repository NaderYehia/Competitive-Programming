#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=9e7+5,M=2e6+7,OO=0x3f3f3f3f;

bool prime[N];
vector<int> v;

void sieve(){
    fill(prime,prime+N,1);
    prime[0]=prime[1]=0;
    for(int i=2;i<N/i;++i){
        if(prime[i]){
            for(int j=i*i;j<N;j+=i)
                prime[j]=0;
        }
    }
    for(int i=0;i<N;++i){
        if(prime[i]) v.push_back(i);
    }
}

int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    sieve();

    int q;
    scanf("%d",&q);
    while(q--){
        int k;
        scanf("%d",&k);
        printf("%d\n",v[k-1]);
    }

    return 0;
}

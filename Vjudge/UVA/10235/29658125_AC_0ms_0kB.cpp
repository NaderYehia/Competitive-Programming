#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e6+10,M=1e3+7,OO=0x3f3f3f3f;


bool isPrime[N];

void sieve(){
    fill(isPrime,isPrime+N,1);
    isPrime[0]=0;
    for(int i=2;i<N/i;++i)
        if(isPrime[i])
            for(int j=i*i;j<N;j+=i)
                isPrime[j]=0;
}

int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    sieve();

    int n;
    while(~scanf("%d",&n)){
        int rev=0;
        int cur=n;
        while(cur){
            rev=rev*10+cur%10;
            cur/=10;
        }
        if(isPrime[n]&&isPrime[rev]&&n!=rev) printf("%d is emirp.\n",n);
        else if(isPrime[n]) printf("%d is prime.\n",n);
        else printf("%d is not prime.\n",n);
    }


    return 0;
}

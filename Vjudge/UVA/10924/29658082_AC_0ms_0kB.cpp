#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=2e3+10,M=1e3+7,OO=0x3f3f3f3f;


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

    string s;
    while(getline(cin,s)){
        int val=0;
        for(int i=0;s[i];++i){
            if(s[i]>='a'&&s[i]<='z')
                val+=s[i]-'a'+1;
            else
                val+=s[i]-'A'+27;
        }
        if(isPrime[val]) puts("It is a prime word.");
        else puts("It is not a prime word.");
    }


    return 0;
}

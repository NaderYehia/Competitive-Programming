#include<bits/stdc++.h>
using namespace std;

const long long N=2e3;
bitset<N> isP;
void sieve(){
	isP.set();
	isP[0]= 0;
	isP[1]=1;
	for(int p = 2 ; p <= N/p ; ++p)
            if(isP[p])
                for(int m = p*p ; m <  N; m += p)
                    isP[m] = 0;
}

int main(){
	char s[25];
	sieve();
	int sum;
	while(scanf("%s",s)==1){
	sum=0;
		for(int i=0;s[i];++i)
			sum+=s[i]>='a'&&s[i]<='z'?s[i]-'a'+1:s[i]-'A'+27;
		puts(isP[sum]?"It is a prime word.":"It is not a prime word.");
	}
}
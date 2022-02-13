#include<bits/stdc++.h>

using namespace std;

const int N=1e7+5;
char s[N];
int frq[30],n;

int main() {
	scanf("%d\n",&n);
	scanf("%s",s);
	for(int i=0;i<n;++i)
        ++frq[s[i]-'a'];
    for(int i=0;i<26;++i)
        while(frq[i]--)
            printf("%c",(char)('a'+i));
	return 0;
}

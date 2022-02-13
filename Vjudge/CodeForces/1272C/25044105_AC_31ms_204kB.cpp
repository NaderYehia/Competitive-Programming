#include<bits/stdc++.h>

using namespace std;

const int N=2e5+5;
int n,k;
char s[N];
int frq[30];

int main() {
    scanf("%d%d",&n,&k);
    scanf("%s",s);
    for(int i=0;i<k;++i){
        char a;
        cin>>a;
        ++frq[a-'a'];
    }
    int cnt=0;
    long long ans=0;
    for(int i=0;i<n;++i){
        if(frq[s[i]-'a']){
            ++cnt;
        }
        else{
            ans+=cnt*1ll*(cnt+1)/2;
            cnt=0;
        }
    }
    ans+=cnt*1ll*(cnt+1)/2;
    printf("%lld",ans);
    return 0;
}

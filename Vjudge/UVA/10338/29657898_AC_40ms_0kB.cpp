#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=2e3+10,M=1e3+7,OO=0x3f3f3f3f;



int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    int n,tc=1;
    scanf("%d",&n);
    while(n --> 0){
        char s[30];
        scanf("%s",s);
        vector<int> freq(26,0);
        for(int i=0;s[i];++i)
            freq[s[i]-'A']++;

        unsigned long long ans=1;

        for(int i=1;i<=strlen(s);++i){
            ans*=i;
            for(int j=0;j<26;++j){
                while(freq[j]>0&&ans%freq[j]==0){
                    ans/=freq[j];
                    --freq[j];
                }
            }
        }

        printf("Data set %d: %lld\n",tc++,ans);

    }



    return 0;
}

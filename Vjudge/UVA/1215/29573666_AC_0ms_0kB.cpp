#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e5+10,M=2e9+7,OO=0x3f3f3f3f;

char s[N];

int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    int t;
    scanf("%d",&t);
    while(t--){
        int k;
        scanf("%d",&k);
        vector<int> cuts(k);
        for(int i=0;i<k;++i)
            scanf("%d",&cuts[i]);
        scanf("%s",s);
        int n=strlen(s);
        vector<int> cut(n,0);
        int total=0;
        for(int i=0;i<k;++i){
            int l=0,r=n-1;
            for(int j=cuts[i]-2;j>-1;--j){
                if(cut[j]){
                    l=j+1;
                    break;
                }
            }
            for(int j=cuts[i];j<n;++j){
                if(cut[j]){
                    r=j;
                    break;
                }
            }
            vector<int> freq1(26,0);
            vector<int> freq2(26,0);
            for(int j=l;j<cuts[i];++j)
                freq1[s[j]-'a']=1;
            for(int j=cuts[i];j<=r;++j)
                freq2[s[j]-'a']=1;
            int cnt=0;
            for(int i=0;i<26;++i)
                cnt+=freq1[i]^freq2[i];
            total+=cnt;
            cut[cuts[i]-1]=1;
        }
        printf("%d\n",total);
    }


    return 0;
}

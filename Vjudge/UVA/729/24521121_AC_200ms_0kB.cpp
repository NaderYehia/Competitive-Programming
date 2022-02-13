#include<bits/stdc++.h>

using namespace std;

int t,c,n;
vector<int>v;

int main() {
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&c);
        for(int i=0;i<(1<<n);++i){
            int msk=i,cnt=0;
            for(int j=0;j<n;++j){
                if(msk&1)
                    ++cnt,v.push_back(1);
                else
                    v.push_back(0);
                msk>>=1;
            }
            if(cnt==c){
                for(int p=v.size()-1;p>-1;--p)
                    printf("%d",v[p]);
                printf("\n");
            }
            v.clear();
        }
        if(t)
            printf("\n");
    }
	return 0;
}

#include<bits/stdc++.h>

using namespace std;

const int N = 1e6+6,M=1e9+7,OO=0x3f3f3f3f;

int first,last,n,m,k,arr[N],cum[N];
long long cnt=1;
vector<pair<int,int> >v;
vector<int>vv;

int main(){
    scanf("%d%d",&m,&n);
        for(int i=1;i<=n;++i){
            int tmp=i,ex=0;
            while(!(tmp&1))
                ++ex,tmp>>=1;
            arr[i]=pow(2,ex);
        }
        cum[1]=arr[1];
        for(int i=2;i<=n;++i)
            cum[i]+=arr[i]+cum[i-1];
        if(cum[n]<m)
            printf("-1");
        else
        {
            for(int i=1;i<=n;++i)
                v.push_back({arr[i],i});
            sort(v.begin(),v.end());
            for(int i=v.size()-1;i>-1;--i)
                if(m>=v[i].first)
                    vv.push_back(v[i].second),m-=v[i].first;
            printf("%d\n",vv.size());
            for(int i=0;i<vv.size();++i)
                printf("%d ",vv[i]);
        }
    return 0;
}

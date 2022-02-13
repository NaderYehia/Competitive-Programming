#include<bits/stdc++.h>

using namespace std;

const int N=2e3+5;
int t,n,m,cnt;
int arr[15];
vector<pair<pair<int,int> ,int> >v;

int getPos(int x){
    for(int i=0;i<n;++i)
        if(arr[i]==x)
            return i;
}

int main() {
    while(scanf("%d%d",&n,&m),(n+m)){
        for(int i=0;i<m;++i){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            v.push_back(make_pair(make_pair(a,b),c));
        }
        cnt=0;
        for(int i=0;i<n;++i)
        arr[i]=i;
        do{
            ++cnt;
            for(int i=0;i<m;++i){
                int f=v[i].first.first;
                int s=v[i].first.second;
                int val=v[i].second;
                if(val<0){
                    if(abs(getPos(f)-getPos(s))<abs(val)){
                        --cnt;
                        break;
                    }
                }
                else{
                    if(abs(getPos(f)-getPos(s))>abs(val)){
                        --cnt;
                        break;
                    }
                }
            }
        }while(next_permutation(arr,arr+n));
        printf("%d\n",cnt);
        v.clear();
    }

    return 0;
}

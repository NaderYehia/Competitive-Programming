#include <bits/stdc++.h>

using namespace std;

const int N=1e3+5,OO=0x3f3f3f3f;
int t,n,m,k,q;
int arr[N];
bool marked[N];


int main(){
    //freopen("myfile.txt","w",stdout);
    while(~scanf("%d",&n),n){
        vector<pair<int,int> > v;
        for(int i=0;i<n;++i){
            int a,b;scanf("%d%d",&a,&b);
            v.push_back({a,b});
        }
        bool stop=0;
        memset(marked,0,sizeof marked);
        for(int i=0;i<v.size();++i){
            int req=i+v[i].second;
            if(req>=0&&req<n&&!marked[req]){
                marked[req]=1;
                arr[req]=v[i].first;
            }
            else{
                stop=1;
                break;
            }
        }
        if(stop)
            printf("-1\n");
        else
            for(int i=0;i<n;++i)
                printf("%d%c",arr[i]," \n"[i+1==n]);
    }
    return 0;
}

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
const int N=1e5+10,M=10000007,OO=0x3f3f3f3f;
const double eps=1e-9;
 
void babbageDifferenceEngine(vector<vector<int> > &def,int m){
    while(def.back().size()>1){
        vector<int> cur;
        for(int i=1;i<def.back().size();++i){
            cur.push_back(def.back()[i]-def.back()[i-1]);
        }
        def.push_back(cur);
    }
    def.back().resize(m+1,def.back().back());
    for(int i=def.size()-1,j=1;i>0;--i,++j){
        for(int k=0;k<m;++k){
            def[i-1].push_back(def[i][k+j]+def[i-1][k+j]);
        }
    }
}
 
int main(){
 
    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);
 
 
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d%d",&n,&m);
        vector<int> arr(n);
        for(int i=0;i<n;++i)
            scanf("%d",&arr[i]);
 
        vector<vector<int> > def;
        def.push_back(arr);
        babbageDifferenceEngine(def,m);
 
        for(int i=n;i<def[0].size();++i)
            printf("%d%c",def[0][i]," \n"[i==def[0].size()-1]);
 
    }
 
    return 0;
}
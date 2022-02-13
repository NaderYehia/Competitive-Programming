#include <bits/stdc++.h>

using namespace std;

const int N=1e6+5,OO=0x3f3f3f3f;
int t,n,m,k,q;
int arr[N];

int main(){
    //freopen("myfile.txt","w",stdout);
    while(~scanf("%d",&n),n){
        vector<int>v;
        v.push_back(0);
        for(int i=0,a;i<n;++i){
            scanf("%d",&a);
            v.push_back(a);
        }
        sort(v.begin(),v.end());
        bool failed=0;
        for(int i=1;i<v.size();++i){
            if(v[i]-v[i-1]>200){
                failed=1;
                break;
            }
        }
        if(1422-v.back()>100)
            failed=1;
        if(failed)
            printf("IMPOSSIBLE\n");
        else
            printf("POSSIBLE\n");
    }
    return 0;
}

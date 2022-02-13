#include<bits/stdc++.h>

using namespace std;

const int N = 1e3+6,M=1e9+7,OO=0x3f3f3f3f;

int t,n,m,k,sum;
int arr[15];
set<vector<int> > ans;
vector<int> v;

void solve(int i){
    if(i==n){
        if(sum==k)
            ans.insert(v);
        return;
    }
    sum+=arr[i];
    v.push_back(arr[i]);
    solve(i+1);
    sum-=arr[i];
    v.pop_back();
    solve(i+1);
}

int main(){
    while(scanf("%d%d",&k,&n),k||n){
        for(int i=0;i<n;++i)
            scanf("%d",arr+i);
        solve(0);
        printf("Sums of %d:\n",k);
        if(ans.size()==0)
            puts("NONE");
        else
        {
            set<vector<int> >::iterator it = ans.end();
            for(--it;;it--){
                vector<int> vec=*it;
                for(int i=0;i<vec.size();++i)
                    printf("%d%c",vec[i],"+\n"[i==vec.size()-1]);
                if(it==ans.begin())
                    break;
            }
        }
        ans.clear();
    }
    return 0;
}

#include<bits/stdc++.h>

using namespace std;

int t,k,n,sum;
int arr[50];
vector<int>v;
set<vector<int> >ans;
stack<vector<int> >st;

void solve(int i){
    if(i==n){
        if(sum==k)
            ans.insert(v);
        return;
    }
    solve(i+1);
    v.push_back(arr[i]);
    sum+=arr[i];
    solve(i+1);
    sum-=arr[i];
    v.pop_back();
}


int main() {
    while(scanf("%d%d",&k,&n),k||n){
        printf("Sums of %d:\n",k);
        for(int i=0;i<n;++i)
            scanf("%d",arr+i);
        ans.clear();
        solve(0);
        if(ans.empty()){
            printf("NONE\n");
            continue;
        }
        for(auto val:ans)
            st.push(val);
        while(st.size()){
            vector<int> tmp=st.top();
            for(int i=0;i<tmp.size();++i)
                printf("%d%c",tmp[i],"+\n"[i+1==tmp.size()]);
            st.pop();
        }
    }
	return 0;
}

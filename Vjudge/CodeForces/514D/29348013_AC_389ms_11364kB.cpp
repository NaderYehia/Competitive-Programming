#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e5+10,M=2e6+7,OO=0x3f3f3f3f;

struct q{

    queue<int> qu;
    deque<int> dq;

    void clear(){
        queue<int> empty;
        swap(empty,qu);
        dq.clear();
    }

    void pop(){
        if(qu.front()==dq.front()){
            dq.pop_front();
        }
        qu.pop();
    }

    void push(int val){
        while(dq.size()&&val>dq.back()){
            dq.pop_back();
        }
        qu.push(val);
        dq.push_back(val);
    }

    int max(){
        return dq.front();
    }

};

int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    vector<vector<int> > arr(n+5,vector<int>(m+5,0));
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            scanf("%d",&arr[i][j]);
        }
    }

    vector<q> mxs(m);
    for(int i=0;i<m;++i)
        mxs[i].push(arr[0][i]);

    vector<int> ans(m,0);

    int i=0,j=0,len=0;
    while(i<n&&j<n){
        if(i>j){
            j=i;
            for(int i=0;i<m;++i)
                mxs[i].clear();
            for(int i=0;i<m;++i)
                mxs[i].push(arr[j][i]);
        }
        int sum=0;
        for(int i=0;i<m;++i)
            sum+=mxs[i].max();
        if(sum>k){
            for(int i=0;i<m;++i)
                mxs[i].pop();
            ++i;
            continue;
        }
        if(j-i+1>len){
            ans.clear();
            for(int i=0;i<m;++i)
                ans.push_back(mxs[i].max());
            len=j-i+1;
        }
        ++j;
        for(int i=0;i<m;++i)
            mxs[i].push(arr[j][i]);
    }
    for(int i=0;i<ans.size();++i)
        printf("%d ",ans[i]);

    return 0;
}

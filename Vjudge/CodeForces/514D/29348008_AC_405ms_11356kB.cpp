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
            for(int k=0;k<m;++k){
                mxs[k].clear();
                mxs[k].push(arr[i][k]);
            }
            j=i;
        }
        vector<int> temp;
        for(int k=0;k<m;++k)
            temp.push_back(mxs[k].max());
        if(accumulate(temp.begin(),temp.end(),0)>k){
            ++i;
            for(int k=0;k<m;++k)
                mxs[k].pop();
            continue;
        }
        if(j-i+1>len){
            len=j-i+1;
            ans=temp;
        }
        ++j;
        for(int k=0;k<m;++k)
            mxs[k].push(arr[j][k]);
    }
    for(int i=0;i<ans.size();++i)
        printf("%d ",ans[i]);

    return 0;
}

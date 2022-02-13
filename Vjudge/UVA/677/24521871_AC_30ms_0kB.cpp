#include<bits/stdc++.h>

using namespace std;

int t,k,n,m;
int vis[20];
int arr[20][20];
vector<int> v;
bool printed;

void print(){
    printf("(");
    for(int i=0;i<v.size();++i)
        printf("%d%c",v[i]+1,",)"[i+1==v.size()]);
    printf("\n");
}

void solve(int i,int len){
    if(len==m){
        printed=1;
        print();
        return;
    }
    for(int j=0;j<n;++j){
        if(arr[i][j]==1&&!vis[j]){
            vis[j]=1;
            v.push_back(j);
            solve(j,len+1);
            vis[j]=0;
            v.pop_back();
        }
    }
}

int main() {
    while(1){
        printed=0;
        cin>>n>>m;
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
                scanf("%d",arr[i]+j);
        v.push_back(0);
        vis[0]=1;
        solve(0,0);
        v.pop_back();
        vis[0]=0;
        if(!printed)
            printf("no walk of length %d\n",m);
        if(cin>>k){
            printf("\n");
            continue;
        }
        else
            break;
    }
	return 0;
}
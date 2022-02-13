#include<bits/stdc++.h>

using namespace std;

int t,n,m,mx,sum;
int arr[10];
bool vis[10],poss;

bool allVis(){
    for(int i=0;i<5;++i)
        if(!vis[i])
            return 0;
    return 1;
}

void solve(){
    if(allVis()){
        if(sum==23)
            poss=1;
        return;
    }
    for(int i=0;i<5;++i){
        if(!vis[i]){
            vis[i]=1;
            sum+=arr[i];
            solve();
            sum-=arr[i];
            sum*=arr[i];
            solve();
            sum/=arr[i];
            sum-=arr[i];
            solve();
            sum+=arr[i];
            vis[i]=0;
        }
    }
}

int main() {
    while(scanf("%d%d%d%d%d",arr+0,arr+1,arr+2,arr+3,arr+4),(arr[0]||arr[1]||arr[2]||arr[3]||arr[4])){
        poss=0;
        for(int i=0;i<5;++i){
            vis[i]=1;
            sum=arr[i];
            solve();
            vis[i]=0;
        }
        if(poss)
            printf("Possible\n");
        else
            printf("Impossible\n");
    }
	return 0;
}

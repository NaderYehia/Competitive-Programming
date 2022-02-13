#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e4+10,M=2e4+7,OO=0x3f3f3f3f;

void go(vector<int> &bck,vector<int> &arr,int i){
    if(i==-1) return;
    go(bck,arr,bck[i]);
    printf(" %d",arr[i]);
}

int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    int n;
    while(~scanf("%d",&n),n){
        vector<int> arr(n);
        for(int i=0;i<n;++i)
            scanf("%d",&arr[i]);
        vector<int> mem(n);
        vector<int> bck(n,-1);
        int mx=0,id=-1;
        for(int i=0;i<n;++i){
            mem[i]=1;
            for(int j=0;j<i;++j){
                if(arr[j]<arr[i]){
                    if(mem[j]+1>mem[i]){
                        mem[i]=mem[j]+1;
                        bck[i]=j;
                    }
                    else if(mem[j]+1==mem[i]){
                        if(arr[bck[i]]>arr[j])
                            bck[i]=j;
                    }
                }
            }
            if(mem[i]>mx){
                mx=mem[i];
                id=i;
            }
            else if(mem[i]==mx&&arr[id]>arr[i]){
                id=i;
            }
        }
        printf("%d",mx);
        go(bck,arr,id);
        puts("");
    }


    return 0;
}

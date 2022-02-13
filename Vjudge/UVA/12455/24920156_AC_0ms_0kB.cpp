#include<bits/stdc++.h>

using namespace std;

const int N=2e3+5;
int t,n,m,cnt;
int arr[40];
vector<int> v1,v2;

vector<int> subset(int ar[],int n){
    vector<int> vals;
    for(int i=0;i<(1<<n);++i){
        int sum=0;
        for(int j=0;j<n;++j)
            if(i&(1<<j))
                sum+=ar[j];
        vals.push_back(sum);
    }
    return vals;
}

int main() {
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&m,&n);
        for(int i=0;i<n;++i)
            scanf("%d",arr+i);
        int ar1[30],ar2[30];
        for(int i=0;i<(n/2+(n&1));++i)
            ar1[i]=arr[i];
        for(int j=0,i=(n/2+(n&1));i<n;++i,++j)
            ar2[j]=arr[i];
        v1=subset(ar1,(n/2+(n&1)));
        v2=subset(ar2,n/2);
        bool found=0;
        sort(v2.begin(),v2.end());
        for(int i=0;i<v1.size();++i){
            if(binary_search(v2.begin(),v2.end(),m-v1[i])){
                found=1;
                break;
            }
        }
        if(!found)
            printf("NO\n");
        else
            printf("YES\n");
        v1.clear(),v2.clear();
    }
    return 0;
}

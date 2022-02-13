#include <bits/stdc++.h>

using namespace std;

const int N=1e6+5,OO=0x3f3f3f3f;
int t,n,m,k,q;
int arr[N];
map<int,int> mp;

int main(){
    //freopen("myfile.txt","w",stdout);
    int j=0;
    while(cin>>n){
        arr[j++]=n;
        ++mp[n];
    }
    for(int i=0;i<j;++i){
        if(mp[arr[i]]!=-1){
            printf("%d %d\n",arr[i],mp[arr[i]]);
            mp[arr[i]]=-1;
        }
    }
    return 0;
}

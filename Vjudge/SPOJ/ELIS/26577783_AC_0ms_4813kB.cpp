#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=6e4+5,OO=0x3f3f3f3f;
const double eps=1e-6,pi=3.14159265359;
int t,n,m;
int arr[2000];
int mem[2000];

int main(){
    //freopen("myfile.txt","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",arr+i);
    for(int i=0;i<n;++i){
        int ret=1;
        for(int j=0;j<i;++j){
            if(arr[i]>arr[j])
                ret=max(ret,mem[j]+1);
        }
        mem[i]=ret;
    }
    int idx=max_element(mem,mem+n)-mem;
    cout<<mem[idx];
    return 0;
}

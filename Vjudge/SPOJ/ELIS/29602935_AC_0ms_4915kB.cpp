#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e4+10,M=2e4+7,OO=0x3f3f3f3f;



int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    int n;
    scanf("%d",&n);
    vector<int> arr(n);
    for(int i=0;i<n;++i)
        scanf("%d",&arr[i]);

    vector<int> mem(n);
    for(int i=0;i<n;++i){
        mem[i]=1;
        for(int j=0;j<i;++j){
            if(arr[j]<arr[i])
                mem[i]=max(mem[i],mem[j]+1);
        }
    }

    printf("%d\n",*max_element(mem.begin(),mem.end()));


    return 0;
}

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=2e2+10,M=1e9+7,OO=0x3f3f3f3f;


int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    int n;
    scanf("%d",&n);
    vector<string> arr(n);
    for(int i=0;i<n;++i)
        cin>>arr[i];

    set<string> st;
    for(int i=n-1;~i;--i){
        if(st.find(arr[i])==st.end()) printf("%s\n",arr[i].c_str()),st.insert(arr[i]);
    }

    return 0;
}

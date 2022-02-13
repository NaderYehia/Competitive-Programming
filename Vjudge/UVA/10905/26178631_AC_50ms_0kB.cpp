#include <bits/stdc++.h>

using namespace std;

const int N=1e6+5,OO=0x3f3f3f3f;
int t,n,m,k,q;
int arr[N];
string s;

bool comp(const string &s1,const string &s2){
    return s2+s1<s1+s2;
}

int main(){
    //freopen("myfile.txt","w",stdout);
    while(~scanf("%d",&n),n){
        vector<string> v;
        for(int i=0;i<n;++i){
            cin>>s;
            v.push_back(s);
        }
        sort(v.begin(),v.end(),comp);
        for(int i=0;i<v.size();++i)
            cout<<v[i];
        printf("\n");
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

const int N=1e3+5,OO=0x3f3f3f3f;
int t,n,m,k,q;
map<string,string> mp;

int main(){
    string s;
    while(getline(cin,s)&&s!=""){
        stringstream ss(s);
        string s1,s2;
        ss>>s1;
        ss>>s2;
        mp[s2]=s1;
    }
    while(cin>>s){
        if(mp.find(s)==mp.end())
            printf("eh\n");
        else
            cout<<mp[s]<<endl;
    }
    return 0;
}

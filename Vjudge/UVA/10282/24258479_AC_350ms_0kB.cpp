#include<bits/stdc++.h>

using namespace std;

map<string,string>mp;
string s,s1,s2;

int main(){
    while(getline(cin,s)&&s.length()){
        string s1,s2;
        stringstream ss(s);
        ss>>s1>>s2;
        mp[s2]=s1;
    }
    while(cin>>s)
        printf("%s\n",(mp[s]=="")?"eh":mp[s].c_str());
    return 0;
}

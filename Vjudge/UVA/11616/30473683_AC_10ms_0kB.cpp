#include <bits/stdc++.h>

using namespace std;

const int N=5e5+10;

map<string,int> mp;

int hat_elrakm(string &s){
    int ret=0;
    for(int i=0;i<s.length();++i)
        ret=ret*10+s[i]-'0';

    return ret;
}

int main(){

    vector<string> v={"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};

    mp["I"]=1;
    mp["IV"]=4;
    mp["V"]=5;
    mp["IX"]=9;
    mp["X"]=10;
    mp["XL"]=40;
    mp["L"]=50;
    mp["XC"]=90;
    mp["C"]=100;
    mp["CD"]=400;
    mp["D"]=500;
    mp["CM"]=900;
    mp["M"]=1000;


    string s;
    while(getline(cin,s)){
        if(s[0]>='0'&&s[0]<='9'){
            int n=hat_elrakm(s);
            int j=v.size()-1;
            while(j>-1){
                while(n>=mp[v[j]]){
                    printf("%s",v[j].c_str());
                    n-=mp[v[j]];
                }
                j--;
            }
            puts("");
        }
        else{
            int ans=0;
            for(int i=0;i<s.length();++i){
                if(i<s.length()-1&&mp[string(1,s[i])]<mp[string(1,s[i+1])]){
                    ans+=-mp[string(1,s[i])]+mp[string(1,s[i+1])];
                    ++i;
                }
                else{
                    ans+=mp[string(1,s[i])];
                }
            }
            printf("%d\n",ans);
        }
    }

    return 0;
}

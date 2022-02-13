#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e2+10,M=2e9+7,OO=0x3f3f3f3f;

bool pal(string &s){
    int i=0,j=s.length()-1;
    while(i<j){
        if(s[i]!=s[j]) return 0;
        ++i,--j;
    }
    return 1;
}

int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    string s;
    while(getline(cin,s)){
        set<string> pals;
        for(int i=0;s[i];++i){
            string temp="";
            temp+=s[i];
            pals.insert(temp);
            for(int j=i+1;s[j];++j){
                temp+=s[j];
                if(pal(temp)) pals.insert(temp);
            }
        }
        printf("The string '%s' contains %d palindromes.\n",s.c_str(),pals.size());
    }


    return 0;
}

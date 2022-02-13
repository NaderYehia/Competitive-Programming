#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e2+10,M=2e9+7,OO=0x3f3f3f3f;

bool haa(string s,int len){
    if(s[len-1]=='o') return 1;
    if(s[len-1]=='s') return 1;
    if(s[len-1]=='x') return 1;
    if(len>=2&&(s[len-2]=='c'&&s[len-1]=='h')) return 1;
    if(len>=2&&(s[len-2]=='s'&&s[len-1]=='h')) return 1;
    return 0;
}

bool con(char c){
    return (c=='o'||c=='e'||c=='i'||c=='a'||c=='u');
}

int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    int l,n;
    scanf("%d%d",&l,&n);
    map<string,string> mp;
    for(int i=0;i<l;++i){
        string s1,s2;
        cin>>s1>>s2;
        mp[s1]=s2;
    }
    for(int i=0;i<n;++i){
        string s;
        cin>>s;
        int len=s.length();
        if(mp.find(s)!=mp.end()){
            printf("%s\n",mp[s].c_str());
        }
        else if(len>=2&&s[len-1]=='y'&&!con(s[len-2])){
            s[len-1]='i';
            printf("%s\n",string(s+"es").c_str());
        }
        else if(haa(s,len)){
            printf("%s\n",string(s+"es").c_str());
        }
        else{
            printf("%s\n",string(s+"s").c_str());
        }
    }


    return 0;
}

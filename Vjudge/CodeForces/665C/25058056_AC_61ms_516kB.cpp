#include<bits/stdc++.h>

using namespace std;

const int N=2e5+5;
int q,n,c;
string s;


int main() {
    cin>>s;
    for(int i=1;s[i];++i){
        if(s[i]==s[i-1]){
            for(int j=0;j<26;++j){
                if('a'+j!=s[i-1]){
                    if(i+1>=s.length()){
                        s[i]='a'+j;
                        break;
                    }
                    else{
                        if(s[i+1]!='a'+j){
                            s[i]='a'+j;
                            break;
                        }
                    }
                }
            }
        }
    }
    cout<<s;
    return 0;
}

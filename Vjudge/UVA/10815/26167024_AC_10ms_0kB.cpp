#include <bits/stdc++.h>

using namespace std;

const int N=1e3+5,OO=0x3f3f3f3f;
int t,n,m,k,q;
string s;

int main(){
    set<string> st;
    while(cin>>s){
        string tmp;
        for(int i=0;s[i];++i){
            s[i]=tolower(s[i]);
            if(s[i]>='a'&&s[i]<='z')
                tmp+=s[i];
            else{
                if(tmp!="")
                    st.insert(tmp),tmp="";
            }
        }
        if(tmp!="")
            st.insert(tmp);
    }
    for(set<string>::iterator iter=st.begin();iter!=st.end();++iter){
        cout<<(*iter)<<endl;
    }
    return 0;
}

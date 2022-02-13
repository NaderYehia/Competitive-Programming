#include <bits/stdc++.h>

using namespace std;

const int N=1e6+5,OO=0x3f3f3f3f;
int t,n,m,k,q;
int arr[N];
string s;


int main(){
    //freopen("myfile.txt","w",stdout);
    while(getline(cin,s)){
        deque<string> dq;
        for(int i=0;i<s.length();++i){
            string tmp="";
            if(s[i]=='['){
                for(int j=i+1;j<s.length();++j){
                    if(s[j]!='['&&s[j]!=']'){
                        tmp+=s[j];
                        i=j;
                    }
                    else {
                        break;
                    }
                }
                dq.push_front(tmp);
            }
            else if(s[i]==']'){
                for(int j=i+1;j<s.length();++j){
                    if(s[j]!='['&&s[j]!=']'){
                        tmp+=s[j];
                        i=j;
                    }
                    else {
                        break;
                    }
                }
                dq.push_back(tmp);
            }
            else{
                tmp+=s[i];
                dq.push_back(tmp);
            }
        }
        while(dq.size()){
            cout<<dq.front();
            dq.pop_front();
        }
        cout<<endl;
    }
    return 0;
}

#include<bits/stdc++.h>

using namespace std;

const int N=1e6+5;
int t,n,c;
string s;
vector<int> v;

int main() {
    scanf("%d",&t);
    while(t--){
        int cnt=0;
        v.clear();
        cin>>s;
        for(int i=0;i<s.length();++i){
            if(i+2<s.length()&&s[i]=='t'&&s[i+1]=='w'&&s[i+2]=='o'){
                ++cnt;
                if(i+4<s.length()&&s[i+3]=='n'&&s[i+4]=='e')
                    v.push_back(i+2);
                else
                    v.push_back(i+1);
                i+=2;
            }
            else if(i+2<s.length()&&s[i]=='o'&&s[i+1]=='n'&&s[i+2]=='e'){
                ++cnt;
                v.push_back(i+1);
                i+=2;
            }
        }
        printf("%d\n",cnt);
        for(int i=0;i<v.size();++i)
            printf("%d%c",v[i]+1," \n"[i+1==v.size()]);
    }
    return 0;
}

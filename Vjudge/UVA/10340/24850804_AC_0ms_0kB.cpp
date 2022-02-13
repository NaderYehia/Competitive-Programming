#include<bits/stdc++.h>

using namespace std;

const int N=2e3+5;
int t,n,m;
vector<int> vp;

int main() {
    string s,s1,s2;
    while(getline(cin,s)){
        stringstream ss(s);
        ss>>s1;
        ss>>s2;
        int j=0;
        for(int i=0;s2[i];++i){
            if(s2[i]==s1[j])
                ++j;
            if(j==s1.length())
                break;
        }
        if(j==s1.length())
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

const int N=1e6+5,OO=0x3f3f3f3f;
int t,n,m,k,q;
int arr[N];
string s;

int main(){
    //freopen("myfile.txt","w",stdout);
    int tc=0;
    scanf("%d\n\n",&t);
    while(t--){
        if(tc++)
            printf("\n");
        map<string,int> mp;
        int cnt=0;
        while(getline(cin,s)&&s!=""){
            ++mp[s];
            ++cnt;
        }
        for(map<string,int>::iterator iter=mp.begin();iter!=mp.end();++iter){
            printf("%s %.4f\n",(iter->first).c_str(),(double)(iter->second)/cnt*100);
        }
    }
    return 0;
}
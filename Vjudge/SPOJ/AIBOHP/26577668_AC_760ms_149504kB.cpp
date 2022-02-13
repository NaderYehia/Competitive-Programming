#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=6e4+5,OO=0x3f3f3f3f;
const double eps=1e-6,pi=3.14159265359;
int t,n,m;
int mem[6105][6105];
string s1;

int solve(int i,int j){
    if(i>=j) return 0;
    int &ret=mem[i][j];
    if(ret!=-1) return ret;
    if(s1[i]==s1[j]) return solve(i+1,j-1);
    ret=min(solve(i+1,j)+1,solve(i,j-1)+1);
    return ret;
}

int main(){
    //freopen("myfile.txt","w",stdout);
    scanf("%d\n",&t);
    while(t--){
        cin>>s1;
        memset(mem,-1,sizeof mem);
        cout<<solve(0,s1.length()-1)<<endl;
    }
    return 0;
}

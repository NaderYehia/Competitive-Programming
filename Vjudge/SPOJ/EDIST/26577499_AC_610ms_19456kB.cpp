#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=2e3+5,OO=0x3f3f3f3f;
const double eps=1e-6,pi=3.14159265359;
int t,n,m;
int mem[N][N];
string s1,s2;

int solve(int i,int j){
    if(i>=s1.length()) return s2.length()-j;
    if(j>=s2.length()) return s1.length()-i;
    int &ret=mem[i][j];
    if(ret!=-1) return ret;
    if(s1[i]==s2[j]) return solve(i+1,j+1);
    ret=min(1+solve(i+1,j),min(1+solve(i,j+1),1+solve(i+1,j+1)));
    return ret;
}

int main(){
    //freopen("myfile.txt","w",stdout);
    scanf("%d\n",&t);
    while(t--){
        cin>>s1>>s2;
        memset(mem,-1,sizeof mem);
        cout<<solve(0,0)<<endl;
    }
    return 0;
}

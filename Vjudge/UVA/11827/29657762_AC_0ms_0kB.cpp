#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=2e3+10,M=1e3+7,OO=0x3f3f3f3f;



int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    int n;
    scanf("%d\n",&n);
    while(n --> 0){
        string s;
        getline(cin,s);
        stringstream ss(s);
        vector<int> v;
        int x;
        while(ss>>x){
            v.push_back(x);
        }
        int g=1;
        for(int i=0;i<v.size();++i){
            for(int j=i+1;j<v.size();++j){
                g=max(g,__gcd(v[i],v[j]));
            }
        }
        printf("%d\n",g);
    }

    return 0;
}

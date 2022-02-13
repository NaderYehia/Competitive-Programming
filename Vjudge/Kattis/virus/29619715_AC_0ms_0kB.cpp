#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e5+10,M=2e4+7,OO=0x3f3f3f3f;



int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    char s[N],t[N];
    scanf("%s%s",s,t);

    deque<char> c1,c2;
    for(int i=0;s[i];++i)
        c1.push_back(s[i]);
    for(int i=0;t[i];++i)
        c2.push_back(t[i]);

    while(c1.size()&&c2.size()&&c1.front()==c2.front())
        c1.pop_front(),c2.pop_front();

    while(c1.size()&&c2.size()&&c1.back()==c2.back())
        c1.pop_back(),c2.pop_back();

    printf("%d\n",int(c2.size()));

    return 0;
}

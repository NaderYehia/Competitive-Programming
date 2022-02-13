#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1e2+10,M=2e9+7,OO=0x3f3f3f3f;



int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    int n;
    scanf("%d\n",&n);
    vector<int> freq(26,0);
    while(n--){
        string s;
        getline(cin,s);
        for(int i=0;s[i];++i){
            if(toupper(s[i])>='A'&&toupper(s[i])<='Z'){
                ++freq[toupper(s[i])-'A'];
            }
        }
    }
    priority_queue<pair<int,int> > pq;
    for(int i=0;i<26;++i)
        if(freq[i]>0) pq.push({freq[i],-i});
    while(pq.size()){
        printf("%c %d\n",char('A'-pq.top().second),pq.top().first);
        pq.pop();
    }


    return 0;
}

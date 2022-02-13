#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=5e2+10,M=1e9+7,OO=0x3f3f3f3f;



int main(){

    //freopen("haa.txt","r",stdin);
    //freopen("myfile.txt","w",stdout);

    priority_queue<int> pq;
    int n;
    scanf("%d",&n);
    vector<string> v;
    for(int i=0;i<n;++i){
        string s;int x;
        cin>>s;
        if(s[0]=='i'){
            scanf("%d",&x);
            string ss;
            ss=s+' '+to_string(x);
            v.push_back(ss);
            pq.push(-x);
        }
        else if(s[0]=='g'){
            scanf("%d",&x);
            if(pq.empty()){
                string ss;
                ss="insert "+to_string(x);
                v.push_back(ss);
                //printf("insert %d\n",x);
                pq.push(-x);
                ss=s+' '+to_string(x);
                v.push_back(ss);
                //printf("%s %d\n",s,x);
            }
            else if(-pq.top()==x){
                string ss=s+' '+to_string(x);
                v.push_back(ss);
                //printf("%s %d\n",s,x);
            }
            else if(-pq.top()>x){
                string ss="insert "+to_string(x);
                v.push_back(ss);
                //printf("insert %d\n",x);
                pq.push(-x);
                ss=s+' '+to_string(x);
                v.push_back(ss);
                //printf("%s %d\n",s,x);
            }
            else{
                while(pq.size()&&-pq.top()<x){
                    v.push_back("removeMin");
                    //printf("removeMin\n");
                    pq.pop();
                }
                if(pq.size()&&-pq.top()==x){
                    string ss=s+' '+to_string(x);
                    v.push_back(ss);
                    //printf("%s %d\n",s,x);
                }
                else{
                    string ss="insert "+to_string(x);
                    v.push_back(ss);
                    //printf("insert %d\n",x);
                    pq.push(-x);
                    ss=s+' '+to_string(x);
                    v.push_back(ss);
                    //printf("%s %d\n",s,x);
                }
            }
        }
        else{
            if(pq.size()){
                v.push_back("removeMin");
                pq.pop();
                //printf("%s\n",s);
            }
            else{
                v.push_back("insert 2");
                //printf("insert %d\n",1);
                v.push_back("removeMin");
                //printf("%s\n");
            }
        }
    }
    printf("%d\n",v.size());
    for(int i=0;i<v.size();++i)
        printf("%s\n",v[i].c_str());

    return 0;
}

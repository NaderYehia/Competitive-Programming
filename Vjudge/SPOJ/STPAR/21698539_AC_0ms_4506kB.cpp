#include<bits/stdc++.h>
using namespace std;
int k=1,n;
queue<int>q;
stack<int>sk;
int main(){
	while(scanf("%d",&n),n){
		k=1;
		while(!sk.empty()) sk.pop();
		for(int i=0;i<n;++i){
			int a;
			scanf("%d",&a);
			q.push(a);
		}
		while(!q.empty()){
			if(q.front()==k){
				q.pop();
				++k;
			}
			else if(!sk.empty()&&sk.top()==k){
				++k;
				sk.pop();
			}
			else{
				sk.push(q.front());
				q.pop();
			}
		}
		while(!sk.empty())
			if(sk.top()==k){
				++k	;
				sk.pop();
			}
			else
				break;
		if(sk.empty())
			puts("yes");
		else
			puts("no");
	}
}
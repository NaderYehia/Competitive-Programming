#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int q, x,r=0;
char op[10];
deque<int> dq;
 
int main(){
  scanf("%d", &q);
  while(q--){
    scanf("%s", op);
    if(op[0] == 't'){   //toFront
      scanf("%d", &x);
      if(r&1)
      	dq.push_back(x);
      else
      	dq.push_front(x);
    }else if(op[0] == 'p'){ //push_back
      scanf("%d", &x);
      if(r&1)
      	dq.push_front(x);
      else
      	dq.push_back(x);
    }else if(op[0] == 'r'){ //reverse
      //TODO
      r+=1;
    }else if(op[0] == 'b'){ //back
      if(dq.size() == 0)
        printf("No job for Ada?\n");
      else{
      	if(r&1){
      		printf("%d\n", dq[0]);
        	dq.pop_front();
		  }
      	else {	  
        printf("%d\n", dq.back());
        dq.pop_back();
    }
      }
    }else if(op[0] == 'f'){ //front
      if(dq.size() == 0)  printf("No job for Ada?\n");
      else{
      	if(r&1){
      		printf("%d\n", dq.back());
        	dq.pop_back();
		  }
		else {
        printf("%d\n", dq[0]);
        dq.pop_front();
    }
      }
    }
  }
  return 0;
}
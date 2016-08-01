#include <iostream>
#include <string.h>
#include <cstdio>

using namespace std;

const int maxi = 100001;
int n,k;
int tis[1200001];
int q[200001];


void bfs(int xx){
   int front =0;
   int rear = 0;
   tis[xx] = 1;
   q[rear++] = xx;
   while(front!=rear){
   	   int p = q[front++];
   	   //if(p<20)
   	   //cout<<p<<endl;
   	   int nx = p+1;
   	   if(nx>=0&&nx<maxi && tis[nx]==0){
   	   	  q[rear++] = nx;
   	   	  tis[nx] = tis[p]+1;
   	   }
   	   nx = p-1;
   	   if(nx>=0&&nx<maxi && tis[nx]==0){
   	   	  q[rear++] = nx;
   	   	  tis[nx] = tis[p]+1;
   	   }
   	   nx =2 * p;
   	   //nx = p-1;
   	   if(nx>=0&&nx<maxi && tis[nx]==0){
   	   	  q[rear++] = nx;
   	   	  tis[nx] = tis[p]+1;
   	   }

   }
}
int main(){
	 memset(tis,0,sizeof(tis));
     cin>>n>>k;
     bfs(n);
     cout<<(tis[k]-1)<<endl;


	return 0;
}
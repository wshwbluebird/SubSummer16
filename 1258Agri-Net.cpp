#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int n;
const int inf = 100001;
int w[101][101];
int vis[101];

void merge(int x){
	for (int i = 1; i < n; ++i)
	{
		w[0][i] = min(w[0][i],w[x][i]);
	}
	vis[x] =1;
}


int prim(){
   int ans = 0;
   memset(w,0,sizeof(w));
   memset(vis,0,sizeof(vis));
    
   for (int i = 0; i < n; ++i)
   {
   	    for (int j = 0; j < n; ++j)
   	    {
   	    	cin>>w[i][j];
   	    }
   }

   for (int i = 1; i < n; ++i)
   {
   	  int x , m = inf;
   	  for (int j = 1; j < n; ++j)
   	  {
   	  	 if(!vis[j]&&m>w[0][j]) m = w[0][x=j];
   	  }
   	  ans +=  m;
   	  merge(x);
   }

   return ans;



}
int main(){
    
    while(cin>>n){
       cout<<prim()<<endl;
    } 


	return 0;
}
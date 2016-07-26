#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;


int n;
int highway[501][501];
int vis[501];

void merge(int x){
	for (int i = 1; i < n; ++i)
	{
		highway[0][i] = min(highway[0][i],highway[x][i]);
	}
	vis[x]  =1;
}

int Prim(){
   int ans = 0;
   memset(highway,0,sizeof(highway));
   memset(vis,0,sizeof(vis));
   for (int i = 0; i < n; ++i)
   {
   	   for (int j = 0; j < n; ++j)
   	   {
   	   	  cin>>highway[i][j];
   	   }
   }
    vis[0] = 1;
   for (int i = 1; i < n; ++i)
   {
   	 int x,m = 65537; 
   	 for (int j = 1; j < n; ++j)
   	 {
   	 	if(!vis[j]&&m>highway[0][j]) m = highway[0][x=j];
   	 }
      if(m>ans) ans = m;
      merge(x);

   }
     return ans;

}

int main(){
    int cases;
    cin>>cases;
    while(cases--){
    	cin>>n;
    	cout<<Prim()<<endl;
    }


	return 0;
}
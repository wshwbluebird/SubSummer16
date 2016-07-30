#include <iostream>
#include <string.h>
#include <queue>

using namespace std;
int p,q;
const int maxp =27;
const int maxq =27;
int vis[maxp][maxq];//记录是否搜索过

// typedef struct position
// {
// 	int x , y;
// }pos ;

char path[maxp*2];

//需要按照字典序列排
int chx[8] ={ -2,-2,-1,-1,1,1,2,2};
int chy[8] ={ -1,1,-2,2,-2,2,-1,1};

 
int dfs(int cur,int x ,int y){
	  //cout<<"cur: "<<cur<<endl;
     if(cur == p*q) return 1;
     for (int i = 0; i < 8; ++i)
     {
     	
     	int nx = x + chx[i];
     	int ny = y + chy[i];
        //cout<<nx<<" :  "<<ny<<endl;
        
     	if(nx> 0 && ny > 0 && nx <= q && ny<=p && vis[nx][ny]==0){
     		vis[nx][ny] = 1;
     		path[cur *2] = 'A' + nx -1;
     		path[cur * 2 +1] = '0' + ny;
     		if(dfs(cur+1,nx,ny))  return 1;
     		vis[nx][ny] = 0;
     	}
     }

     return 0;

}

int main()
{
  int n = 1;
  int cases;
  cin>>cases;
  while(cases--){
  	cin>>p>>q;
  	printf("Scenario #%d:\n", n++);
    memset(vis,0,sizeof(vis));
    // int x = 1;
    // int y = 1;
    vis[1][1] =1;
    path[0] = 'A';
    path[1] = '1';
    if(dfs(1,1,1)) {
    	for (int i = 0; i < p*q*2; ++i)
    	{
             cout<<path[i];
    	}
    	
    }else{
         printf("impossible");
    }
    cout<<endl<<endl;
  }

	return 0;
}
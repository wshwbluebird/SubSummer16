#include <iostream>
#include <string.h>
#include <cstdio>

using namespace std;

char dun[31][31][31];
bool vis[31][31][31];
int sx,sy,sz;
int ex,ey,ez;
int L,R,C;

int dz[]={1,-1,0,0,0,0};
int dx[]={0,0,1,-1,0,0};
int dy[]={0,0,0,0,1,-1};
const int maxi = 2147483646;
int ans;
void dfs(int cur , int z,int x ,int y){
	//cout<<z<<" : "<<x<<" : "<<y<<endl;
    if(x==ex&&y==ey&&z==ez)  {
    	if(ans>cur) ans = cur;
    }
	for (int i = 0; i < 6; ++i)
	{
		int nz = z + dz[i];
		int nx = x + dx[i];
		int ny = y + dy[i];
		//cout<<"new: "<<nz<<" : "<<nx<<" : "<<ny<<endl;
		if(nz>=0&&nz<L && nx>=0&&nx<R && ny>=0&&ny<C && (!vis[nz][nx][ny]) && dun[nz][nx][ny]!='#'){
               //cout<<"DS"<<endl;
               vis[nz][nx][ny] = 1;
               dfs(cur+1,nz,nx,ny);
               vis[nz][nx][ny] = 0;
		}
	}
}


int main(){
   while(cin>>L>>R>>C){
   	  if((!L)&&(!R)&&(!C)) break;
   	  memset(vis,0,sizeof(vis));
   	  ans = maxi;
      for (int i = 0; i < L; ++i)
         for (int j = 0; j < R; ++j){
         	scanf("%s",dun[i][j]);
         	//getchar();
            for (int k = 0; k < C; ++k)
            {
            	if(dun[i][j][k]=='S') {sx = j; sz = i;sy=k;}
            	else if(dun[i][j][k]=='E'){ex = j; ez = i;ey=k;}
            }
          } 
      vis[sz][sx][sy] = 1;
      dfs(0,sz,sx,sy);
      if(ans!=maxi)  printf("Escaped in %d minute(s).\n", ans);
      else cout<<"Trapped!"<<endl;
       


   } 


	return 0;
}
#include <iostream>
#include <string.h>
#include <cstdio>

using namespace std;

char dun[31][31][31];
int dis[31][31][31];
int sx,sy,sz;
int ex,ey,ez;
int L,R,C;
int qz[30000];
int qx[30000];
int qy[30000];
int dz[]={1,-1,0,0,0,0};
int dx[]={0,0,1,-1,0,0};
int dy[]={0,0,0,0,1,-1};
const int maxi = 2147483646;
int ans;
void bfs(int zz,int xx ,int yy){
    int front = 0;
    int rear = 0;
    dis[zz][xx][yy]=1;
    qz[rear] = zz;
    qx[rear] = xx;
    qy[rear++] = yy;
    while(front!=rear){
        int x = qx[front];
        int y = qy[front];
 		int z = qz[front++];	 

	    for (int i = 0; i < 6; ++i)
	        {
		    int nz = z + dz[i];
		    int nx = x + dx[i];
		    int ny = y + dy[i];
		      //cout<<"new: "<<nz<<" : "<<nx<<" : "<<ny<<endl;
		    if(nz>=0&&nz<L && nx>=0&&nx<R && ny>=0&&ny<C && (dis[nz][nx][ny]==0) && dun[nz][nx][ny]!='#'){
                qz[rear] = nz;
    		    qx[rear] = nx;
    			qy[rear++] = ny;
    			dis[nz][nx][ny] =  dis[z][x][y] + 1;
               
		        }
	        }
		}
}

int main(){
   while(cin>>L>>R>>C){
   	  if((!L)&&(!R)&&(!C)) break;
   	  memset(dis,0,sizeof(dis));
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
      bfs(sz,sx,sy);
      if(dis[ez][ex][ey]!=0)  printf("Escaped in %d minute(s).\n", dis[ez][ex][ey]-1);
      else cout<<"Trapped!"<<endl;
       


   } 


	return 0;
}
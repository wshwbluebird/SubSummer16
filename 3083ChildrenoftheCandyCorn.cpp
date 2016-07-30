#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

const int maxn = 41;



struct pos
{
	int x,y,dist;
};
char maze[maxn][maxn];
int cases,h,w;
int dl[][2] = {{0,-1},{-1,0},{0,1},{1,0}};
int dr[][2] = {{0,1},{-1,0},{0,-1},{1.0}};
int sx,sy,ex,ey;//记录 x，y开始和结束时的位置

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int dfs(int x ,int y , int cur, int dirc ,int dir[][2]){
     if(x==ex&& y==ey)  return cur;
     //cout<<cur<<endl;
     for (int i = 0; i < 4; ++i)
     {
     	//int d = (dirc + i)%4;
     	int d = ((dirc-1+4)%4+i)%4;
     	int nx = x + dir[d][0];
     	int ny = y + dir[d][1];
     	
     	if(nx >= 0 && ny >= 0  && nx < h && ny <w && maze[nx][ny] != '#'){
     		//cout<<nx<<": "<<ny<<endl;
     		return dfs(nx,ny,cur+1,d,dir);

     	}

     }
}

int bfs(int x,int y){
    int ans = 0;
    bool vis[maxn][maxn];
    memset(vis,0,sizeof(vis));
    queue<pos> que;
    pos t1;
    t1.x = sx;
    t1.y =sy;
    t1.dist =1;
    que.push(t1);
    vis[sx][sy] = 1;
    while(!que.empty()){
    	pos p = que.front();
    	que.pop();
    	if(p.x==ex&&p.y==ey)  return p.dist;
    	for (int i = 0; i < 4; ++i)
    	{
    		int nx = p.x+dx[i];
    		int ny = p.y+dy[i];
    		if(nx >= 0 && ny >= 0  && nx < h && ny <w &&!vis[nx][ny]&& maze[nx][ny] != '#'){
                vis[nx][ny] =1 ;
                pos t2;
                t2.x =nx;
                t2.y =ny;
                t2.dist =p.dist+1;
                que.push(t2);
                //que.push((pos){nx,ny,p.dist+1});
    		}
    	}
    }




}

int main(){
 
   scanf("%d",&cases);
   while(cases--){
      scanf("%d%d",&w,&h);
      for (int i = 0; i < h; ++i)
      {
      	scanf("%s",maze[i]);
      	for (int j = 0; j < w; ++j)
      	{
      		if(maze[i][j] == 'S') {sx = i; sy = j;} 
      		else if(maze[i][j] == 'E'){ex = i ; ey = j;}
      	}
      }
      //cout<<sx<<" : "<<sy<<endl;
     int d1,d2;
     // if(sx==0)  {d1 = 2;d2 = 2;}
     // else if(sx==h-1) {d1 = 0;d2 = 0;}
     // else if(sy==0) {d1 = 1;d2 =3;}
     // else if(sy==w-1)   {d1= 3;d2=1;}

     if(sx == 0) { d1 = 3; d2 = 3; }
        else if(sx == h-1) { d1 = 1; d2 = 1; }
        else if(sy == 0) { d1 = 2; d2 = 0; }
        else if(sy == w-1) { d1 = 0; d2 = 2; }

      printf("%d ", dfs(sx, sy, 1, d1, dl));
      printf("%d ", dfs(sx, sy, 1, d2, dr));
      printf("%d\n", bfs(sx, sy));



 }

	return 0;
}
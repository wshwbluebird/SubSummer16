#include <iostream>
#include <string.h>
#include <cstdio>

using namespace std;

const int inf = 2501;

char map[51][51];
int node[51][51];//哈西 查询表查询 当前位置是否是字母 是第几个字母
int col,row;
int m;//记录迷宫顶点的数目

int dist[102][102]; //记录 各个顶点之间的 最短距离
int edge[102][102]; //构造两个字母之间的 边权
int num;

class move
{
public:
	int row,col;	
}mov[4]={{0,-1},{0,1},{-1,0},{1,0}};


void bfs(int i , int j){   //查询 坐标为 i j 的节点 到其他所有 地方的 最小距离
	int vist[51][51];//记录 当前的节点是否 已经被访问
	int qx[5000],qy[5000];
	int head = 0;
	int rear = 0;

	memset(vist,0,sizeof(vist));
	memset(dist,0,sizeof(dist));
	vist[i][j] = 1;
	qx[rear] = i;
	qx[rear++] = j;

	//start bfs

	while(head<rear){
		int x = qx[head];
		int y = qy[head++];

		if(node[x][y]) edge[node[i][j]][node[x][y]] = dist[x][y]; //表现广度优先搜索 作用的一句

		for (int i = 0; i < 4; ++i)
		{
			int mx = mov[i].row +x;
			int my = mov[i].col +y;
			if (mx>=1 && my>=1 && mx<=row && my<=col)
			{
				if (!vist[mx][my]&&map[x][y]!='#')
				{
					vist[mx][my] = 1;
					qx[rear] = mx;
					qy[rear++] = my;
					dist[mx][my] = dist[x][y] +  1;
				}
			}
		}
	}

}


void init(){
	 memset(node,0,sizeof(node));  
     num=0;  

     cin>>col>>row;
     char temp;
     cin>>temp;
     for (int i = 1; i <= row; ++i)
     {
     	//gets(map[i]) ;
     	for (int j = 1; j <= col+1; ++j)
     	{
     		if (map[i][j]=='A'||map[i][j]=='S')
     		{
     			 cin>>map[i][j];
     			 node[i][j]=++num;
     		}
     	}
     }

    //BFS  the  map
      for (int i = 1; i <= row; ++i)
      {
      	 for(int j=1 ;j<= col ; ++j)
      	 	if(node[i][j])  bfs(i,j);
      }

}



int prim(){
	int s = 1;
	int m = 1;

	int u[102];


	int min_w;
	int prim_w = 0;
	int point;
	int low_dis[102];

	for (int i = 1; i <=num; ++i)
	{
		low_dis[i] = inf;
		u[i] = 0;
	}
    

	while(m!=num){
		min_w = inf;
		for (int i = 2; i <=num; ++i){
			if(!u[i] && low_dis[i] > edge[s][i])
				  low_dis[i] = edge[s][i];
			if(!u[i] && min_w > low_dis[i]){
				min_w = low_dis[i];
                point = i;
			 }	
	}

        s= point ;
	    u[s] = 1;
        prim_w += min_w;
        m++;
    }
    return prim_w;

}

int main(){
     int test;  
    cin>>test;  
    while(test--){
    	init();
    	for (int i = 1; i <= row; ++i)
    	{
    		for (int j = 1; j <= col; ++i)
    		{
    			cout<<map[i][j];
    		}
    		cout<<endl;
    	}
    	//cout<<prim()<<endl;
    }

	return 0;
}
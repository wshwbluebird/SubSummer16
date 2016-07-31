#include <iostream>
#include <string.h>

using namespace std;

int w,h;
int board[21][21];
int sx,sy,ex,ey;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int ans = 1000000;
bool succ;
void dfs(int x,int y,int step){
	//cout<<"step: "<<step<<" :  "<<x<<" : "<<y<<" throwtime:"<<throwtime<<endl;
	if(step>10) return;

	//cout<<x<<" : "<<y<<endl;
	if(x==ex&&y==ey){
		if(ans > step)  ans = step;
		succ = true;
		return ;
	}
	
 
	for (int i = 0; i < 4; ++i)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		//cout<<"in   "  << nx<< " : "<<ny<<endl;
		//bool flag = 0;
		if(nx==ex&&ny==ey){
               if(ans > (step+1))  ans = step+1;
		          succ = true;
		          return ;
		}
		while(nx>0 && nx <= h  && ny >0 && ny <= w && board[nx][ny]!=1){
			nx += dx[i];
			ny += dy[i];

			if(nx==ex&&ny==ey){
               if(ans > (step+1))  ans = step+1;
		          succ = true;
		          return ;
			}
		}

		if(nx>0 && nx <= h && ny >0 && ny <= w&&board[nx][ny]==1){
			int tx = nx;
			int ty = ny;
			board[nx][ny] =  0;
			
			nx=nx-dx[i];
			ny=ny-dy[i];
			if(nx!=x||ny!=y){

			     //cout<<tx<<" : "<<ty<<"  &&    "<<nx<<" : "<<ny<<endl;
		         dfs(nx,ny,step+1);
                 //cout<<"step: "<<step<<endl;
            }
 
            board[tx][ty]= 1;
		}
	}
	//cout<<"end step: "<<step<<endl;


}


int main(){
    
  while(true) { 
    cin>>w>>h;
    if(!w&&!h) break;
    succ = false;
    ans = 99999999;
    memset(board,0,sizeof(board));
    for (int i = 1; i <=h; ++i)
    {
    	for (int j = 1; j <=w ; ++j)
    	{
    		cin>>board[i][j];
    		if(board[i][j]==2) {sx = i;sy=j;}
    		else if(board[i][j]==3){ex=i;ey=j;}
    	}
    }
    //cout<<sx<<" : "<<sy<<endl;
    //cout<<ex<<" : "<<ey<<endl;
    //cout<<"endinput"<<endl;
    dfs(sx,sy,0);
    if(succ&&ans<=10)
    cout<<ans<<endl; 
    else
    cout<<"-1"<<endl;	
}

	return 0;
}
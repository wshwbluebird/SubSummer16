#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
//OJ WA 不知道为什么 应该没次测试就是一组数据
int A,B,C;
int front = 0;
int rear = 0;
int qa[10005];
int qb[10005];
int fa[105][105];//记录上一个节点
int fb[105][105];
string info[105][105];

int cnt = 0;

void printi(int na,int nb){
	if(na==0&&nb==0){
		cout<<cnt<<endl;
		return;
	}
	cnt++;
	printi(fa[na][nb],fb[na][nb]);
	cout<<info[na][nb]<<endl;
	//scout<<na<<" : "<<nb<<endl;
}


void check(int na,int  nb){
       if(na==C||nb==C){
          printi(na,nb);
          exit(0);
       }
}

int main(){
	cin>>A>>B>>C;
	

	qa[rear] = 0;
    qb[rear++] = 0;
	fa[0][0] = 0;
	fb[0][0] = 0;
	bool vis[105][105];
	memset(vis,0,sizeof(vis));
	vis[0][0] =1;
	while(front!=rear){
		int ta = qa[front];
		int tb = qb[front++];
        
        //fill a
        int na = A;
        int nb = tb;
        if(!vis[na][nb]){
        	vis[na][nb] = 1;
        	fa[na][nb] = ta;
        	fb[na][nb] = tb;
        	info[na][nb] = "FILL(1)";
        	qa[rear] = na;
        	qb[rear++]=nb;
            check(na,nb);
            
        }

        //fill b
        na = ta;
        nb = B;
        if(!vis[na][nb]){
        	vis[na][nb] = 1;
        	fa[na][nb] = ta;
        	fb[na][nb] = tb;
        	info[na][nb] = "FILL(2)";
        	qa[rear] = na;
        	qb[rear++]=nb;
        	check(na,nb);
        }

        //drop a
        na = 0;
        nb = tb;
        if(!vis[na][nb]){
        	vis[na][nb] = 1;
        	fa[na][nb] = ta;
        	fb[na][nb] = tb;
        	info[na][nb] = "DROP(1)";
        	qa[rear] = na;
        	qb[rear++]=nb;
        	check(na,nb);
        }

        //drop b
        na = ta;
        nb = 0;
        if(!vis[na][nb]){
        	vis[na][nb] = 1;
        	fa[na][nb] = ta;
        	fb[na][nb] = tb;
        	info[na][nb] = "DROP(2)";
        	qa[rear] = na;
        	qb[rear++]=nb;
        	check(na,nb);
        }

        //Pour 1 to 2
        if(ta>=B-tb){
        	na = ta - (B-tb);
        	nb = B;
        }else{
        	na = 0;
        	nb = tb + ta;
        }
        if(!vis[na][nb]){
        	vis[na][nb] = 1;
        	fa[na][nb] = ta;
        	fb[na][nb] = tb;
        	info[na][nb] = "POUR(2,1)";
        	qa[rear] = na;
        	qb[rear++]=nb;
        	check(na,nb);
        }

        //Pour 2 to 1
        if(tb>=A-ta){
        	na = A;
        	nb = tb - (A-ta);
        }else{
        	na = na + nb;
        	nb = 0;
        }
        if(!vis[na][nb]){
        	vis[na][nb] = 1;
        	fa[na][nb] = ta;
        	fb[na][nb] = tb;
        	info[na][nb] = "POUR(2,1)";
        	qa[rear] = na;
        	qb[rear++]=nb;
        	check(na,nb);
        }



	}
	cout<<"impossible"<<endl;

	return 0;
}
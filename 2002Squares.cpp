#include <iostream>
#include <string.h>
#include <cstdio> 
#include <algorithm>
//跑 oj超时 不知道是什么问题
using namespace std;


const int maxn = 1001;
int n;
const int prime =19999;


int xp[maxn];
int yp[maxn];
int head[prime];
int nexte[maxn];


// int hash(int x,int y){
    
//      return  

// }

bool isthere(int x, int y){
	int h = ((x*x) +(y*y))%prime+1;

	    for (int e = head[h] ;e != -1; e = nexte[e])
        {
           if(x==xp[e]&&y==yp[e])  return true;
        }
	
	return false;
}




int main(){
	while(cin>>n){
		if(!n) return 0;
		memset(head,-1,sizeof(head));
	    int ans = 0;
    //memset(nexte,0,sizeof(nexte));
    
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d",&xp[i],&yp[i]);
        //cin>>xp[i]>>yp[i];
        //xp[i]+=20000 ,yp[i]+=20000;
        int h = (xp[i]*xp[i] + yp[i]*yp[i])%prime+1;
        nexte[i] = head[h];
        head[h] = i;
    }
    int mm = 0;
    for (int i = 1; i <= n-1; ++i)
    {
        for (int j = i+1; j <= n; ++j)
        {
             int dx = xp[i] - xp[j];
             int dy = yp[i] - yp[j];

             //int px1,py1,px2,py2;
             int px1 = xp[i] + dy;
             int px2 = xp[j] + dy;
             int py1 = yp[i] - dx;
             int py2 = yp[j] - dx;

             if(px1< maxn
                && px2< maxn
                && py1<maxn
                && py2<maxn
                &&isthere(px1,py1)
                &&isthere(px2,py2)) {
                ans++;
             //cout<<"ans" << ans<<endl;
            }

                //cout<<i<<endl;
        }
    }
           
           printf("%d\n",ans/2 );


    }
	return 0;
}

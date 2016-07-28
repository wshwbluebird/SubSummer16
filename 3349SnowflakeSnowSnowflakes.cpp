#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

typedef int State[6];
const int maxstate = 100001;
State snow[maxstate];
int head[120007];
int nexte[maxstate];

int n;

int hash_f(int i){
	int sum = 0;
	for (int j = 0; j < 6; ++j)
	{
		sum += snow[i][j];
	}

	return sum%120007 ;
}


int isSame(int a, int b)   
{  
    for(int i=0;i<6;i++)  
    {  
        if(/*顺时针方向*/  
            (snow[a][0] == snow[b][i] &&  
            snow[a][1] == snow[b][(i+1)%6] &&  
            snow[a][2] == snow[b][(i+2)%6] &&  
            snow[a][3] == snow[b][(i+3)%6] &&  
            snow[a][4] == snow[b][(i+4)%6] &&  
            snow[a][5] == snow[b][(i+5)%6])  
              
            ||  
            /*逆时针方向*/  
            (snow[a][0] == snow[b][i] &&  
            snow[a][1] == snow[b][(i+5)%6] &&  
            snow[a][2] == snow[b][(i+4)%6] &&  
            snow[a][3] == snow[b][(i+3)%6] &&  
            snow[a][4] == snow[b][(i+2)%6] &&  
            snow[a][5] == snow[b][(i+1)%6])  
            )  
              
            return 1;  
    }  
      
    return 0;  
}  


int insert_find(int i){
	int h = hash_f(i);
    
    for(int e = head[h]; e!=-1; e=nexte[e])
    	if(isSame(i,e))  return 1;
    	
     
    nexte[i] = head[h];
    head[h] = i;
    
    return 0;

}

int main(){
    memset(head,-1,sizeof(head));
    cin>>n;
    int flag = 0;
    for (int i = 0; i < n; ++i)
    {
    	for (int j = 0; j < 6; ++j)
    	{
    		// cin>>snow[i][j];
    		scanf("%d", &snow[i][j]);
    	}
    	
    	if(!flag){
    		flag = insert_find(i);
    		if(flag) {
    			cout<<"Twin snowflakes found."<<endl;
    			return  0;
    		}
    	}
    	
    }
   if(flag) cout<<"Twin snowflakes found."<<endl;
   else cout<<"No two snowflakes are alike."<<endl;


	return 0;
}

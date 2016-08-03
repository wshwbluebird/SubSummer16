#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;
//明明 给的数据 都过了  oj   WA
//不过我这个倒是什么算法都没用

int tran[28][28];
int ch[28];
int main(){
   int n;
   while(cin>>n){
   		if(!n) break;
   		int cnt = 0;
   		bool flag = true;
   	    
   		memset(tran,0,sizeof(tran));
   		memset(ch,0,sizeof(ch));
   		for (int i = 0; i < n; ++i)
   		{
   			char t ;
   			cin>>t;
   			int tt = t-'A';
   			getchar();//吃冒号
   			t =getchar();
   			while(t!='\n'){
   				tran[tt][t-'A']=1;
   				t=getchar();
   			}
   		}
   		//cout<<"tran   1 0   : "<<tran[1][0]<<endl;
   		
   		ch[0] = ++cnt;
        
   		for (int i = 1; i < n; ++i)
   		{
   			flag = true;
   			for (int j = 0; j < i; ++j)
   			{
   				if(!tran[i][j]) {
   					bool ff = true;
   					for (int k = j+1; k < i; ++k)
   					{
   						// //cout<<"j: k   "<<j<<" : "<<k<<endl;
   						// cout<<ch[j]<<endl;
   						// cout<<ch[k]<<endl;
   						// cout<<tran[i][k]<<endl;
   						// //cout<<flag<<endl;
   						if(ch[k]==ch[j]&&tran[i][k]){
   							ff=false;
   							break;
   						}
   					}
   					if(ff){
   						ch[i] = ch[j];
   						flag = false;
   						break;
   					}
   				} 				
   			}
   			if(flag)  ch[i]=++cnt;
   		}
   		if(cnt==1)
   		printf("%d channel needed.\n", cnt);
   	    else 
   	    printf("%d channels needed.\n", cnt);
   }

	return 0;
}
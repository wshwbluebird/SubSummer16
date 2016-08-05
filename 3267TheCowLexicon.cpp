#include <iostream>
#include <string.h>
using namespace std;

int W,L;
char dict[805][27];
char mess[500];
int dp[500];//表示从i到末为 需要删除的字符数

int main(){
    while(cin>>W>>L){
    	memset(mess,0,sizeof(mess));
    	memset(dict,0,sizeof(dict));
    	cin>>mess;
    	for (int i = 0; i < W; ++i)
    	{
    		cin>>dict[i];
    	}
    	memset(dp,0,sizeof(dp));


         //初始化  
    	dp[L] = 0;
        for (int i = L-1; i >=0 ; i--)
        {
        	dp[i] = dp[i+1]+1;
        	for (int j = 0; j < W; ++j) //逐个便利每个单词
        	{
        		int length = strlen(dict[j]);
        		if(L-i >= length  && dict[j][0] == mess[i] ){
        			int startm = i;
        			int startw = 0;
        			while(startm<L){
        				if(mess[startm++] == dict[j][startw])  startw++;
        				if(startw==length){
        					dp[i] = min(dp[i] , dp[startm] + startm-i-length);
        					break;
        				}
        			}
        		}
        	}
        }
        cout<<dp[0]<<endl;


    }



	return 0;
}
#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;
int len;
char s1[101];
char s2[101];
char s12[201];

int main(){
   int cases;
   cin>>cases;
   int cc = 0;

   while(cc!=cases){
     cin>>len; 
     int ans = 0;
     memset(s1,0,sizeof(s1));
     memset(s2,0,sizeof(s2));
     memset(s12,0,sizeof(s12));
     scanf("%s",s1);
     scanf("%s",s2);
     scanf("%s",s12);
     char temp1[101];
     char temp2[101];
     char temp12[201];
     for (int i = 0; i < len*2; ++i)
      {
      	 temp12[i] = i%2==0? s2[i/2]:s1[i/2];
      } 
         temp12[2*len]='\0';
         //cout<<endl;
         //cout<<temp12<<endl;
         //cout<<s12<<endl;
     while(true){
        ans++;
     	if(strcmp(temp12,s12)==0) break;
     	int point=0;
     	while(point<len){
     		temp1[point] = temp12[point];
     		point++;
     	}
     	//cout<<"temp1:  "<<temp1<<endl;
     	temp1[len] = '\0';
     	while(point<2*len){
     		temp2[point-len] = temp12[point];
     		point++;
     	}
     	temp2[len] = '\0';
     	//cout<<"temp2:  "<<temp2<<endl;
     	if(strcmp(s1,temp1)==0&&(strcmp(s2,temp2)==0))
     	{
     		ans = -1;
     		break;
     	}
         //cout<<strcmp(s1,temp12)
     	for (int i = 0; i < len*2; ++i)
        {
      	    temp12[i] = i%2==0? temp2[i/2]:temp1[i/2];
        } 
        temp12[2*len]='\0';
        //cout<<"temp12:  "<<temp12<<endl;
     } 

     cout<<(++cc)<<" "<<ans<<endl;




   }

	return 0;
}
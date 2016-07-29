#include <iostream>
#include <string.h>

using namespace std;

short hash[25000001];//精髓  学会用更短的 数据类型 表示较大的数组
//很简单的hash 不用链表

int main(){
   
   int a1,a2,a3,a4,a5;
   cin>>a1>>a2>>a3>>a4>>a5;

   int x1,x2,x3,x4,x5;
   memset(hash,0,sizeof(hash));

   for (x1 = 1; x1 <= 50 ; ++x1)
   {
   	   for (x2 = -50; x2 <= 50; x2++)
   	   { 
   	   	 if(!x2) continue;
   	   	 int sum = a1*x1*x1*x1 + a2*x2*x2*x2;
   	   	 sum =sum * (-1);
         if(sum<0)
         	sum += 25000000;
         if(sum<25000000)hash[sum]++;
   	   }
   }
    int solution = 0;
   for (x3 =-50 ; x3 <= 50; ++x3)
   {
   	  if(!x3) continue;
   	  for (x4 =-50 ; x4 <= 50; ++x4)
          {
   	          if(!x4) continue;
   	          for (x5 =-50 ; x5 <= 50; ++x5)
                 {
                     if(!x5) continue;
                     int sum = a3*x3*x3*x3  +a4*x4*x4*x4  + a5*x5*x5*x5;
                     if(sum<0)
         	         sum += 25000000;
                     if(sum <= 25000000 && hash[sum])
                     	solution += hash[sum];
                 }
          }
   }

    cout<<solution*2<<endl;

	return 0;
}
#include <iostream>
#include <string.h>

using namespace std;

__int64 ans;
int n;
int num[500005];
int t[500005];
void merge_sort(int *A , int p,int r,int *T){
	if(p>=r)  return ;

	int m = (p+r)/2;

	merge_sort(A,p,m,T);
	merge_sort(A,m+1,r,T);

    int i = p, k = p;
    int j = m+1;
	while(i<=m || j <=r){
		if(j>r ||(A[i]<= A[j] && i<=m))  T[k++] = A[i++]; //注意变相 哨兵

		else {ans += m-i+1; T[k++] = A[j++];}
	}
	for (int  w= p; w <= r; ++w)
	{
		A[w] = T[w];
	}
}



int main(){
   

   while(cin>>n){
   	   if(!n) break;

   	   memset(num,0,sizeof(num));
   	   memset(t,0,sizeof(t));
   	   ans =  0;
       for (int i = 1; i <= n; ++i)
          {
   	       cin>>num[i];
          }
          merge_sort(num,1, n ,t);
          cout<<ans<<endl;
       }
	return 0;
}
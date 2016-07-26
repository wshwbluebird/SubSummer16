#include <iostream>
#include <string.h>
#include <cstdio>

using namespace std;
const int maxn =27;

int G[maxn][maxn];
int q[maxn];
int indegree[maxn];

int toposort(int n){
    int c = 0;
    int flag = 1; //表示 结果  1代表确定  0代表失败  －1代表目前无序
    int temp[maxn];
    int loc;
    for (int i = 1; i <= n; ++i)
    {
        temp[i] = indegree[i];
    }

    for (int i = 1; i <= n; ++i)
    {

         int m = 0;
        for (int j = 1; j <= n; ++j)
        {
            if(!temp[j]) {m++; loc = j;}
        }
            if(!m) return 0;
            if(m>1) flag = -1;
            q[c++] = loc;
            temp[loc] = -1;

            for (int k = 1; k <= n; ++k)
            {
                if(G[loc][k])   temp[k]--;
            }            
    }
    return flag;
}




int main(){
    //Declaring
    int m,n;
    int sign ;//表示是否已经确定状态


    //Initialized
    
    char str[5];
    while(true){
        cin>>n>>m;
        memset(G,0,sizeof(G));
        memset(indegree,0,sizeof(indegree));
        sign=0;

        if(n==0&&m==0)  break;
        for (int i = 1; i <= m; ++i)
        {
            scanf("%s",str);
            if(sign) continue;
            int x = str[0] - 'A' +1;
            int y = str[2] - 'A' +1;
            G[x][y] = 1;
            indegree[y]++;

            int s = toposort(n);

            if(s==0) {
                printf("Inconsistency found after %d relations.\n",i);
                sign=1;
            }

            if(s==1){
                printf("Sorted sequence determined after %d relations: ",i);
                for(int j=0;j<n;j++)
                    printf("%c",q[j]+'A'-1);
                printf(".\n");
                sign=1;
            }

        }
        if(!sign)
             printf("Sorted sequence cannot be determined.\n");   
        
    }

    return 0;
}
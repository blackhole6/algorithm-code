//TSP问题 最短旅行商 从0点出发然后回到0点最小花费
#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
int dis[12][12],f[1<<12][12],pos[1<<12][12];
int main()
{
        int n,m;
    	scanf("%d%d",&n,&m);
    	int xx,yy,ww;
    	for(int t=0;t<m;t++)
    	{
    		scanf("%d%d%d",&xx,&yy,&ww);
    		dis[xx][yy]=ww;
    		dis[yy][xx]=ww;
		}
        int b=1<<(n-1);
        memset(f,-1,sizeof(f));
        for(int i=0;i<n;i++) 
            f[0][i]=dis[i][0]; 
        for(int st=1;st<b-1;st++){
            for(int i=1;i<n;i++){
                if(st&(1<<(i-1)))continue; 
                int minn=INF;
                for(int j=1;j<n;j++){  
                    if(st&(1<<(j-1))){  
                        int tmp=dis[i][j]+f[st^(1<<(j-1))][j]; 
                        if(tmp<minn){
                            minn=tmp;
                            f[st][i]=tmp;
                        }
                    }
                }
            }
        }
        int minn=INF;
        for(int k=1;k<n;k++){
            int tmp=f[(b-1)^(1<<(k-1))][k]+dis[0][k];
            if(tmp<minn)
                minn=tmp,f[b-1][0]=tmp,pos[b-1][0]=k;;
        }
        if(f[b-1][0]!=INF)
        printf("%d\n",f[b-1][0]);
        else
        {
        	puts("-1");
		}
    return 0;
}
 
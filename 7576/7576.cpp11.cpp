#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;
int arr[1001][1001];

int main()
{
    int N,M;
    scanf("%d %d",&N,&M);
    queue<pair<int,int> > q;

    
    int cnt=0; 
    int reap=0;
    int time=1;

    for(int i =1;i<=M;i++)
    {
        for(int j =1;j<=N;j++)
        {
            scanf("%d", &arr[i][j]);
            if(arr[i][j]==1)
            {
                q.push(make_pair(i,j));
                reap++;
                cnt++;
            }else if(arr[i][j]==0){
                cnt++;
            }
        }
    }



    int dx[]= {-1,1,0,0,};
    int dy[] ={0,0,1,-1};
    
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        cnt--;
        for(int i =0;i<4;i++)
        {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx >= 1 && nx <= M &&  ny >= 1 && ny <=N)
            {
                if(arr[nx][ny] ==0)
                {
                    arr[nx][ny]  = arr[x][y] +1;
                    if(time < arr[nx][ny])
                        time = arr[nx][ny];
                    
                    q.push(make_pair(nx,ny));
                }
            }
        }
    }

    if(cnt==0)
    {
        printf("%d",time-1);
    }else{
        printf("%d",-1);
    }


    return 0;    
}

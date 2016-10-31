#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

int arr[101][101];
bool  v[101][101];
queue<pair<int,int> > q;

void bfs(int N,int M)
{
    if(arr[0][0]){          
        v[0][0] = true;
        q.push(make_pair(0,0));
    }


    while(!q.empty())
    {
        int f = q.front().first;
        int s = q.front().second;
        q.pop();
        int cur= arr[f][s];

        if( arr[f][s+1]==1 && s+1 < N && !v[f][s+1]){
                arr[f][s+1] = cur+1;
                q.push(make_pair(f,s+1));
        }

        if(arr[f][s-1]==1 && s-1 >=0 && !v[f][s-1]){
                arr[f][s-1] = cur+1;
                q.push(make_pair(f,s-1));
        }

        if(arr[f+1][s]==1 && f+1 < M && !v[f+1][s]){
                arr[f+1][s] = cur+1;
                q.push(make_pair(f+1,s));
        }

        if(arr[f-1][s]==1 && f-1 >=0 && !v[f-1][s]){
                arr[f-1][s] = cur+1;
                q.push(make_pair(f-1,s));
        }

        
        if(!v[f][s])
        {
            v[f][s] = true;
            if(f+1==M &&s+1==N){
                break;
            }
        }
    }
}

int main()
{
    int N, M;
    cin >> N >> M;
    for(int y=0;y<N;y++)
    {
        for(int x=0;x<M;x++)
        {
            scanf("%1d", &arr[x][y]);
        }
    }
    bfs(N,M);
    printf("%d\n", arr[M-1][N-1]);
    return 1;
}

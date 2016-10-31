#include <math.h>
#include <iostream>
#include <queue>

using namespace std;
int v[100001];

int bfs(int s, int e)
{
    int x,_cnt;
    queue<pair<int, int> > q;

    q.push(make_pair(s,0));

    while(!q.empty())
    {
        x=q.front().first;
        _cnt=q.front().second; 
        q.pop();
        if(x==e)
            return _cnt;

        _cnt++;
            if(x > e){
                if(!v[x-1]){
                    q.push(make_pair(x-1,_cnt));
                    v[x-1] =true;
                }
            }else{
                if(x*2 < e+2){
                    if(!v[2*x]){
                         q.push(make_pair(2*x,_cnt));
                         v[2*x] = true;
                    }
                }
                if(!v[x-1]){
                    q.push(make_pair(x-1,_cnt));
                    v[x-1]=true;
                }
                if(!v[x+1]){
                    q.push(make_pair(x+1,_cnt));
                    v[x+1]=true;
                }
            }
            
    }
    return 0;
}
int main()
{
    int s,e;
    cin >> s >>e;
    cout << bfs(s,e) << endl;
    return 0;
}

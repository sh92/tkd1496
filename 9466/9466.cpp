#include <cstdio>

int a[100001];
int v[100001];
bool cycle[100001]; 


void make_cycle(int x)
{
    if(cycle[x])
        return;
    cycle[x]=true;
    make_cycle(a[x]);
}


int dfs( int x, int start)
{
    if(cycle[x] || v[x]) 
    {
        return 0;
    }

    v[x] = start;
    if(v[a[x]] == start)
       return x; 

    return dfs(a[x], start);
}

int main()
{
    int T;
    scanf("%d", &T);

    while(T--)
    {
        int n;
        scanf("%d", &n);

        for(int i =1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            cycle[i]=false;
            v[i] = 0;
        }


        int sum=0;

        for(int i=1;i<=n;i++)
       {
           if(v[i]==0){
                int t= dfs(i,i);
                if(t){
                     make_cycle(t);
                 }
            }
        }
        
        for(int i=1;i<=n;i++)
        {
            if(!cycle[i])
                sum++;
        }
        printf("%d\n", sum);

    }
    return 0;
}

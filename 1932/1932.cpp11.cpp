#include <cstdio>
using namespace std;


int tri[501][501]; 
int D[501][501];

int main()
{
    int  n;
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i+1;j++){
            scanf("%d", &tri[i][j]);
        }
    }


    D[0][0] = tri[0][0]; 

    for(int i=0;i<n;i++)
    {
       for(int j=0;j<i+1;j++)
       {
            if(D[i+1][j] < D[i][j]+tri[i+1][j])
            {
                D[i+1][j] = D[i][j]+tri[i+1][j];
            }    
          
            if(D[i+1][j+1] < D[i][j]+tri[i+1][j+1])
            {
                D[i+1][j+1] = D[i][j]+tri[i+1][j+1];
            }
       }
    }

    int Maxsum=0;
    for(int i=0;i<n;i++)
    {
        if(Maxsum < D[n][i])
        {
            Maxsum = D[n][i];
        }
    }
    
    printf("%d\n", Maxsum);

    return 0;
}

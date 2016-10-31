#include <cstdio>

int memo[41];
int zero[41];
int one[41];

void fibonacci(int n)
{
    zero[0] = 1;
    one[1] = 1;

    for(int i=2; i<=n;i++){
        zero[i] = zero[i-1]+zero[i-2];
        one[i] = one[i-1] + one[i-2];
    }
    return ;
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n,r;
        scanf("%d",&n);
        fibonacci(n);
        printf("%d %d\n", zero[n], one[n]);

    }
    return 1;
}

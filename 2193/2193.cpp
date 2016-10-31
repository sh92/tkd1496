#include <iostream>
#include <cstdio>

using namespace std;
long long D[91][2];

long long count(int n){

    D[1][1]=1;
    D[2][0]=1;

    for(int i=3;i<=n;i++)
    {
        D[i][1]=D[i-1][0];
        D[i][0]=D[i-1][0]+D[i-1][1];
    }
    return D[n][0]+D[n][1];
}

int main(){
    int n;

    scanf("%d", &n);

    printf("%lld",count(n));
    return 0;
}
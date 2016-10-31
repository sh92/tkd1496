#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int arr[10001];

int main()
{
    int N;
    cin >> N;

    for(int i=0;i<N;i++)
    {
        scanf("%d", &arr[i]);
    }

    sort(arr,arr+N);
    int sum[N];
   
    sum[0]=arr[0];
    for(int i=1;i<N;i++)
    {
        sum[i]=(sum[i-1]+arr[i]);
    }

    int totalSum=0;
    for(int i=0;i<N;i++)
    {
        totalSum +=sum[i];
    }

    printf("%d", totalSum);

    
    return 1;
}


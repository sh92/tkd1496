#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int A[10000001];
int arr[11]; 

bool cmp(int a, int b){return a>b;};

int main()
{
    int N,K;

    cin >> N >> K;
    int tt = K;
    int cnt=0;

    for(int i =0;i<N;i++)
    {
        scanf("%d", &arr[i]);
    }

    sort(arr,arr+N,cmp);


    for(int i =0;i<N;i++)
    {
        if(tt == 0 ) break;
        while(tt!=0){
            if(tt >= arr[i]){
                tt -= arr[i];
                cnt++;
            }else{
                break;
            }
        }
    }
    printf("%d",cnt);

    return 0;
}

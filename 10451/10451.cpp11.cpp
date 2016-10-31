#include <iostream>

using namespace std;

int a[1001];
bool c[1001];

void dfs(int x)
{
    if(c[x]) return;
    c[x] = true;
    dfs(a[x]);
}


int main()
{
    int T;
    scanf("%d", &T);

    while(T--){
        int N;
        cin >> N;

        for(int j =1;j<=N;j++)
        {
            cin >> a[j];
            c[j] = false;
        }

        int ans = 0;
        for(int i=1;i<=N;i++)
        {
            if(c[i]==false)
            {
                dfs(i);
                ans +=1;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}

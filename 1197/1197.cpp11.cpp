#include <cstdio>
#include <queue>
#include <tuple>
using namespace std;
#define Edge tuple<int,int, int>
#define MAX_N 100001


int V[10001];
int E[100001];
int par[MAX_N];
int ranking[MAX_N];


void init(int n)
{
   for(int i =0;i<n;i++)
   {
      par[i] =i;
      ranking[i] = 0;
   }
}

int find(int x)
{
   if(par[x] == x)
   {
      return x;
   }else{
      par[x] =find(par[x]);
      return par[x];
   }
}

void unite(int a, int b)
{
   a = find(a);
   b = find(b);
   if(a ==b)
      return ;
   if(ranking[a] < ranking[b])
   {
      par[a] = b;
   }else{
      par[b] = a;
      if(ranking[a] == ranking[b])
         ranking[a]++;
   }
}

int notCycle(int a, int b)
{
   if(find(a) == find(b))
   {
      return 0;
   }else{
      return 1;
   }
}


struct Order
{
   bool operator()(Edge const& a,Edge const& b) const
   {
      return get<2>(a) > get<2>(b);
   }
};

int main()
{
   int V,E;
   int weightSum=0;
   scanf("%d %d", &V, &E);
   priority_queue<Edge, vector<Edge>, Order> minHeap;
   for(int i =0;i<E;i++)
   {
      int from,to,weight;
      scanf("%d %d %d\n",&from, &to, &weight);

      auto t= make_tuple(from,to,weight);
      minHeap.push(t);
   }
   int cnt=0;
   init(V);
   while(cnt!=V-1)
   {
      auto top = minHeap.top();
      minHeap.pop();
      int c1 = get<0>(top);
      int c2 = get<1>(top);

      while(notCycle(c1,c2))
      {
         cnt++;
         unite(c1,c2);
         weightSum += get<2>(top);
      }
   }


   printf("%d\n", weightSum);


   return 0;
}

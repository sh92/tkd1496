#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
  int N;
  scanf("%d", &N);
  char s1[]="KBS1";
  char s2[]="KBS2";
  int p=0,q=0;

  for(int i =0;i<N;i++){
    char str[10];
    scanf("%s",str);


    if(strcmp(str,s1)==0)
    {
        p = i;
    }else if(strcmp(str,s2)==0)
    {
        q = i;
    }
  }
  if(p==1)
  {
    printf("%d",3);
    if(q==0){
    }else if(q==2){
      printf("%d",3);;
    }else{
      for(int i =0;i<q-1;i++){
        printf("%d",1);
      }
      for(int i =0;i<q-1;i++){
        printf("%d",4);
      }
    }
  }else{
    if(p<q)
    {
      for(int i =0;i<p;i++){
        printf("%d",1);
      }
      for(int i =0;i<p;i++){
        printf("%d",4);
      }
      for(int i =0;i<q;i++){
        printf("%d",1);
      }
      for(int i =0;i<q-1;i++){
        printf("%d",4);
      }
    }else if(p>q){
      for(int i =0;i<q;i++){
        printf("%d",1);
      }
      for(int i =0;i<q;i++){
        printf("%d",4);
      }
      for(int i =0;i<p;i++){
        printf("%d",1);
      }
      for(int i =0;i<p;i++){
        printf("%d",4);
      }
    }
  }
  return 0;
}

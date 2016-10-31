#include <iostream>
using namespace std;


int main(){
  int T;
  int v;
  long long a[100];
  
  cin >> T;
  
  while(T--){
    cin >> v;
      a[0]=1;
      a[1]=1;
      a[2]=1;
    if(v==1 || v==2 || v==3){
      cout <<  a[v-1] << endl;
    }else{
      for(int i=3;i<v;i++){
        a[i]=0;
      }
      for(int i=3;i<v;i++){
        a[i] = a[i-2] +a[i-3];
      }
      cout << a[v-1] << endl;    
    }
  }
  return 0;
}

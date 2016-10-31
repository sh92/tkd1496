#include <cstdio>
#include <iostream>
using namespace std;

int main(){

    int N;
    cin >>N;
    if(N <0 || N> 100000)
        return -1;
    for(int i =0;i<N;i++)
        cout << (i+1) <<endl;
    return 0;
}
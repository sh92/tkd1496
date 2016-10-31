#include <iostream>
#include <cstdio>
#include <string>

using namespace std ;



void sort(int len, string* a){

    int i ,j;
    
    for(int i =0; i<len; i++)
    {
        for(int j=i+1;j<len;j++){
            

            if(a[i]> a[j])
            {
                string temp =  a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    
        
}
int main(){

    string s;
    cin >> s;

    int len = s.length();


    string* sa =  new string[len];

    
    for(int i =0;i<len;i++)
    {
        sa[i]= s.substr(i,len-i);
    }
    sort(len,sa);

    for(int i =0;i<len;i++)
    {
        cout << sa[i] << endl;
    }

    
    return 0;
}



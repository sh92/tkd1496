
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int isPalindrome(char* s,int len){
    
    if(len <1)
        return 1;
    
    if(*s != *(s+len))
        return 0;
    else
        return isPalindrome(s+1,len-2);
    
    
}

int main(){
    
    char s[1001];
    cin >> s;
    
    printf("%d", isPalindrome(s , strlen(s)-1));
    return 0;
}

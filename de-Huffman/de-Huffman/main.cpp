#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

void cnt(string code,string input[256]){
    if (code.length()!=0) {
        int i,j;
        for (i=code.length()-1; i!=0; i--) {
            for (j=0; j!=256; j++) {
                if(code.substr(0,i)==input[j]){
                    cout<<(char)j;
                    break;
                }
            }
            if(j!=256){
                cnt(code.substr(i,code.length()-i),input);
            }
        }
    }
}

int main( ) {
    string input[256];
    string code;
    char tmp;
    string output;
    
    for (int i=0; i!=256; i++) {
        
        cin>>input[i];
        
    }
    
    while(scanf("%c",&tmp) != EOF) {
        code=code+tmp;
    }
    
    cnt(code, input);
    return 0;
    
}

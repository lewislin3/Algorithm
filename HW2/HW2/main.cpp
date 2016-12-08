#include <iostream>
#include <stdlib.h>
using namespace std;

int main( ) {
    
    int enter[100];
    int l=0;
    int i=0,j=0;
    int max=0;
    int tmp=0;
    
    while (scanf("%d",&enter[l])==1) {
        l++;
    }
    for (i=1; i!=l+1; i++) {
        for (j=0; j!=l-i+1;j++) {
            for (int c=j;c!=j+i; c++) {
                tmp=tmp+enter[c];
            }
            if(max==0){
                max=tmp;
            }
            else{
                if (max<tmp) {
                    max=tmp;
                }
            }
            tmp=0;
        }
    }
    cout<<max;
    
    
    
    return 0;
}

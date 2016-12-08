
#include <iostream>
#include <cstdlib>
#include <stdio.h>
using namespace std;

int subarray(int enter[1000],int length){
    
    int ans=0;
    int tmp=0;
    
    for (int i=0; i<=length; i++) {
        //cout<<enter[length]<<endl;
        tmp=tmp+enter[i];
        
        if (tmp<=0) {
            tmp=0;
        }
        
        if(tmp>=ans){
            ans=tmp;
        }
        
    }
    
    return ans;
}

int main(){
    int enter[1000];
    int tmp;
    int length;
    int ans;
    length=0;
    tmp=0;
    
    for(int i=0; ; i++) {
        //cout<<",,,"<<tmp;
        if (scanf("%d",&tmp)==1) {
            length=i;
        }
        else{
            break;
        }
        enter[length]=tmp;
        length++;
        tmp=0;
    }
    //cout<<length<<endl;;
    ans=subarray(enter, length);
    cout<<ans;
    
    return 0;
    
    
}

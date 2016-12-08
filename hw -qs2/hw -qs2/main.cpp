#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

void Quicksort(int length,int word[10000]){
    
    
    int p=0;
    int left[10000];
    int right[10000];
    int l=0,r=0;
    
    if ((word[0]>=word[length/2] && word[length/2]>=word[length-1])||(word[0]<=word[length/2] && word[length/2]<=word[length-1])) {
        p=length/2;
    }
    else if ((word[length/2]>=word[0] && word[0]>=word[length-1])||(word[length/2]<=word[0] && word[0]<=word[length-1])){
        p=0;
    }
    else{
        p=length-1;
    }
    
    
    for (int i=0; i!=length; i++) {
        if(i!=p){
            if(word[i]<=word[p]){
                
                left[l]=word[i];
                l++;
            }
            if (word[i]>word[p]) {
                right[r]=word[i];
                r++;
            }
        }
    }
    
    
    if (length==1) {
        cout<<word[0]<<" ";
    }
    
    else{
        if (l!=0)
            Quicksort(l, left);
        cout<<word[p]<<" ";
        if(r!=0)
            Quicksort(r, right);
    }
    
    
}






int main() {
    
    int word[10000];
    
    int length=0;
    for (int i=0; ; i++) {
        if(scanf("%d",&word[i])==1){
            length=i;
        }
        else{
            break;
        }
    }
    length++;
    time_t begin;
    begin=clock();
    
    Quicksort(length, word);
    cout<<clock()-begin;
    system("pause");
    return 0;
    
    
}

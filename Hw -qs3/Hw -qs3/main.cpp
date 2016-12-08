#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

void Quicksort(int length,int word[10000]){
    
    int p;
    int left[10000];
    int right[10000];
    int l=0,r=0;
    
    int m1,m2,m3;
    
    if ((word[0]>=word[length/9] && word[length/9]>=word[length*2/9])||(word[0]<=word[length/9] && word[length/9]<=word[length*2/9])) {
        m1=length/9;
    }
    else if ((word[length/9]>=word[0] && word[0]>=word[length*2/9])||(word[length/9]<=word[0] && word[0]<=word[length*2/9])){
        m1=0;
    }
    else{
        m1=length*2/9;
    }

    
    if ((word[length*3/9]>=word[length*4/9] && word[length*4/9]>=word[length*5/9])||(word[length*3/9]<=word[length*4/9] && word[length*4/9]<=word[length*5/9])) {
        m2=length*4/9;
    }
    else if ((word[length*4/9]>=word[length*3/9] && word[length*3/9]>=word[length*5/9])||(word[length*4/9]<=word[length*3/9] && word[length*3/9]<=word[length*5/9])){
        m2=length*3/9;
    }
    else{
        m2=length*5/9;
    }
    
    if ((word[length*6/9]>=word[length*7/9] && word[length*7/9]>=word[length*8/9])||(word[length*6/9]<=word[length*7/9] && word[length*7/9]<=word[length*8/9])) {
        m3=length*7/9;
    }
    else if ((word[length*6/9]>=word[length*8/9] && word[length*8/9]>=word[length*7/9])||(word[length*6/9]<=word[length*8/9] && word[length*8/9]<=word[length*7/9])){
        m3=length*8/9;
    }
    else{
        m3=length*6/9;
    }
    
    if ((word[m1]>=word[m2] && word[m2]>=word[m3])||(word[m1]<=word[m2] && word[m2]<=word[m3])) {
        p=m2;
    }
    else if ((word[m2]>=word[m1] && word[m1]>=word[m3])||(word[m2]<=word[m1] && word[m1]<=word[m3])){
        p=m1;
    }
    else{
        p=m3;
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

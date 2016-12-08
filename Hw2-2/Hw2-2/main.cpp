#include <iostream>
#include <stdlib.h>
using namespace std;

int algorithm(int num[100],int k){
    
    int n = k;
    int a=0,b=0;
    int sum=0;
    
    if (k<=0) {
        return 0;
    }
    if(k == 1){
        return num[0];
    }

        for (int i=0; i!=k; i++) {
            sum=sum+num[i];
        }
        
        int m = n / 2;
        int left[100];
        int right[100];
        
        for (int i=0; i!=k; i++) {
            if(i<m){
                left[a]=num[i];
                a++;
            }
            else{
                right[b]=num[i];
                b++;
            }
        }
        
        int leftsum=algorithm(left,a);
        int rightsum=algorithm(right,b);
        
        if ((leftsum>=rightsum&&rightsum>=sum)||(leftsum>=sum&&sum>=rightsum)) {
            return leftsum;
        }
        else if((sum>=leftsum&&leftsum>=rightsum)||(sum>=rightsum&&rightsum>=leftsum)){
            return sum;
        }
        else{
            return rightsum;
        }
    
    
    
    

    
}

int main( ) {
    int enter[100];
    int k=0;
    int devide=0;
    int midsum=0;
    int sum=0;
    int ans=0;
    while (scanf("%d",&enter[k])) {
        k++;
    }
    devide=algorithm(enter,k);
    for (int i=0; i!=k/2; i++) {
        for (int j=k/2+1; j!=k; j++) {
            for (int l=i; l!=j; l++) {
                midsum=midsum+enter[l];
            }
            if (sum==0) {
                sum=midsum;
            }
            else{
                if (midsum>sum) {
                    sum=midsum;
                }
            }
            midsum=0;
        }
    }
    
    if (sum>devide) {
        cout<<sum;
    }
    else{
        cout<<devide;
    }
    
    
    
    
    return 0;
}

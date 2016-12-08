#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

int max_subarray(int enter[ ],int size){
    int now_sum=0;
    int ans=0;
    
    for (int i=0; i!=size; i++) {
        now_sum=now_sum+enter[i];
        if (now_sum<0) {
            now_sum=0;
        }
        else{
            if (now_sum >= ans) {
                ans=now_sum;
            }
        }
    }
    return ans;
}

int main() {
    int enter [10000];
    int length=0;
    for (int i=0; ; i++) {
        if(scanf("%d",&enter[i])==1){
            length=i;
        }
        else{
            break;
        }
    }
    cout<<max_subarray(enter,length+1);
    
    system("pause");
    return 0;



}

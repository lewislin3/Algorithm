#include <iostream>
#include <cstdlib>

using namespace std;

struct town{
    int name;
    int connect[10]={0};
    int weight[10]={0};
    
};


int main() {
    int townnum;
    int connum;
    
    cin>>townnum;
    cin>>connum;
    
    town towns[10];
    
    
    int lf,rt,w;
    
    for (int i=0; i!=connum; i++) {
        //cout<<"yes"<<endl;
        cin>>lf;
        cin>>rt;
        cin>>w;
            towns[lf].connect[rt]=1;
            towns[lf].weight[rt]=w;
            towns[rt].connect[lf]=1;
            towns[rt].weight[lf]=w;
    }
    
   
    
    
    
    int range;
    cin>>range;
    int speed;
    cin>>speed;
    int source;
    cin>>source;
    int dest;
    cin>>dest;
    
    
    
    int townw[10]; //towns walk weight
    
    int walked[10];// visited or not
    
    int from[10];//where does it from
    
    for (int i=0; i!=10; i++) {
        townw[i]=999999999;
        walked[i]=0;
        from[i]=-1;
    }
    townw[source]=0;
    walked[source]=1;
    from[source]=source;
    
    
    
    int now=source;
    for (int k=0; k!=townnum; k++){
        walked[now]=1;
        
        for (int i=0; i!=townnum; i++) {
            if (towns[now].connect[i]==1 && walked[i]==0) {
                if (townw[i]>townw[now]+towns[now].weight[i] && towns[now].weight[i]<range) {
                    townw[i]=townw[now]+towns[now].weight[i];
                    from[i]=now;
                }
            }
           
        }
        for (int i=0; i!=townnum; i++) {
            if (walked[i]==0) {
                now=i;
            }
        }
        for (int i=0; i!=townnum; i++) {
            if(townw[i]<townw[now] && walked[i]==0){
                now=i;
            }
        }
        
        
        
    }
    int ans[100];
    int count=0;
    for (int i=dest; i!=source; ) {
        ans[count]=i;
        i=from[i];
        count++;
    }
    ans[count]=source;
 
    cout<<"Route:";
    for (int i=count; i!=-1; i--) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    cout<<"Total distance:";
    cout<<townw[dest]<<endl;
    cout<<"Estimation time:";
    cout<<(float)townw[dest]/speed<<endl;
    
    
    
    return 0;
}

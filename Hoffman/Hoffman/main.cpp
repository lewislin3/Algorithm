#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <cstdlib>
#include <string>
#include <bitset>
using namespace std;

struct node{
    unsigned fre;
    unsigned key;
    node* lchild;
    node* rchild;
};
string ans[256];

void ansbit(node b,string c){
    
    string cl,cr;
    if (b.lchild==NULL && b.rchild==NULL) {
        ans[b.key]=c;
    }
    else{
        cl=c+'0';
        cr=c+'1';
        ansbit(*b.lchild,cl);
        ansbit(*b.rchild,cr);
        
    }
    
    
};

int main() {
    unsigned char input[2048];
    int frequency[256]={0};
    long int count=0;
    
    while(scanf("%c",&input[count]) != EOF) {
        frequency[input[count]]++;
        count++;

    }
    
    
    
    
    
    node start[256];
    node combine[256][256];
    
    
    for (int i=0; i!=256; i++) {
        start[i].fre=frequency[i];
        start[i].lchild=NULL;
        start[i].rchild=NULL;
        start[i].key=i;
    }
    
    for (int i=0; i!=256; i++) {
        for (int j=0; j!=255; j++) {
            if (start[j].fre > start[j+1].fre) {
                node tmp;
                tmp=start[j];
                start[j]=start[j+1];
                start[j+1]=tmp;
            }
        }
    }
    for (int i=0; i!=256; i++) {
        combine[0][i]=start[i];
    }
    
    int k=255;
    for (int i=1; i!=256; i++) {
        combine[i][0].lchild=&combine[i-1][0];
        combine[i][0].rchild=&combine[i-1][1];
        combine[i][0].fre=combine[i-1][0].fre+combine[i-1][1].fre;
        combine[i][0].key=999;
        
        for (int j=1; j!=k; j++) {
            combine[i][j]=combine[i-1][j+1];
        }
    
            for (int n=0; n!=k-1; n++) {
                if (combine[i][n].fre >= combine[i][n+1].fre) {
                    node tmp;
                    tmp=combine[i][n];
                    combine[i][n]=combine[i][n+1];
                    combine[i][n+1]=tmp;
                }
            }
        
        k--;
    }
    
    string bitt;
    ansbit(combine[255][0],bitt);
    
    
    
    /*for (int i=0; i!=256; i++) {
        cout<<"-"<<i<<"-"<<endl;
        for (int j=0; j!=256-i; j++) {
            cout<<combine[i][j].key<<"-"<<combine[i][j].fre;
            if (combine[i][j].lchild!=NULL) {
                cout<<"("<<combine[i][j].lchild->key<<"-"<<combine[i][j].rchild->key<<endl;
            }
            else{
                cout<<endl;
            }
        }
        cout<<"///////////"<<endl;

    }*/
    
    for (int i=0; i!=256; i++) {
        cout<<ans[i]<<endl;
    }
    
    
    for (int i=0; i!=count; i++) {
        cout<<ans[input[i]];
    }
    cout<<endl;
    
    /*for (int i=0; i!=256; i++) {
        cout<<combine[0][i].key<<"-"<<combine[0][i].fre<<endl;
    }
    cout<<"count:"<<count;*/
    
   
    
    
    
}

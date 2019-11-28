#include<bits/stdc++.h>
using namespace std;

const int siz_n=10005;
const int siz_m=500005;
const int INF=0x3f3f3f3f;
int n,m;
struct node{
    int u,v,w;
}G[siz_m];
int d[siz_n];
void bellman(int s){
    int i,u,v,w,sig;
    memset(d,INF,sizeof(d));
    d[s]=0;
    while(1){
        sig=0;
        for(i=0;i<m;i++){
            u=G[i].u;
            v=G[i].v;
            w=G[i].w;
            if(d[v]>d[u]+w){
                d[v]=d[u]+w;
                sig=1;
            }
        }
        if(sig==0)
        break;
    }
}

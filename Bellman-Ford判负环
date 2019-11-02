#include<bits/stdc++.h>
using namespace std;

const int siz_n=2005;
const int siz_m=10005;
const int INF=0x3f3f3f3f;
int n,m;
struct node{
    int u,v,w;
}G[siz_m];
int d[siz_n];
int bellman(int s){
    int i,j,u,v,w;
    memset(d,INF,sizeof(d));
    d[s]=0;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            u=G[j].u;
            v=G[j].v;
            w=G[j].w;
            if(d[v]>d[u]+w){
                d[v]=d[u]+w;
                if(i==n-1)
                return 1;
            }
        }
    }
    return 0;                                   //问是否存在含s点的负环，按边松弛可能存在负环，但是不含s点
}                                               //要注意负环的起始点是否存在

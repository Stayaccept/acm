#include<bits/stdc++.h>
using namespace std;

const int siz=10005;
const int INF=0x3f3f3f3f;
struct node{
    int to,val;
};
vector<node> G[siz];
int n,d[siz],vis[siz];
void dij(int s){
    int i,k,u,v;
    memset(d,INF,sizeof(d));
    memset(vis,0,sizeof(vis));
    d[s]=0;
    while(1){
        k=-1;
        for(i=1;i<=n;i++){
            if(vis[i]==0&&(k==-1||d[i]<d[k]))
            k=i;
        }
        if(k==-1)
        break;
        vis[k]=1;
        for(i=0;i<G[k].size();i++){
            u=G[k][i].to;
            v=G[k][i].val;
            d[u]=min(d[u],d[k]+v);
        }
    }
}

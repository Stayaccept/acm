#include<bits/stdc++.h>
using namespace std;

const int siz=20005;
vector<int> G[siz];
int rt,top,sccnum;
int a[siz],d[siz];
int dfn[siz],low[siz],scc[siz],sta[siz];
void tarjan(int u){
    int i,v;
    sta[++top]=u;
    low[u]=dfn[u]=++rt;
    for(i=0;i<G[u].size();i++){
        v=G[u][i];
        if(dfn[v]==0){
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(scc[v]==0)
        low[u]=min(low[u],dfn[v]);
    }
    if(low[u]==dfn[u]){
        sccnum++;
        v=-1;
        while(u!=v){
            v=sta[top--];
            scc[v]=sccnum;
            d[sccnum]+=a[v];
        }
    }
}

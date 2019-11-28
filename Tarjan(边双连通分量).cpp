#include<bits/stdc++.h>
using namespace std;

const int siz=20005;
int rt,top,sum;
int dfn[siz],low[siz],sta[siz],vis[siz];
vector<int> tmp,G[siz];
void tarjan(int u,int fa){
    int i,v,id;
    sta[++top]=u;
    low[u]=dfn[u]=++rt;
    for(i=0;i<G[u].size();i++){
        v=G[u][i];
        if(dfn[v]==0){
            tarjan(v,u);
            low[u]=min(low[u],low[v]);
        }
        else if(v!=fa)
        low[u]=min(low[u],dfn[v]);
    }
    if(low[u]==dfn[u]){
        tmp.clear();
        v=-1,id=u,sum++;
        while(v!=u){
            v=sta[top--];
            id=min(id,v);
            tmp.push_back(v);
        }
        for(i=0;i<tmp.size();i++)
        vis[tmp[i]]=id;
    }
}

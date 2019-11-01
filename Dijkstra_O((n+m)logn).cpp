#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;

const int siz=20005;
const int INF=0x3f3f3f3f;
int d[siz];
struct node{
    int to,val;
};
vector<node> G[siz];
void dij(int s){
    P p;
    int i,t,u,v,w;
    priority_queue<P,vector<P>,greater<P> > qu;
    memset(d,INF,sizeof(d));
    d[s]=0;
    qu.push(make_pair(0,s));
    while(qu.size()){
        p=qu.top();
        qu.pop();
        t=p.second;
        if(d[t]<p.first)
        continue;
        for(i=0;i<G[t].size();i++){
            u=G[t][i].to;
            v=G[t][i].val;
            if(d[u]>d[t]+v){
                d[u]=d[t]+v;
                qu.push(make_pair(d[u],u));
            }
        }
    }
}

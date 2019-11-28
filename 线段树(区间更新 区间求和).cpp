#include<bits/stdc++.h>
using namespace std;

const int siz=100005;
int tr[siz<<2],lazy[siz<<2];
void pushup(int rt){
    tr[rt]=tr[rt<<1]+tr[rt<<1|1];
}
void pushdown(int rt,int p){
    if(lazy[rt]!=0){
        lazy[rt<<1]=lazy[rt];
        lazy[rt<<1|1]=lazy[rt];
        tr[rt<<1]=lazy[rt]*(p-(p>>1));
        tr[rt<<1|1]=lazy[rt]*(p>>1);
        lazy[rt]=0;
    }
}
void build(int l,int r,int rt){
    int mid;
    lazy[rt]=0;
    if(l==r){
        tr[rt]=1;
        return;
    }
    mid=(l+r)>>1;
    build(l,mid,rt<<1);
    build(mid+1,r,rt<<1|1);
    pushup(rt);
}
void change(int L,int R,int p,int l,int r,int rt){
    int mid;
    if(L<=l&&r<=R){
        lazy[rt]=p;
        tr[rt]=(r-l+1)*p;
        return;
    }
    pushdown(rt,r-l+1);
    mid=(l+r)>>1;
    if(L<=mid)
    change(L,R,p,l,mid,rt<<1);
    if(R>mid)
    change(L,R,p,mid+1,r,rt<<1|1);
    pushup(rt);
}
int query(int L,int R,int l,int r,int rt){
    int ans,mid;
    if(L<=l&&r<=R)
    return tr[rt];
    ans=0,mid=(l+r)>>1;
    pushdown(rt,r-l+1);
    if(L<=mid)
    ans+=query(L,R,l,mid,rt<<1);
    if(R>mid)
    ans+=query(L,R,mid+1,r,rt<<1|1);
    return ans;
}

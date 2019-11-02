#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
const ull base=131;
const ull mod=212370440130137957ll;
ull a[10005];
char s[10005];
ull Hash(char s[]){
    int i;
    ull ans=0;
    for(i=0;s[i];i++)
    ans=(ans*base+(ull)s[i])%mod;
    return ans;
}

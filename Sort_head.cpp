#include <queue>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>

using namespace std;

void down(int *A, int l, int r) {
    int fa = l, son = 2 * l + 1;
    while (son <= r) {
        if (son + 1 <= r && A[son + 1] < A[son]) {
            son++;
        }
        if (A[fa] <= A[son]) {
            break;
        }
        swap(A[fa], A[son]);
        fa = son;
        son = fa * 2 + 1;
    }
}

int main() {
    //freopen("data.in", "r", stdin);
    int N = 6;
    int A[10] = {4, 5, 6, 3, 2, 1};

    for (int i = (N - 1 - 1) / 2; i >= 0; i--) {
        down(A, i, N - 1);
    }
    
    for (int i = N - 1; i >= 0; i--){
        cout<<A[0]<<" ";
        swap(A[0], A[i]);
        if (i >= 1) {
            down(A, 0, i - 1);
        }
    }
    cout<<endl;


    //for (int i = 0; i < 6; i++) {
    //    cout<<A[i]<<" ";
    //}
    //cout<<endl;

    return 0;
}

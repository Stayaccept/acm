#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

template <typename T>
void merge(vector<T> &a, int l, int mid, int r) {
   vector<T> b;
   int i = l, j = mid + 1;
   while (i <= mid && j <= r) {
       if (a[i] < a[j]) {
           b.push_back(a[i]);
           i++;
       }
       else {
           b.push_back(a[j]);
           j++;
       }
   }
   while (i <= mid) {
       b.push_back(a[i++]);
   }
   while (j <= r) {
       b.push_back(a[j++]);
   }
   int _i = 0;
   for (i = l; i <= r; i++) {
       a[i] = b[_i++];
   }
}

// 归并排序，非递归
template<typename T>
void merge_sort(vector<T> &a) {
    int n = a.size();
    for (int seg = 1; seg < n; seg *= 2) {
        for (int i = 0; i + seg - 1 < n; i += seg * 2) {
            int l = i, mid = i + seg - 1, r = min(i + seg * 2 - 1, n - 1);
            merge(a, l, mid, r);
        }
    }
}

// 归并排序，递归
template<typename T>
void merge_sort(vector<T> &a, int l, int r) {
    if (l >= r) return;
    int mid = (l + r) / 2;
    merge_sort(a, l, mid);
    merge_sort(a, mid + 1, r);
    merge(a, l, mid, r);
}

int main() {
    int n, tmp;
    vector<int> a;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        a.push_back(tmp);
    }

    merge_sort(a, 0, n - 1);

    for (int i = 0; i < a.size(); i++) {
        if (i != 0) putchar(' ');
        printf("%d", a[i]);
    }
    putchar('\n');
    return 0;
}

/*
5
4 3 1 2 5
*/


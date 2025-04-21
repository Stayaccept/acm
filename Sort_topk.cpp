#include <queue>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>

using namespace std;

int partition(int *A, int low, int high) {
    int key = A[low];
    while (low < high) {
        while (low < high && A[high] >= key) high--;
        A[low] = A[high];
        while (low < high && A[low] <= key) low++;
        A[high] = A[low];
    }
    A[low] = key;
    return low;
}

void quick_sort(int *A, int low, int high) {
    if (low >= high) return;
    int mid = partition(A, low, high);
    quick_sort(A, low, mid - 1);
    quick_sort(A, mid + 1, high);
}

void quick3_sort(int *A, int len) {
    if (len <= 1) return;
    int key = A[rand() % len];

    int i = 0, j = 0, k = len;
    while (i < k) {
        if (A[i] < key) {
            swap(A[i++], A[j++]);
        }
        else if (A[i] > key) {
            swap(A[i], A[--k]);
        }
        else {
            i++;
        }
    }

    quick3_sort(A, j);
    quick3_sort(A + k, len - k);
}

int quick3_k(int *A, int len, int rk) {
    if (len == 1) return A[0];
    int i = 0, j = 0, k = len;
    int key = A[rand() % len];

    while (i < k) {
        if (A[i] < key) {
            swap(A[i++], A[j++]);
        }
        else if (A[i] > key) {
            swap(A[i], A[--k]);
        }
        else {
            i++;
        }
    }

    if (rk < j) {
        return quick3_k(A, j, rk);
    }
    else if(rk >= k) {
        return quick3_k(A + k, len - k, rk - k);
    }
    return key;
}

void merge(int *A, int l, int r, int _l, int _r) {
    int index = 0, start = l, end = _r;
    int tmp[1024] = {};
    while (l <= r && _l <= _r) {
        if (A[l] < A[_l]) {
            tmp[index++] = A[l];
            l++;
        }
        else {
            tmp[index++] = A[_l];
            _l++;
        }
    }
    while (l <= r) {
        tmp[index++] = A[l++];
    }
    while (_l <= _r) {
        tmp[index++] = A[_l++];
    }
    int _index = 0;
    for (int i = start; i <= end; i++) {
        A[i] = tmp[_index++];
    }
}

void merge_sort(int *A, int l, int r) {
    if (l >= r) {
        return;
    }
    int mid = (l + r) >> 1;
    merge_sort(A, l, mid);
    merge_sort(A, mid + 1, r);
    merge(A, l, mid, mid + 1, r);
}

int main() {
    //freopen("data.in", "r", stdin);
    int A[10] = {6, 5, 4, 3, 2, 1};

    //int ans = quick3_k(A, 6, 5);
    //cout<<"ans = "<<ans<<endl;

    merge_sort(A, 0, 5);

    for (int i = 0; i < 6; i++) {
        cout<<A[i]<<" ";
    }
    cout<<endl;

    return 0;
}

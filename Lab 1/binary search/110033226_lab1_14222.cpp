// https://acm.cs.nthu.edu.tw/contest/2951/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to perform binary search, now using size_t for indexing
bool binary_search(const vector<long long>& arr, long long x) {
    size_t left = 0, right = arr.size() - 1;

    while (left <= right) {
        size_t mid = left + (right - left) / 2;
        
        if (arr[mid] == x) return true;
        
        // Since the array is non-increasing, we go left if the mid is less than x
        if (arr[mid] < x) right = mid - 1;
        else left = mid + 1;
    }
    return false;
}

int main() {
    size_t n, m;
    cin >> n >> m;
    
    vector<long long> A(n);
    for(long long& a : A) cin >> a;
    
    vector<long long> Q(m);
    for(long long& q : Q) cin >> q;
    
    // We can use std::binary_search since we just need to know if the element exists
    for(size_t i = 0; i < m; ++i){
        bool found = binary_search(begin(A), end(A), Q[i], greater<long long>());
        cout << (found ? "Y " : "N ");
    }
    return 0;
}

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int testCase;
    cin >> testCase;
    while (testCase--) {
        int n, l, r;
        cin >> n >> l >> r;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int tofind = r - l + 1;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; i++) {
            pq.push(arr[i]);
        }
        long long ans = 0;
        for (int i = 0; i < tofind; i++) {
            ans += pq.top();
            pq.pop();
        }
        cout << ans << endl;
    }
}

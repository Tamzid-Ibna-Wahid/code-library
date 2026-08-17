#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

// monotonic queue to find the maximum of every sliding window of size k
struct monotonous_queue { //max, stores strictly decreasing sequence of the current queue
  int a[N + 10], b[N + 10], l = 0, r = -1;
  void push(int val) {  // Insert a new value
    int cnt = 0;
    while(l <= r && a[r] <= val) {  // For minimum (l <= r && a[r] >= val) 
      cnt += b[r] + 1;
      r--;
    }
    a[++r] = val, b[r] = cnt;
  };
  int top() {   // Current maximum
    return a[l];
  }
  void pop() {    // Remove one element from the front of the original queue
    if(l > r) return;
    if (b[l] > 0) {
      b[l] --;
      return;
    }
    l++;
  }
};

int32_t main() {
  int n, k; cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  monotonous_queue mq;

  for (int i = 0; i < n; i++) {
      mq.push(a[i]);
      if (i >= k - 1) {
          cout << mq.top() << " ";
          mq.pop();
      }
  }
  return 0;
}
// https://cses.fi/boi24/task/3221

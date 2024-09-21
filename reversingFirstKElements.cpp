#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  queue<int> modifyQueue(queue<int> q, const int k) {
    solve(q, k);
    unsigned long long s = q.size() - k;
    while (s-- > 0) {
      int x = q.front();
      q.pop();
      q.push(x);
    }
    return q;
  }

  void solve(queue<int> &q, const int k) {
    if (k == 0)
      return;
    const int e = q.front();
    q.pop();
    solve(q, k - 1);
    q.push(e);
  }
};

int main() {
  int t;
  cin >> t;
  while (t-- > 0) {
    int n, k;
    cin >> n >> k;
    queue<int> q;
    while (n-- > 0) {
      int a;
      cin >> a;
      q.push(a);
    }
    Solution ob;
    queue<int> ans = ob.modifyQueue(q, k);
    while (!ans.empty()) {
      const int a = ans.front();
      ans.pop();
      cout << a << " ";
    }
    cout << endl;
  }
}

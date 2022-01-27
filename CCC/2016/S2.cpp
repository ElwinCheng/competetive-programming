#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  cin >> q;
  int n; 
  cin >> n;
  int p[n], d[n];
  for (int i = 0; i < n; i++){
    cin >> d[i];
  }
  for (int i = 0; i < n; i++){
    cin >> p[i];
  }
  if (q == 1){
      sort(d, d + n);
      sort(p, p + n);
  } else {
      sort(d, d + n);
      sort(p, p + n, greater<int>());
  }
  int ans = 0;
  for (int i = 0; i < n; i++){
    ans += max(d[i], p[i]);
  }
  cout << ans;
}
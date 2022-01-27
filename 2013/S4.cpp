#include <bits/stdc++.h>
using namespace std;

const int maxN = 1000001;
vector<int> adj[maxN];
bool visited[maxN];

void dfs(int a){
  visited[a] = true;
  for (int b : adj[a]){
    if (!visited[b]){
      dfs(b);
    }
  }
}

int main() {
  memset(visited, 0, sizeof(visited));
  int n, m; cin >> n >> m; // n nodes, m edges
  
  for (int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    adj[a].push_back(b);
  }

  int p, q;
  cin >> p >> q;

  dfs(p);
  if (visited[q]){
    cout << "yes";
	return 0;
  }
  memset(visited, 0, sizeof(visited));
  dfs(q);
  if (visited[p]){
    cout << "no";
  } else {
    cout << "unknown";
  }

}
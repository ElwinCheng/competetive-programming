#include <bits/stdc++.h>
using namespace std;

const int N = 10000;
int dist[N];
bool visited[N];
vector<int> adj[N];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++){
    int a, b; 
    cin >> a >> b;
    adj[a].push_back(b);
  }
  while (true){
    int l, k;
    cin >> l >> k;
    if (l == 0){
      break;
    }
    memset(visited, 0, sizeof(visited));
    dist[l] = 0;
    queue<int> q;
    q.push(l);
    visited[l] = true;
    while(!q.empty()){
      int a = q.front();
      q.pop();
      for (int b : adj[a]){
        if (!visited[b]){
          q.push(b);
          visited[b] = true;
          dist[b] = dist[a] + 1;
        }
      }
    }
    if (visited[k]){
      cout << "Yes " << dist[k] - 1;
    } else {
      cout << "No";
    }
    cout << "\n";

  
  }
  
}
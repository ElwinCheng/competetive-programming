#include <bits/stdc++.h>
using namespace std;

const int INF = 200000000;
const int N = 5001;
bool visited[N];
vector<pair<int,int>> adj[N];
int dist[N];
int pencil_cost[N];
bool has_pencil[N];

int main() {
    ios_base::sync_with_stdio(false);
   cin.tie(NULL);

  memset(visited, 0, sizeof(visited));
  memset(has_pencil, 0, sizeof(has_pencil));
  int nodes, roads;
  cin >> nodes >> roads;
  for (int i = 0; i < roads; i++){
    int x, y, cost;
    cin >> x >> y >> cost;
    adj[x].push_back({y, cost});
    adj[y].push_back({x, cost});
  }
  int k; 
  cin >> k;
  for (int i = 0; i < k; i++){
    int city, cost;
    cin >> city >> cost;
    pencil_cost[city] = cost;
    has_pencil[city] = true;
  }
  priority_queue<pair<int,int>> q;
  int d;
  cin >> d;
  for (int i = 1; i <= nodes; i++){
    dist[i] = INF;
  }
  dist[d] = 0;
  q.push({0,d});
  while(!q.empty()){
    int a = q.top().second;
    q.pop();
    if (visited[a]) continue;
    visited[a] = true;
    for (pair<int,int> u : adj[a]) {
      int b = u.first;
      int weight = u.second;
      if (dist[a] + weight < dist[b]){
        dist[b] = dist[a] + weight;
        q.push({-dist[b], b});
      }
    }
  }
  int ans = INF;
  for (int i = 1; i <= nodes; i++){
    if (has_pencil[i]){
      if (pencil_cost[i] + dist[i] < ans){
        ans = pencil_cost[i] + dist[i];
      }
    }
    
  }
  cout << ans;
}
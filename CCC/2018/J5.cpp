#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n; cin >> n;
	vector<int> graph[n+1];
	for (int i = 1; i <= n; i++){
		int num; cin >> num;
		for (int j = 0; j < num; j++){
			int a; cin >> a;
			graph[i].push_back(a);
		}
	}
	bool visited[n+1];
	int dist[n+1];
	memset(visited, 0, sizeof(visited));
	queue<int> q;
	q.push(1);
	visited[1] = 1;
	dist[1] = 1;
	int ans = 0x3f;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		if (!graph[u].size()){
			ans = min(ans, dist[u]);
		}
		for (int v : graph[u]){
			if (visited[v]) continue;
			dist[v] = dist[u] + 1;
			visited[v] = 1;
			q.push(v);		
		}
	}
	bool ok = 1;
	for (int i = 1; i <= n; i++){
		ok &= visited[i];
	}
	cout << (ok? 'Y' : 'N') << "\n";
	cout << ans;
}
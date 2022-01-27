#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
using namespace std;
bool visited[50];
int ans = 0;
int dist[50];
	
int main(){
	
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    unordered_set<int> f[50] = {{}, {6}, {6}, {4,5,6,15}, {3,5,6}, {3,4,6}, {1,2,3,4,5,7}, {6,8}, {7,9}, {8,10,12}, {9,11}, {10,12}, {9,11,13}, {12,14,15}, {13}, {3,13}, {17,18}, {16,18}, {16,17}};
    char c;
    int x, y;
    while(cin >> c){
		if (c == 'q') break;
		else if (c == 'i'){
			cin >> x >> y;
			f[x].insert(y);
			f[y].insert(x);
			}
		else if (c == 'd'){
			cin >> x >> y;
			f[x].erase(y);
			f[y].erase(x);
			}
		else if (c == 'n'){
			cin >> x;
			cout << f[x].size() << "\n";;
			/*
			memset(visited, 0, sizeof(visited));
			memset(dist, 0, sizeof(dist));
			visited[x] = 1;
			dist[x] = 0;
			queue<int> q;
			p.push(x);
			while(!q.empty()){
				int a = q.front();
				q.pop();
				for (auto u: f[a]){
					if (visited[u] || dist[) continue;
					visited[u] = 1;
					dist[u] = dist[a] +1;
					}
				}
				*/
		}
		else if (c == 'f'){
			cin >> x;
			memset(visited, 0, sizeof(visited));
			visited[x] = 1;
			for (auto u : f[x]) visited[u] = 1;
			int count = 0;
			for (auto u : f[x]){
				for (auto v : f[u]){
					if (visited[v]) continue;
					visited[v] = 1;
					count ++;
					}
				}
			cout << count << "\n";
			}
		else if (c == 's'){
			cin >> x >> y;
			memset(visited, 0, sizeof(visited));
			memset(dist, 0, sizeof(dist));
			queue<int> q;
			q.push(x);
			dist[x] = 0;
			visited[x] = 1;
			while(!q.empty()){
				int a = q.front(); q.pop();
				for (auto u : f[a]){
					if (visited[u]) continue;
					visited[u] = 1;
					dist[u] = dist[a] +1;
					if (u == y) break;
					q.push(u);
					}
				}
			if (dist[y]) cout << dist[y] << "\n";
			else cout << "Not connected\n";
			}
		
		
		}
	
	}
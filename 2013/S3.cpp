#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
using namespace std;

map<int,int> score;
vector<pair<int,int>> teams;
bool played[5][5] = {0};
int answer = 0;
int myTeam;

bool mx(){
	int ans = 0;
	int mx = 0;
	for (auto it = score.begin(); it != score.end(); it++){
		if (it->second > mx){
			mx = it-> second;
			ans = it -> first;
			}
		}
	for (auto it = score.begin(); it != score.end(); it++){
		if (it->second == mx && it->first != ans){
			return 0;
			}
		}		
	return (myTeam == ans);
	}

void dfs(int a, int b, int dep, int mxdep){
	if (dep!= -1){
	score[teams[dep].first] += a;
	score[teams[dep].second] += b;
	}
	if (dep == mxdep){
		if (mx()) answer++;
		return;
		}
	dfs(0,3,dep+1,mxdep);
	score[teams[dep+1].second] -= 3;
	
	dfs(3, 0, dep+1, mxdep);
	score[teams[dep+1].first] -= 3;
	
	dfs(1, 1, dep+1, mxdep);
	score[teams[dep+1].second]--;
	score[teams[dep+1].first]--;
	
	}

void solve(){
		int a, b, n, m, g;
		cin >> myTeam >> g;
		for (int i = 0; i < g; i++){
			cin >> a >> b >> n >> m;
			if (n >m)
				score[a] += 3;
			else if (n < m)
				score[b] += 3;
			else {
				score[a]++;
				score[b]++;
			}
			played[a][b] = 1;
			played[b][a] = 1;
			}
		for (int i = 2; i < 5; i++){
			for (int j = 1; j < i; j++){
				if (!played[i][j]){
					teams.pb(mp(i,j));
					}
				}
			}
		dfs(0, 0, -1, 6-g-1);
	}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
	solve();
	cout << answer;
}
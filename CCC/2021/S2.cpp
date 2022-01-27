#include <bits/stdc++.h>
using namespace std;

int main(){
	int m, n, k; cin >> m >> n >> k;
	int row[m], col[n];
	memset(row, 0, sizeof(row));
	memset(col, 0, sizeof(col));
	for (int i = 0; i < k; i++){
		char c; cin >> c;
		int num; cin >> num;
		num--;
		if (c== 'R'){
			row[num]++;	
		} else{
			col[num]++;
		}
	}
	int ans = 0;
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			if ((row[i] + col[j])&1){
				ans++;
			}
		}
	}
	cout << ans;

}
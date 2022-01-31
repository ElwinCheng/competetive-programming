#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
	int n; cin >> n;
	tuple<ll,ll,ll> arr[n];
	for (int i = 0; i < n; i++){
		ll p, w, d; cin >> p >> w >> d;
		arr[i] = {p,w,d};
	}
	ll ans = (1 << 30);
	ans *= ans;
	ll l = 0, r = 1000000000;
	while (l <= r){
		//cout << l << ' ' << r << "\n";
		ll m1 = l + ((r - l) / 3);
		ll m2 = r - ((r - l) / 3);
		//cout << m1 << ' ' << m2 << "\n";
		ll ans1 = 0, ans2 = 0;
		for (int j = 0; j < n; j++){
			ll p = get<0>(arr[j]), w = get<1>(arr[j]), d = get<2>(arr[j]);	
			if ((abs(m1-p)-d) > 0){
				ans1 += (abs(m1-p)-d)*w;
			}
			if ((abs(m2-p)-d) > 0){
				ans2 += (abs(m2-p)-d)*w;
			}
		}
		/*for (int j = 0; j < n; j++){
			ll p = get<0>(arr[j]), w = get<1>(arr[j]), d = get<2>(arr[j]);	
			if ((abs(m2-p)-d) > 0){
				ans2 += (abs(m2-p)-d)*w;
			}
		}*/
		//cout << ans1 << ' ' << ans2 << "\n\n";
		if (ans1 > ans2){
			if (ans2 < ans){
				ans = ans2;
			}
			l = m1 + 1;
		} else {
			if (ans1 < ans){
				ans = ans1;
			}
			r = m2 - 1;
		}
	}
	cout << ans;
	
}
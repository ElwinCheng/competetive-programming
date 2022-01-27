#include <bits/stdc++.h>

using namespace std;

int main() {
    string a, b; cin >> a >> b;
    int s = a.length();
    int ara[26], arb[26];
    memset(ara, 0, sizeof(ara));
    memset(arb, 0, sizeof(arb));
    int na = 0;
    for (int i = 0; i < s; i++){
        ara[a[i] - 'a']++;
        if (b[i] == '*'){
            continue;
        }
        arb[b[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++){
        if (arb[i] > ara[i]){
            cout << 'N';
            return 0;
        }
    }
    cout << 'A';
    return 0;
}
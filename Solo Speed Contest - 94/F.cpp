#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> kingdoms(n);
        for (int i = 0; i < n; i++) {
            cin >> kingdoms[i].first >> kingdoms[i].second;
        }
        sort(kingdoms.begin(), kingdoms.end());
        int bombs = 1, last = kingdoms[0].second;
        for (int i = 1; i < n; i++) {
            if (kingdoms[i].first > last) {
                bombs++;
                last = kingdoms[i].second;
            } else {
                last = min(last, kingdoms[i].second);
            }
        }
        cout << bombs << endl;
    }
    return 0;
}

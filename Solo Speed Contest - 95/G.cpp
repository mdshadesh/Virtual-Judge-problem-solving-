#include <iostream>
#include <stdio.h>

using namespace std;


int main() {
	int n, d;
	long long ans;

	scanf("%d", &n);
	d = 1, ans = 0;
	while (n--) {
		int a;

		scanf("%d", &a);
		ans += (a - 1) / d;
		if (a == d || d == 1)
			d++;
	}
	printf("%lld\n", ans);
	return 0;
}
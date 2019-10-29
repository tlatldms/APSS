#include <iostream>
#include <vector>

using namespace std;

int fun(int x, int y) {
	int sub = y - x;
	int t = 1;
	while (sub > (t * (t++)));
	if (sub <= (t*t-t)) return (t - 1) * 2;
	else return t * 2 - 1;
}
int main() {
	int T, x, y;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> x >> y;
		cout << fun(x, y) << endl;
	}
}
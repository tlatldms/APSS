#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;
double cnt;
map<string, int> m;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	while (1) {
		string name;
		
		getline(cin, name);

		if (cin.eof()) break;
		cnt++;
		if (m.find(name) == m.end()) {
			m[name] = 1;
		}
		else m[name]++;
		//cout << m[name] << endl;
	}
	for (auto s : m) {
		cout << fixed;
		cout.precision(4);
		cout << s.first << " " << ((double)s.second / cnt) * 100 << endl;
	}

	

	return 0;
}
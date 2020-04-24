#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>

using namespace std;

map<string, vector<string>> m;
map<string, bool> visit;
vector<string> v;
int n;

void dfs(string s) {
	
	visit[s] = true;

	for (string ss : m[s]) {
		if (!visit[ss]) {
			dfs(ss);
			v.push_back(ss);
		}
			
	}
}

int main() {
	int TC;
	cin >> TC;
	while (TC--) {
		cin >> n;
		string s1, s2;
		m.clear();
		for (int i = 0; i < n; i++) {	
			v.clear();
			visit.clear();
			cin >> s1 >> s2;
			m[s1].push_back(s2);
			m[s2].push_back(s1);
			
			dfs(s1); dfs(s2);
			
			
			cout << "\nsize: " << v.size() << "\nelems: ";
			for (auto x : v) cout << x << " ";
		}

	}
	return 0;
}
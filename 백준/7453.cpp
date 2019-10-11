#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> A, B, C, D;
vector<int> AB, CD;
long long int answer=0;
void pluss() {
	int i, j, idx = 0, target;
	long long int cntcd;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			AB[idx++] = A[i] + B[j];
		}
	}
	idx = 0;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			CD[idx++] = C[i] + D[j];
		}
	}
	sort(AB.begin(), AB.end());
	sort(CD.begin(), CD.end());
	
	/*
	for (i = 0; i < n * n; i++) cout << "i: "<< i << ", AB[i]: "<< AB[i] << endl;
	cout << endl;
	for (i = 0; i < n * n; i++) cout << "i: " << i << ", CD[i]: " << CD[i] << endl;
	//cout << "DSDGSDDSFL: " << CD[6] << " " << CD[7] << " " << CD[8] << endl;
	*/

	i = 0;
	while (i < n * n) {
		long long int cntab = 0;
		target = -AB[i];
		//cout << "i: " << i << endl;
		while (i+cntab < n*n) {
			if (AB[i + cntab] != -target) break;
			cntab++;
		}
		int low = lower_bound(CD.begin(), CD.end(), target) - CD.begin();
		
		int up = upper_bound(CD.begin(), CD.end(), target) - CD.begin();
		//cout << "cntab: " << cntab << ", low: " << low << ", up: " << up << endl;
		if (low < n*n && CD[low] == target) {
			cntcd = (up - low);
			answer += (cntab* cntcd);
		}

		i += cntab;
	}

	
}
int main() {
	cin >> n;
	int i;
	A.resize(n);
	B.resize(n);
	C.resize(n);
	D.resize(n);
	AB.resize((n * n));
	CD.resize((n * n));

	for (i = 0; i < n; i++) {
		cin >> A[i] >> B[i] >> C[i] >> D[i];
	}
	pluss();
	cout << answer;
	return 0;
}
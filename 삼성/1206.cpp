#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int fun(vector<int> bds, int n) {
  int i,lm, rm, m, sum=0;
  for (i=2; i<n-2; i++) {
    lm = max(bds[i-1], bds[i-2]);
    rm = max(bds[i+1], bds[i+2]);
    m = max(lm, rm);
    if (bds[i] > m) { //최소한개는있음
      cout << "한개는"<<endl;
      sum += (bds[i]-m);
    }
  }

  return sum;
}

int main() {
  int i,j, n, a;
  for (i=1; i<=10; i++) {
    cin >> n;
    vector<int> buildings (n);
    for (j=0; j<n; j++) {
      cin >> a;
      buildings.push_back(a);
    }

    cout << "#"<<i<<" "<<fun(buildings, n)<<endl;
  }
  return 0;
}

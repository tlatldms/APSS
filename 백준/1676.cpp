#include <iostream>

using namespace std;

int main(void) {
  int N, i, check = 0, tt;
  long long res=1;
  cin >> N;

  for ( i=1 ; i<=N; i++ ) {
    tt=i;
    while( tt != 0) {
      if ( tt % 5 == 0 ) {
        check ++ ;
        tt /= 5;
      } else break;
    }
  }

  cout  << check;
  return 0;
}

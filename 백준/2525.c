#include <stdio.h>

int main() {
  int h,m, c;
  scanf("%d %d %d", &h, &m, &c);

  int before_h = (m+c)/60;
  int after_m = (m+c)%60;

  int after_h = (h+before_h)%24;

  printf("%d %d", after_h, after_m);
  return 0;
}

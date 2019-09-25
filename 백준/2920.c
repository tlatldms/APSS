#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
  int i;
  int* a;
  int flag=-1;
  for (i=0; i<8; i++) {
    a=malloc(sizeof(int)*8);
  }

  for (i=0; i<8; i++) {
    scanf("%d", &a[i]);
  }

if (a[0]==1) {
  for (i=0; i<7; i++){
      if (a[i+1]!=a[i]+1) {
        break;
      }
  }
  if (i==7) flag=1;
} else if (a[0]==8){
  for (i=0; i<7; i++) {
    if (a[i+1]!=a[i]-1) {
      break;
    }
  }

   if (i==7) flag=2;
}

if (flag==-1) {
  printf("%s", "mixed");
} else if (flag==1) {
  printf("%s", "ascending");
} else printf("%s", "descending");

  return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main() {
  int N, i, a=0,b=0,c=0, m;
  scanf("%d", &N);
  char* answer = malloc(sizeof(char)*N);
  scanf("%s", answer);


  for (i=0; i<N; i++) {
    if (i%3==0 && answer[i]=='A' || i%3==1 && answer[i]=='B' || i%3==2 && answer[i]=='C') {
      a++;
    } 
    if (i%2==0 && answer[i]=='B' || i%4==3 && answer[i]=='C' || i%4==1 && answer[i]=='A') {
      b++;
    }
    if (((i%6==0 || i%6==1)&&answer[i]=='C') ||
        ((i%6==2 || i%6==3)&&answer[i]=='A') ||
        ((i%6==4 || i%6==5)&& answer[i]=='B')) {
      c++;
    }
  }

  free(answer);

  if (a>=b) {
    m=a;
    if (c>=a) {
      m=c;
    }
  } else if (b>=a) {
    m=b;
    if (c>=b) {
      m=c;
    }
  }

  printf("%d\n", m);
  if (m==a) printf("%s", "Adrian\n");
  if (m==b) printf("%s", "Bruno\n");
  if (m==c) printf("%s", "Goran\n");

  return 0;
}


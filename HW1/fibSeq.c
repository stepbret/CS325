#include <stdio.h>
#include <math.h>
#include <time.h>

int recurFib(int n){
  if(n == 0){
    return 0;
  }
  else if (n == 1) {
    return 1;
  }
  else {
    return (recurFib(n-1) + recurFib(n-2));
  }
}

int iterFib(n) {
  int fib = 0;
  int a = 1;
  int t = 0;
  int i = 1;
  for(i; i < n; i++){
    t = fib + a;
    a = fib;
    fib = t;
  }
  return fib;
}


int main () {

  int inputs[] = {5, 10, 15, 20, 30, 50, 100, 1000, 2000, 5000, 10000};
  clock_t t;
  FILE *fp;
  fp = fopen("results.txt", "w+");
  int i;
  for(i = 0; i < 11; i++){
    t = clock();
    recurFib(inputs[i]);
    t = clock() - t;
    printf("Clocks: %d\n", t);
    fprintf(fp, "%d   %f\n", inputs[i], ((float)t) / CLOCKS_PER_SEC);
  }
  for(i = 0; i < 11; i++){
    t = clock();
    iterFib(inputs[i]);
    t = clock() - t;
    fprintf(fp, "%d   %f\n", inputs[i], ((float)t) / CLOCKS_PER_SEC);
  }

  fclose(fp);


  return 0;
}

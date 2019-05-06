#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <limits.h>
#include <x86intrin.h>
#include <math.h>

#define N 10000000

void print_time(long n, int *tab, long pas, int (*f_to_time)(long, long, int*)){
  unsigned long nb = clock(); 

  f_to_time(n, pas, tab);

  printf("Size : %ld & pas : %ld --> %.10f sec\n", n, pas, (clock()-nb)/(float)CLOCKS_PER_SEC);
}


void print_cycles(int n, int (*f_to_time)(int), int count){
  int sum = 0;
  for (int i = 0; i < 3; ++i){
   sum+=f_to_time(n);
  }

  unsigned long tic, toc;
  unsigned int ui;

  tic = __rdtscp(&ui);

  for (int i = 0; i < count; ++i){
   sum+=f_to_time(n);
  }

  toc = __rdtscp(&ui);
  
  printf("%d, n=%d (tab size = %luK): %lu cycles\n",sum==0,n,n*sizeof(int)/1000, (toc-tic)/count);
}

int acceder(long n, long pas, int *tab){
  int i, res, sum = 0; 

  for(i = 0; i < N; i+=pas){
    sum += tab[i%(n-1)];
  }

  return sum;
}

int main(){
  int i, j;
  int *tab;
  int size[10] = {10, 16, 17, 18, 19, 20, 21, 30};

  for(i = 0; i < 10; i++){
    for(j = 0; j < 10; j++){
      tab = (int *) malloc(sizeof(int) * size[i]);
      print_time(pow(2, size[i]), tab, pow(2, j), acceder);

      free(tab);
    }
  }


  return 0;
}
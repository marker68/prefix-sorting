/* -*-coding: utf-8 -*-
 * Option 6: make_sa3.c
 * Student No.: 03-123010
 * Name: NGUYEN ANH TUAN
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "utils/util.h"
#include "utils/quicksort.h"

char * S;

int int_cmp(const long a_, const long b_) {
  const long * a = &a_;
  const long * b = &b_;
  return strcmp(S + *a, S + *b);
}

int main(int argc, char * argv[]) {
  double start = get_current_milisec();
  if(argc != 4 || argv[2] == NULL || argv[1] == NULL || argv[3] == NULL) {
    fprintf(stderr,"Usage: %s 文字列ファイル 接尾辞配列ファイル N\n",argv[0]);
    exit(1);
  }
  
  long N , n, i, j = 0, * sa;
  FILE * fp;
  char * s0;
  
  N = atol(argv[3]);
  s0 = read_file_n(argv[1], N);
  S = s0;
  for (i = 0; i < N; i++) if(first_byte(S[i])) j++;
  n = j;
  sa = malloc(sizeof(long) * n);
  printf("number of indexes: %ld\n",n);
  for(i = j = 0;i < N; i++) if(first_byte(S[i])) sa[j++] = i;
#pragma omp parallel 
  {
#pragma omp master
    {
      qs(sa, 0, n, int_cmp);
    }
  }
  if((fp = fopen(argv[2],"w+"))==NULL){
    fprintf(stderr,"Error while writing to file\n");
    exit(1);
  }
  
  for (i = 0; i < n; i++) {
    if(i < n-1) fprintf(fp,"%ld\n", sa[i]);
    else fprintf(fp,"%ld",sa[i]);
  }
  
  fclose(fp);
  double end = get_current_milisec();
  printf("Execution time: %.2f[ms]\n",end - start);
  return 0;
}

/* -*-coding: utf-8 -*-
 * Option 4: make_sa2.c
 * Student No.: 03-123010
 * Name: NGUYEN ANH TUAN
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "utils/util.h"

char * S;
long comp = 0;

int int_cmp(const void * a_, const void * b_) {
  comp++;
  const int * a = a_;
  const int * b = b_;
  return strcmp(S + *a, S + *b);
}

int main(int argc, char * argv[]) {
  if(argc != 4 || argv[2] == NULL || argv[1] == NULL || argv[3] == NULL) {
    fprintf(stderr,"Usage: %s 文字列ファイル 接尾辞配列ファイル N\n",argv[0]);
    exit(1);
  }
  long N = atol(argv[3]);
  char * s0 = read_file_n(argv[1], N);
  S = s0;
  long i, j = 0;
  for (i = 0; i < N; i++) if(first_byte(S[i])) j++;
  long n = j;
  long * sa = malloc(sizeof(long) * n);
  double start = get_current_milisec();
  printf("How many indexes we'd have? %ld\n",n);
  for(i = j = 0;i < N; i++) if(first_byte(S[i])) sa[j++] = i;
  qsort(sa, n, sizeof(long), int_cmp); 
  double end = get_current_milisec(); 
  FILE * fp;
  if((fp = fopen(argv[2],"w+"))==NULL){
    fprintf(stderr,"Error while writing to file\n");
    exit(1);
  }

  for (i = 0; i < n; i++) {
    if(i < n-1) fprintf(fp,"%ld\n", sa[i]);
    else fprintf(fp,"%ld",sa[i]);
  }

  fclose(fp);

  printf("Time for making SA: %.2f[ms]\n",end - start);
  printf("How many comparisons this algorithm used? %ld\n",comp);
  return 0;
}

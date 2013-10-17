/* -*-coding: utf-8 -*-
 * Option 1: make_sa1.c
 * Student No.: 03-123010
 * Name: NGUYEN ANH TUAN
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include "utils/util.h"

char * S;
long comp = 0; // for counting how many comparisons we've just used

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

  char * s0 = malloc(N);
  if(s0 == NULL) {
    fprintf(stderr,"Malloc failure\n");
    exit(1);
  }

  FILE * fp;
  if((fp = fopen(argv[1],"r")) == NULL) { 
    fprintf(stderr,"cannot open the file\n");
    exit(1);
  }

  if(fread(s0,sizeof(char),N,fp) < N) {
    fprintf(stderr,"The file does not contain %ld bytes or more.\n",N);
    exit(1);
  }

  fclose(fp);
  S = s0;
  long n= strlen(S);
  long i;
  long * sa = malloc(sizeof(long) * n);
  double start = get_current_milisec();
  printf("How many indexes we'd have? %ld\n",n);
  for (i = 0; i < n; i++) {
    sa[i] = i;
  }
  qsort(sa, n, sizeof(long), int_cmp);
  double end = get_current_milisec();
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
  printf("How many comparisons this quicksort algorithm used? %ld\n",comp);
  return 0;
}

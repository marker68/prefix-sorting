/* -*-coding: utf-8 -*-
 * Problem 4: make_sa_find4.c
 * Student No.: 03-123010
 * Name: NGUYEN ANH TUAN
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include "utils/bsearcht.h"

long int sct = 0; // for counting the times the string_cmp function was called

int string_cmp2(const void * a_, const void * b_) {
  sct++;
  const char * const * a = a_;
  const char * const * b = b_;
  return strcmp(*a, *b);
}

int main(int argc, char * argv[]) {
  clock_t begin, end;
  double read_time = 0.0, sort_time = 0.0, search_time = 0.0;

  if(argc != 5) {
    fprintf(stderr,"Usage: %s 文字列ファイル N L K\n",argv[0]);
    exit(1);
  }

  int N = atoi(argv[2]);
  int L = atoi(argv[3]);
  int K = atoi(argv[4]);
  FILE * fp;

  if((fp = fopen(argv[1],"r")) == NULL) {
    fprintf(stderr,"Cannot open the file %s\n",argv[1]);
    exit(1);
  }

  fseek(fp, 0L, SEEK_END); // seek to the end of the buffer
  if(ftell(fp) < N) {
    fprintf(stderr,"This %s file does not contain %d bytes or more\n",argv[1],N);
    exit(1);
  }
  
  fseek(fp, 0L, SEEK_SET); // after obtaining the file size, seek to the begin of the buffer for the main process
  char * s = malloc(N);
  if(s == NULL) {
    fprintf(stderr,"Malloc failure.\n");
    exit(1);
  }

  int i = 0;
  // Reading file
  begin = clock();
  while(i < N) {
    s[i++] = fgetc(fp);
  }
  s[i] = 0; // insert a 0 to the end
  // End of reading file
  end = clock();
  read_time = (double)(end-begin)/CLOCKS_PER_SEC * 1000.0F;
  fclose(fp);

  char ** a = malloc(sizeof(char*) * N);
  for (i = 0; i < N; i++) {
    a[i] = s + i;
  }
  begin = clock();
  qsort(a, N, sizeof(char*), string_cmp2);
  end = clock();
  sort_time = (double)(end-begin)/CLOCKS_PER_SEC * 1000.0F;

  char * sk = (char *)malloc(sizeof(char) * L);
  int k = (int)(N/K);
  begin = clock();
  for(i = 0; i < K; i++) {
    strncpy(sk,s + i * k,L);
    search1(sk,a,N);
  }
  end = clock();
  search_time = (double)(end-begin)/CLOCKS_PER_SEC * 1000.0F;

  printf("File reading time: %f\nSorting time: %f\nSearching time: %f\nThe time string_cmp function was called:%ld\n",read_time,sort_time,search_time,sct);
  return 0;
}

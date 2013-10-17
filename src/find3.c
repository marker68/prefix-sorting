/* -*-coding: utf-8 -*-
 * Problem 3: q3.c
 * Compilation: gcc -O3 -Wall -g -o find3 q3.c
 * Student No.: 03-123010
 * Name: NGUYEN ANH TUAN
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include "utils/util.h"
#include "utils/bsearcht.h"

int main(int argc, char * argv[]) {
  if(argc != 4) {
    fprintf(stderr,"Usage: %s 入力ファイル 検索文字列 N\n",argv[0]);
    exit(1);
  }

  int N = atoi(argv[3]);
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
  fseek(fp, 0L, SEEK_SET); // after obtaining the filesize, seek to the begin of the buffer for the main process
  char * s = malloc(N);
  if(s == NULL) {
    fprintf(stderr,"Malloc failure.\n");
    exit(1);
  }
  int i = 0;
  while(i < N) {
    s[i++] = fgetc(fp);
  }
  s[i] = 0; // insert a 0 to the end
  fclose(fp);

  int k = strlen(argv[2]),  f = -1;
  char ** a = malloc(sizeof(char*) * N);
  for (i = 0; i < N; i++) {
    a[i] = s + i;
  }
  qsort(a, N, sizeof(char*), string_cmp);

  // binary search
  f = bsearch_ex(argv[2],a,N);
  if(f >= 0) {
    for(;f<N;f++) {
      if(strncmp(argv[2],a[f],k) != 0) break;
      if(f < N) printf("%d\n",(int)(N-strlen(a[f])));
    }
  }
  return 0;
}

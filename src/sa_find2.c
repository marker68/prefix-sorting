/* -*-coding: utf-8 -*-
 * Option 2: sa_find2.c
 * Student No.: 03-123010
 * Name: NGUYEN ANH TUAN
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include "utils/util.h"
#include "utils/bsearcht.h"

#define MAX 100000000

long * sa; 
char * S;

int main(int argc, char * argv[]) {
  clock_t begin, end;
  double time = 0.0;
  if(argc != 4) {
    fprintf(stderr,"Usage: %s 文字列ファイル 接尾辞配列ファイル 検索文字列\n",argv[0]);
    exit(1);
  }

  FILE * fp;
  char * sk = argv[3];
  begin = clock();
  if((fp = fopen(argv[2],"r")) == NULL) {
    fprintf(stderr,"Cannot open the file %s\n",argv[2]);
    exit(1);
  }
  sa = malloc(sizeof(long) * MAX);
  if(sa == NULL) die("malloc");

  long i = 0;
  while(fscanf(fp,"%ld",&sa[i]) > 0) i++;
  fclose(fp);
  long N = i;
  if((fp = fopen(argv[1],"r")) == NULL) {
    fprintf(stderr,"Cannot open the file %s\n",argv[1]);
    exit(1);
  }
  fseek(fp, 0L, SEEK_END);
  long sz = ftell(fp);
  fseek(fp, 0L, SEEK_SET);

  char * s0 = malloc(sz);

  if(s0 == NULL) die("malloc");
  if(fread(s0,1,sz,fp) < sz) {
    fprintf(stderr,"some errors\n");
    exit(1);
  }
  fclose(fp);
  S = s0;
  char ** a = malloc(sizeof(char*) * N);
  for(i = 0; i < N; i++) a[i] = S + sa[i];
  search(sk,a,N,sa);
  end = clock();
  time += (double)(end - begin)/CLOCKS_PER_SEC * 1000.0;
  printf("File reading time: %.2f[ms]\n", time);
  return 0;
}

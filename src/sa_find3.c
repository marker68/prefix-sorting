/* -*-coding: utf-8 -*-
 * Option 3: sa_find3.c
 * Compilation: gcc -O3 -Wall -g -o sa_find3 sa_find3.c
 * Student No.: 03-123010
 * Name: NGUYEN ANH TUAN
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "utils/util.h"
#include "utils/bsearcht.h"

long * sa; 
char * S;

int main(int argc, char * argv[]) {
  clock_t begin, end;
  double time = 0.0;
  if(argc != 4) {
    fprintf(stderr,"Usage: %s 文字列ファイル 接尾辞配列ファイル 検索文字列\n",argv[0]);
    exit(1);
  }

  long * szp = malloc(sizeof(long));
  begin = clock();
  char * s0 = read_file(argv[1],szp);
  char * s1 = read_file(argv[2],szp);
  sa = split_str(s1, '\n',szp);
  long N = *szp;
  S = s0;

  char * sk = argv[3];
  char ** a = malloc(sizeof(char *) * N);
  if(!a) die("malloc");
  long i;
  for(i = 0;i < N;i++) a[i] = S + sa[i];
  search(sk,a,N,sa);
  end = clock();
  time += (double)(end - begin)/CLOCKS_PER_SEC * 1000.0;
  printf("Execution time: %.2f[ms]\n", time);
  return 0;
}

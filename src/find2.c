/* -*-coding: utf-8 -*-
 * Problem 2: find2.c
 * Student No.: 03-123010
 * Name: NGUYEN ANH TUAN
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils/util.h"
#include "utils/bsearcht.h"

int main(int argc, char * argv[]) {
  if(argc != 2 || argv[1] == NULL) {
    fprintf(stderr,"Usage: %s 検索文字列\n",argv[0]);
    exit(1);
  }

  char * s = "となりのきゃくはよくかきくうきゃくだ";
  int n = strlen(s);
  int k = strlen(argv[1]);
  int i, f = -1;
  char ** a = malloc(sizeof(char*) * n);
  for (i = 0; i < n; i++) {
    a[i] = s + i;
  }
  qsort(a, n, sizeof(char*), string_cmp);

  // binary search
  f = bsearch_ex(argv[1],a,n);
  if(f >= 0) {
    for(;f < n;f++) {
      if(strncmp(argv[1],a[f],k) != 0) break; // 複数現れる場合、出現しないまで、出現場所を表示
      if(f < n) printf("%d\n",(int)(n-strlen(a[f])));
    }
  }
  return 0;
}


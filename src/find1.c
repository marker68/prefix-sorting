/* -*-coding: utf-8 -*-
 * Problem 1: find1.c
 * Student No.: 03-123010
 * Name: NGUYEN ANH TUAN
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils/util.h"

int main(int argc, char * argv[]) {
  if(argc != 2 || argv[1] == NULL) {
    fprintf(stderr,"Usage: %s 検索文字列\n",argv[0]);
    exit(1);
  }

  char * s = "となりのきゃくはよくかきくうきゃくだ";
  //char * s = "world cup";
  int n = strlen(s);
  int i, f = -1;
  char ** a = malloc(sizeof(char*) * n);
  for (i = 0; i < n; i++) {
    a[i] = s + i;
  }
  qsort(a, n, sizeof(char*), string_cmp);

  for(i = 0; i < n; i++) {
    if(strcmp(argv[1],a[i]) == 0) {
      f = i;
      printf("%d\n",(int)(n-strlen(a[i])));
    }
  }
  if(f < 0) printf("-1\n");
  return 0;
}

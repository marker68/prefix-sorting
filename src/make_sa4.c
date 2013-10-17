/* -*-coding: utf-8 -*-
 * Option 7: make_sa4.c
 * Student No.: 03-123010
 * Name: NGUYEN ANH TUAN
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "utils/util.h"
#include "utils/inducedsort.h"

int main(int argc, char * argv[]) {
  if(argc != 4 || argv[2] == NULL || argv[1] == NULL || argv[3] == NULL) {
    fprintf(stderr,"Usage: %s 文字列ファイル 接尾辞配列ファイル N\n",argv[0]);
    exit(1);
  }
  
  long N , i, * sa;
  FILE * fp;
  unsigned char * s0;
  
  N = atol(argv[3]);
  s0 = (unsigned char *)read_file_n(argv[1], N);
  sa = malloc(sizeof(long) * N);
  // Induced sorting
  double start = get_current_milisec();
  inducedsort(s0,sa,N,256,0);
  double end = get_current_milisec();
  if((fp = fopen(argv[2],"w+"))==NULL){
    fprintf(stderr,"Error while writing to file\n");
    exit(1);
  }
  
  for (i = 0; i < N; i++) {
    if(i < N-1) fprintf(fp,"%ld\n", sa[i]);
    else fprintf(fp,"%ld",sa[i]);
  }
  
  fclose(fp);
  printf("Execution time: %.2f[ms]\n",end - start);
  return 0;
}

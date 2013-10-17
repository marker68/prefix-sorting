#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bsearcht.h"

long bsearch_ex(char * k, char ** a, long n) {
  long length = strlen(k);
  if(strncmp(k,a[0],length) <= 0) return 0;
  if(strncmp(a[n-1],k,length) < 0) return n;
  long l = 0, r = n-1;
  while(r - l > 1) {
    long c = (l+r)/2;
    if(strncmp(k,a[c],length) <= 0) r = c;
    else l = c;
  }
  if(strncmp(k,a[r],strlen(k)) != 0) return -1;
  return r;
}

void search1(char * k, char ** a,long n) {
  long length = strlen(k),  f = -1;
  long count = 0;
  // binary search
  f = bsearch_ex(k,a,n);
  long f0 = f;
  if(f0 >= 0) {
    for(;f0 < n;f0++) {
      if(strncmp(k,a[f0],length) != 0) break;
      if(f0 < n) count++; // found
    }
  }

  printf("Found keyword: %s(length = %ld byte(s)) in %ld place(s)\n",k,length,count);
}

void search(char * k, char ** a,long n, long * sa) {
  long length = strlen(k),  f = -1;
  long count = 0;
  // binary search
  f = bsearch_ex(k,a,n);
  long f0 = f;
  if(f0 >= 0) {
    for(;f0 < n;f0++) {
      if(strncmp(k,a[f0],length) != 0) break;
      if(f0 < n) count++; // found
    }
  }

  printf("Found keyword: %s(length = %ld byte(s)) in %ld place(s)\n",k,length,count);
  for(;f<f0;f++) printf("%ld\n",sa[f]);
}

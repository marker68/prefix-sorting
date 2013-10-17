#include <string.h>

void swap(long * a, long l, long r) {
  long c = a[l];
  a[l] = a[r];
  a[r] = c;
}

long partition(long * a, long l, long r, int(*compar)(const long, const long)) {
  long j = l + 1, i;
  for(i = l + 1; i < r; i++) 
    if(compar(a[i],a[l]) <= 0) {
      swap(a,i,j);
      j++;
    }
  swap(a,l,j-1);
  return j;
}

void qs(long * a, long l, long r, int(*compar)(const long, const long)) {
  if(r - l <= 1) return;
  else {
    long c = partition(a,l,r,compar);
#pragma omp task if(r - l > 100)
    qs(a,l,c-1,compar);
    qs(a,c,r,compar);
#pragma omp taskwait
  }
}

#ifndef _QUICKSORT_H_
#define _QUICKSORT_H_

void swap(long * a, long l, long r);
long partition(long * a, long l, long r, int(*compar)(const long, const long));
void qs(long * a, long l, long r, int(*compar)(const long, const long));

#endif

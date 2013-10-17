#ifndef _INDUCEDSORT_H
#define _INDUCEDSORT_H

#define bool int
void getBuckets(unsigned char *s, int *bkt, int n, int K, int cs, bool end);
void induceSAl(unsigned char *t, long *SA, unsigned char *s, int *bkt,
                int n, int K, int cs, bool end);
void induceSAs(unsigned char *t, long *SA, unsigned char *s, int *bkt,
                int n, int K, int cs, bool end);
void inducedsort(unsigned char *s, long *SA, int n, int K, int cs);

#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include "util.h"

int string_cmp(const void * a_, const void * b_) {
  const char * const * a = a_;
  const char * const * b = b_;
  return strcmp(*a, *b);
}

double get_current_milisec(void) {
  struct timeval tv;
  gettimeofday(&tv, NULL);
  return tv.tv_sec * 1E3 + (double)tv.tv_usec/1E3;
}

long * split_str(char * a, const char a_delim, long  * szp) {
  long * result = 0;
  size_t count  = 0;
  char* tmp     = a;
  char* last_comma = 0;
  while (*tmp) {
    if (a_delim == *tmp) { count++; last_comma = tmp;}
    tmp++;
  }
  count += last_comma < (a + strlen(a) - 1);
  count++;
  result = malloc(sizeof(long) * count);
  if(result) {
    size_t idx = 0;
    char * token = strtok(a, "\n");
    while(token) {
      *(result + idx++) = atol(strdup(token));
      token = strtok(0,"\n");
    }
    *(result + idx) = 0;
  }
  *szp = count - 1;
  return result;
}

void die(char * msg) {
  perror(msg); exit(1);
}
	  
/* (ファイルサイズ + 1)バイトの領域に,
   ファイルの中身全てを配列に入れて返す.
   最後のバイトには0を入れる.
   ファイルのサイズ(バイト数)を *szp に書いて返す */
char * read_file(char * file, long * szp) {
  int fd = open(file, O_RDONLY);
  if (fd == -1) die("open");
  off_t sz = lseek(fd, 0, SEEK_END);
  char * a = mmap(NULL, sz+1, PROT_READ|PROT_WRITE, MAP_PRIVATE, fd, 0);
  if (a == MAP_FAILED) die("mmap");
  a[sz] = 0;
  *szp = sz;
  return a;
}

/* using mmap to read only first N bytes and insert a '\0' to the end */
char * read_file_n(char * file, long N) {
  int fd = open(file, O_RDONLY);
  if (fd == -1) die("open");
  off_t sz = lseek(fd,0,SEEK_END);
  if(sz < N) die("Not enough data");
  char * a = mmap(NULL, N + 1, PROT_READ|PROT_WRITE, MAP_PRIVATE, fd, 0);
  if (a == MAP_FAILED) die("mmap");
  a[N] = 0;
  return a;
}

int first_byte(char c) {
  unsigned char u = c;
  if(0x80 <= u && u < 0xbf) return 0;
  return 1;
}

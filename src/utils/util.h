#ifndef _UTIL_H_
#define _UTIL_H_

int string_cmp(const void * a_, const void * b_);
double get_current_milisec(void);
long * split_str(char * a, const char a_delim, long  * szp);
void die(char * msg);
/* reading file by mmap */
char * read_file(char * file, long * szp);
/* using mmap to read only first N bytes and insert a '\0' to the end */
char * read_file_n(char * file, long N);
int first_byte(char c);

#endif

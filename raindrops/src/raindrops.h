#ifndef _raindrops_
#define _raindrops_

char *convert(char *buffer, int size, int number);

#define CHECK(A) if (!(A)) {printf("BSTR OP Failed\n"); goto error;}

#endif

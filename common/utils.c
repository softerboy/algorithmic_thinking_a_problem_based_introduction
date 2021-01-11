#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

#define hashsize(n) ((unsigned long)1 << (n))
#define hashmask(n) (hashsize(n) - 1)

char *read_line(int size) {
  int ch, len = 0;
  char *str = malloc(size);

  if (str == NULL) {
    fprintf(stderr, "malloc error\n");
    exit(1);
  }

  while((ch = getchar()) != EOF && (ch != '\n')) {
    str[len++] = ch;
    if (len == size) {
      size *= 2;
      str = realloc(str, size);
      if (str == NULL) {
        fprintf(stderr, "realloc error\n");
        exit(1);
      }
    }
  }

  str[len] = '\0';
  return str;
}

int oaat(char *key, unsigned long len, unsigned long bits) {
  unsigned long hash = 0, i;

  for (i = 0; i < len; ++i) {
    hash += key[i];
    hash += (hash << 10);
    hash ^= (hash >> 6);
  }

  hash += (hash << 3);
  hash ^= (hash >> 11);
  hash += (hash << 15);

  return hash & hashmask(bits);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

#define NUM_BITS 17
#define WORD_LENGTH 16

typedef struct word_node {
  char **word;
  struct word_node *next;
} word_node;

int in_hash_table(word_node *hash_table[], char *find, unsigned find_len);
void identify_compound_words(char *words[], word_node *hash_table[], int total_words);

int main() {
  static char *words[1 << NUM_BITS] = {NULL};
  static word_node *hash_table[1 << NUM_BITS] = {NULL};
  int total = 0;
  char *word;
  word_node *wordptr;
  unsigned length, word_code;
  word = read_line(WORD_LENGTH);
  while (*word) {
    words[total] = word;
    wordptr = malloc(sizeof(word_node));
    if (wordptr == NULL) {
      fprintf(stderr, "malloc error\n");
      exit(1);
    }
    length = strlen(word);
    word_code = oaat(word, length, NUM_BITS);
    wordptr->word = &words[total];
    wordptr->next = hash_table[word_code];
    hash_table[word_code] = wordptr;
    word = read_line(WORD_LENGTH);
    total++;
  }
  identify_compound_words(words, hash_table, total);
  return 0;
}

int in_hash_table(word_node *hash_table[], char *find, unsigned find_len) {
  unsigned word_code = oaat(find, find_len, NUM_BITS);
  word_node *wordptr = hash_table[word_code];
  while (wordptr) {
    if ((strlen(*(wordptr->word)) == find_len) && (strncmp(*(wordptr->word), find, find_len) == 0))
      return 1;
    wordptr = wordptr->next;
  }

  return 0;
}

void identify_compound_words(char *words[], word_node *hash_table[], int total_words) {
  int i, j;
  unsigned long len;
  for (i = 0; i < total_words; ++i) {
    len = strlen(words[i]);
    for (j = 1; j < len; ++j) {
      if (in_hash_table(hash_table, words[i], j) && in_hash_table(hash_table, &words[i][j], len - j)) {
        printf("%s\n", words[i]);
        break;
      }
    }
  }
}

#include <stdio.h>
#include <stdlib.h>

#define SIZE 100000

typedef struct snowflake_node {
  int snowflake[6];
  struct snowflake_node *next;
} snowflake_node;

int code(const int snowflake[]);
void identify_identical(snowflake_node *snowflakes[]);
int are_identical(const int snow1[], const int snow2[]);
int identical_left(const int snow1[], const int snow2[], int start);
int identical_right(const int snow1[], const int snow2[], int start);

int main() {
  static snowflake_node *snowflakes[SIZE] = {NULL};
  snowflake_node *snow;

  int n, i, j, snowflake_code;
  scanf("%d", &n);
  for (i = 0; i < n; ++i) {
    snow = malloc(sizeof(snowflake_node));
    if (snow == NULL) {
      fprintf(stderr, "malloc error\n");
      exit(1);
    }
    for (j = 0; j < 6; ++j)
      scanf("%d", &snow->snowflake[j]);

    snowflake_code = code(snow->snowflake);
    snow->next = snowflakes[snowflake_code];
    snowflakes[snowflake_code] = snow;
  }

  identify_identical(snowflakes);

  return 0;
}

int code(const int snowflake[]) {
  return (snowflake[0] + snowflake[1] + snowflake[2]
      + snowflake[3] + snowflake[4] + snowflake[5]) % SIZE;
}

void identify_identical(snowflake_node *snowflakes[]) {
  snowflake_node *node1, *node2;
  int i;
  for (i = 0; i < SIZE; ++i) {
    node1 = snowflakes[i];
    while (node1 != NULL) {
      node2 = node1->next;
      while (node2 != NULL) {
        if (are_identical(node1->snowflake, node2->snowflake)) {
          printf("Twin snowflakes found.\n");
          return;
        }
        node2 = node2->next;
      }
      node1 = node1->next;
    }
  }

  printf("No two snowflakes are alike.\n");
}

int are_identical(const int snow1[], const int snow2[]) {
  for (int start = 0; start < 6; ++start) {
    if (identical_right(snow1, snow2, start))
      return 1;
    if (identical_left(snow1, snow2, start))
      return 1;
  }
  return 0;
}

int identical_right(const int snow1[], const int snow2[], int start) {

  for (int offset = 0; offset < 6; ++offset) {
    if (snow1[offset] != snow2[(start + offset) % 6])
      return 0;
  }

  return 1;
}

int identical_left(const int snow1[], const int snow2[], int start) {
  int snow2_index;
  for (int offset = 0; offset < 6; ++offset) {
    snow2_index = start - offset;
    if (snow2_index < 0) snow2_index = snow2_index + offset;
    if (snow1[offset] != snow2[snow2_index])
      return 0;
  }

  return 1;
}
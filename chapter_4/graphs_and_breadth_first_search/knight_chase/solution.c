#include <stdio.h>

#define MAX_ROWS 99
#define MAX_COLS 99

typedef struct position {
  int row, col;
} position;

/*
 * A board is a two-dimensional array, and we can make a type definition
 * for that too. We’ll let it hold integers, which will correspond to numbers of
 * moves. We have a maximum of 99 rows and 99 columns, but we allocate one
 * extra row and column so that we can start indexing rows and columns at 1,
 * not 0:
 */
typedef int board[MAX_ROWS + 1][MAX_COLS + 1];

/*
 * Make an array type for holding the positions that we discover
 * during the BFS. We’ll make it big enough that it can hold every possible
 * square on the board:
 */
typedef position positions[MAX_ROWS * MAX_COLS];

/**
 * @param knight_row Starting row of knight
 * @param knight_col Starting column of knight
 * @param dest_row Desired row of destination
 * @param dest_col Desired column of destination
 * @param num_rows Number of rows in the board
 * @param num_cols Number of columns in the board
 * @return Minimum number of moves for the knight to go from its starting location to the destination.
 * If there’s no way for the knight to get to the destination, then we return -1.
 */
int find_distance(int knight_row, int knight_col, int dest_row, int dest_col, int num_rows, int num_cols);

void add_position(int from_row, int from_col, int to_row, int to_col,
                  int num_rows, int num_cols, positions new_positions, int *num_new_positions, board min_moves);

void solve(int pawn_row, int pawn_col, int knight_row, int knight_col, int num_rows, int num_cols);

int main() {
  int num_cases, i;
  int num_rows, num_cols, pawn_row, pawn_col, knight_row, knight_col;
  scanf("%d", &num_cases);
  for (i = 0; i < num_cases; ++i) {
    scanf("%d%d", &num_rows, &num_cols);
    scanf("%d%d", &pawn_row, &pawn_col);
    scanf("%d%d", &knight_row, &knight_col);
    solve(pawn_row, pawn_col, knight_row, knight_col, num_rows, num_cols);
  }
  return 0;
}

int find_distance(int knight_row, int knight_col, int dest_row, int dest_col, int num_rows, int num_cols) {

  /*
   * This array holds the positions discovered from the current round of BFS.
   * For example, it might be all of the positions discovered in round 3
   */
  positions cur_positions;
  int num_cur_positions;

  /*
   * This array holds the positions discovered in the next round of BFS.
   * For example, if cur_positions holds the positions discovered in round 3,
   * then new_positions will hold those positions discovered in round 4
   */
  positions new_positions;
  int num_new_positions;

  int i, j, from_row, from_col;
  board min_moves;

  /*
   * set all board square values to -1
   */
  for (i = 1; i <= num_rows; ++i)
    for (j = 1; j <= num_cols; ++j)
      min_moves[i][j] = -1;

  /*
   * set knight's initial square value to 0
   */
  min_moves[knight_row][knight_col] = 0;

  cur_positions[0] = (position) {knight_row, knight_col};
  num_cur_positions = 1;

  while (num_cur_positions > 0) {
    num_new_positions = 0;
    for (i = 0; i < num_cur_positions; ++i) {
      from_row = cur_positions[i].row;
      from_col = cur_positions[i].col;
      if (from_row == dest_row && from_col == dest_col)
        return min_moves[dest_row][dest_col];

      add_position(from_row, from_col, from_row + 1, from_col + 2,
                   num_rows, num_cols, new_positions, &num_new_positions, min_moves);

      add_position(from_row, from_col, from_row + 1, from_col - 2,
                   num_rows, num_cols, new_positions, &num_new_positions, min_moves);

      add_position(from_row, from_col, from_row - 1, from_col + 2,
                   num_rows, num_cols, new_positions, &num_new_positions, min_moves);

      add_position(from_row, from_col, from_row - 1, from_col - 2,
                   num_rows, num_cols, new_positions, &num_new_positions, min_moves);

      add_position(from_row, from_col, from_row + 2, from_col + 1,
                   num_rows, num_cols, new_positions, &num_new_positions, min_moves);

      add_position(from_row, from_col, from_row + 2, from_col - 1,
                   num_rows, num_cols, new_positions, &num_new_positions, min_moves);

      add_position(from_row, from_col, from_row - 2, from_col + 1,
                   num_rows, num_cols, new_positions, &num_new_positions, min_moves);

      add_position(from_row, from_col, from_row - 2, from_col - 1,
                   num_rows, num_cols, new_positions, &num_new_positions, min_moves);
    }

    num_cur_positions = num_new_positions;
    for (i = 0; i < num_cur_positions; ++i)
      cur_positions[i] = new_positions[i];
  }

  return -1;
}

void add_position(int from_row, int from_col, int to_row, int to_col, int num_rows, int num_cols,
                  positions new_positions, int *num_new_positions, board min_moves) {
  position new_position;
  if (to_row >= 1 && to_col >= 1 && to_row <= num_rows &&
      to_col <= num_cols && min_moves[to_row][to_col] == -1) {
    min_moves[to_row][to_col] = 1 + min_moves[from_row][from_col];
    new_position = (position) {to_row, to_col};
    new_positions[*num_new_positions] = new_position;
    (*num_new_positions)++;
  }
}

void solve(int pawn_row, int pawn_col, int knight_row, int knight_col, int num_rows, int num_cols) {
  int cur_pawn_row, num_moves, knight_takes;

  cur_pawn_row = pawn_row;
  num_moves = 0;
  while (cur_pawn_row < num_rows) {
    knight_takes = find_distance(knight_row, knight_col, cur_pawn_row, pawn_col, num_rows, num_cols);
    if (knight_takes >= 0 && num_moves >= knight_takes && (num_moves - knight_takes) % 2 == 0) {
      printf("Win in %d knight move(s).\n", num_moves);
      return;
    }

    cur_pawn_row++;
    num_moves++;
  }

  cur_pawn_row = pawn_row;
  num_moves = 0;
  while (cur_pawn_row < num_rows) {
    knight_takes = find_distance(knight_row, knight_col, cur_pawn_row + 1, pawn_col, num_rows, num_cols);
    if (knight_takes >= 0 && num_moves >= knight_takes && (num_moves - knight_takes) % 2 == 0) {
      printf("Stalemate in %d knight move(s).\n", num_moves);
      return;
    }
    cur_pawn_row++;
    num_moves++;
  }

  printf("Loss in %d knight move(s).\n", num_rows - pawn_row - 1);
}

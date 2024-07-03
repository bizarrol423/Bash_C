#ifndef SRC_CAT_S21_CAT_H_  //  SRC_CAT_S21_CAT_H_
#define SRC_CAT_S21_CAT_H_  //  SRC_CAT_S21_CAT_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_size 100

void s21_cat(int argc, char **argv);
void file_print();
int B_N_option(char symb, char next_symb, int currentStr);
int E_option(char symb);
int T_option(char symb);
int V_option(char symb);

typedef struct cat_string {
  int count_files;
  short b_opt, e_opt, n_opt, s_opt, t_opt, v_opt;
  char **file_args;
} cat_string;

#endif  // SRC_CAT_S21_CAT_H_

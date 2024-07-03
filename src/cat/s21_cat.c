#include "s_cat.h"

int main(int argc, char **argv) {
  s_cat(argc, argv);
  return 0;
}
cat_string pars_string = {.b_opt = 0,
                          .e_opt = 0,
                          .n_opt = 0,
                          .s_opt = 0,
                          .t_opt = 0,
                          .v_opt = 0,
                          .count_files = 0,
                          .file_args = NULL};

void s_cat(int argc, char **argv) {
  short error = 0;
  int i = 1;
  for (; i < argc && argv[i][0] == '-'; i++) {
    if (argv[i][1] == '-') {
      if (strcmp(argv[i], "--number-nonblank") == 0) {
        pars_string.b_opt = 1;
        continue;
      } else if (strcmp(argv[i], "--number") == 0) {
        pars_string.n_opt = 1;
        continue;
      } else if (strcmp(argv[i], "--squeeze-blank") == 0) {
        pars_string.s_opt = 1;
        continue;
      } else {
        fprintf(stderr, "nelegal flag\n");
        error = 1;
        break;
      }
    }
    for (int j = 1; j < (int)strlen(argv[i]); j++) {
      switch (argv[i][j]) {
        case 'b':
          pars_string.b_opt = 2;
          break;
        case 'E':
          pars_string.e_opt = 1;
          break;
        case 'e':
          pars_string.e_opt = 2;
          break;
        case 'n':
          pars_string.n_opt = 2;
          break;
        case 's':
          pars_string.s_opt = 1;
          break;
        case 'T':
          pars_string.t_opt = 1;
          break;
        case 't':
          pars_string.t_opt = 2;
          break;
        case 'v':
          pars_string.v_opt = 1;
          break;
        default:
          fprintf(stderr, "nelegal flag\n");
          error = 1;
          break;
      }
      if (error) break;
    }
    if (error) break;
  }
  if (!error) {
    pars_string.file_args = (char **)malloc(argc * sizeof(char *));
    for (int i = 0; i < argc; i++)
      pars_string.file_args[i] = (char *)malloc(max_size * sizeof(char));
    for (; i < argc; i++) {
      int tmp = pars_string.count_files;
      strcpy(pars_string.file_args[tmp], argv[i]);
      pars_string.count_files++;
    }
    if (argc > 1) file_print();
    for (int i = 0; i < argc; i++) free(pars_string.file_args[i]);
    free(pars_string.file_args);
  }
}

void file_print() {
  FILE *file_arg = NULL;
  int currentStr = 1;
  for (int i = 0; i < pars_string.count_files; i++) {
    file_arg = fopen(pars_string.file_args[i], "r");
    if (file_arg) {
      char next_symb = fgetc(file_arg);
      char symb = next_symb;
      if (next_symb != (char)EOF) {
        int print = 0, was_blank_line = 0;
        if (pars_string.b_opt != 1 && pars_string.n_opt != 1) currentStr = 1;
        next_symb = fgetc(file_arg);
        if (pars_string.s_opt && symb == '\n') was_blank_line = 1;
        if (symb != '\n') currentStr += B_N_option(symb, next_symb, currentStr);
        if (!T_option(symb) && !E_option(symb)) {
          int flag = 0;
          if (pars_string.v_opt) flag = V_option(symb);
          if (!flag) printf("%c", symb);
        }
        while (next_symb != (char)EOF) {
          symb = next_symb;
          next_symb = fgetc(file_arg);
          if (pars_string.s_opt) {
            if (symb == '\n') {
              short currrentLine = (next_symb == '\n') ? 1 : 0;
              if (was_blank_line && currrentLine == 1) continue;
              was_blank_line = currrentLine;
            }
          }
          if (!T_option(symb) && !E_option(symb)) {
            int flag = 0;
            if (pars_string.v_opt) flag = V_option(symb);
            if (!flag) printf("%c", symb);
          }
          if (symb == '\n')
            currentStr += B_N_option(symb, next_symb, currentStr);
        }
      }
      fclose(file_arg);
    } else {
      fprintf(stderr, "cat: %s: No such file or directory\n",
              pars_string.file_args[i]);
    }
  }
}

int T_option(char symb) {
  int retval = 0;
  if (pars_string.t_opt) {
    if (pars_string.t_opt == 2) retval = V_option(symb);
    if (symb == '\t') {
      printf("^I");
      retval = 1;
    }
  }
  return retval;
}

int B_N_option(char symb, char next_symb, int currentStr) {
  int retval = 0;
  if (pars_string.b_opt) {
    if (next_symb != '\n' && next_symb != (char)EOF) {
      printf("%6d\t", currentStr);
      retval = 1;
    }
  } else if (pars_string.n_opt) {
    if (next_symb != (char)EOF) {
      printf("%6d\t", currentStr);
      retval = 1;
    }
  }
  return retval;
}

int E_option(char symb) {
  int retval = 0;
  if (pars_string.e_opt) {
    if (pars_string.e_opt == 2 && pars_string.t_opt != 2)
      retval = V_option(symb);
    if (symb == '\n') printf("$");
  }
  return retval;
}

int V_option(char symb) {
  int retval = 0;
  char nonprint_symb = 32;
  switch (symb) {
    case 0:
      nonprint_symb = '@';
      break;
    case 1:
      nonprint_symb = 'A';
      break;
    case 2:
      nonprint_symb = 'B';
      break;
    case 3:
      nonprint_symb = 'C';
      break;
    case 4:
      nonprint_symb = 'D';
      break;
    case 5:
      nonprint_symb = 'E';
      break;
    case 6:
      nonprint_symb = 'F';
      break;
    case 7:
      nonprint_symb = 'G';
      break;
    case 8:
      nonprint_symb = 'H';
      break;
    case 11:
      nonprint_symb = 'K';
      break;
    case 12:
      nonprint_symb = 'L';
      break;
    case 13:
      nonprint_symb = 'M';
      break;
    case 14:
      nonprint_symb = 'N';
      break;
    case 15:
      nonprint_symb = 'O';
      break;
    case 16:
      nonprint_symb = 'P';
      break;
    case 17:
      nonprint_symb = 'Q';
      break;
    case 18:
      nonprint_symb = 'R';
      break;
    case 19:
      nonprint_symb = 'S';
      break;
    case 20:
      nonprint_symb = 'T';
      break;
    case 21:
      nonprint_symb = 'U';
      break;
    case 22:
      nonprint_symb = 'V';
      break;
    case 23:
      nonprint_symb = 'W';
      break;
    case 24:
      nonprint_symb = 'X';
      break;
    case 25:
      nonprint_symb = 'Y';
      break;
    case 26:
      nonprint_symb = 'Z';
      break;
    case 27:
      nonprint_symb = '[';
      break;
    case 28:
      nonprint_symb = '\\';
      break;
    case 29:
      nonprint_symb = ']';
      break;
    case 30:
      nonprint_symb = '^';
      break;
    case 31:
      nonprint_symb = '_';
      break;
    case 127:
      nonprint_symb = '?';
      break;
    default:
      nonprint_symb = 32;
      break;
  }
  if (nonprint_symb != 32) {
    printf("^%c", nonprint_symb);
    retval = 1;
  }
  return retval;
}

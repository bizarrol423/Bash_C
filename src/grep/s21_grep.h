#ifndef SRC_GREP_S21_GREP_H_  //  SRC_GREP_S21_GREP_H_
#define SRC_GREP_S21_GREP_H_  //  SRC_GREP_S21_GREP_H_
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct flags_a {
  int flag_e;  // регулярные выражения +
  int flag_i;  // нечуствителен к регистрам +
  int flag_v;  // инверсия +
  int flag_c;  // только количество строк +
  int flag_l;  // выводит только названия файла +
  int flag_n;  // нумерует строки +
  int flag_h;  // подавляет вывод названий файлов +
  int flag_s;  // убирает вывод ошибок +
  int flag_f;  // записывает файл в переменную и использует её
  int flag_o;  // выводит только совпадающую часть
};
typedef struct flags_a flags;
int flag_e(char *flag);
int flag_i(char *flag);
int flag_v(char *flag);
int flag_c(char *flag);
int flag_l(char *flag);
int flag_h(char *flag);
int flag_o(char *flag);
int flag_s(char *flag);
int flag_n(char *flag);
void namefile_flag_l(int flag_l, int string_i, char **file, int i);
void error_flag_s(int flag_s, int i, char **file);
int logic_flag_v(int flag_v, int status);
#endif  // SRC_GREP_S21_GREP_H_

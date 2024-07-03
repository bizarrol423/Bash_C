#include "s21_grep.h"

int main(int argc, char *argv[]) {
  char *console_string = NULL;  // консольная строка
  char *flag = NULL;            // флаги
  char *search_string = NULL;   // строка которую ищем
  int file_i = 1;               //  количество файлов
  int bool_flags = 0;
  int reg_flags = 0;
  char *line = NULL;      // строка
  int number_string = 0;  //  нумерация строки
  int status = 0;  // для проверки проходимости строки
  int string_i = 0;
  size_t len = 0;            // размер полчаемой строки
  flags f;                   // подключение структуры
  memset(&f, 0, sizeof(f));  //  отчищение структуры
  regex_t regex;             //  подключение структуры regex
  regmatch_t ff;             //  для флага о
  for (int i = 0; i < argc; i++) {
    console_string = argv[i];
    if (console_string[0] == '-') {  // получение данных о фалагах
      flag = console_string;
      f.flag_e = flag_e(flag);
      f.flag_i = flag_i(flag);
      f.flag_v = flag_v(flag);
      f.flag_c = flag_c(flag);
      f.flag_l = flag_l(flag);
      f.flag_n = flag_n(flag);
      f.flag_h = flag_h(flag);
      f.flag_s = flag_s(flag);
      f.flag_o = flag_o(flag);
      if (f.flag_e || f.flag_i || f.flag_v || f.flag_c || f.flag_l ||
          f.flag_n || f.flag_h || f.flag_s || f.flag_o) {
        bool_flags = 1;
      }
      i++;
      file_i = 2;
    }
  }
  for (int i = 0; i < argc; i++) {  //  поиск строки
    if (argv[i] == flag && (f.flag_e || f.flag_f)) {
      search_string = argv[i + 1];
      break;
    } else if ((argv[i] == flag && i != 1) || (flag == NULL)) {
      search_string = argv[1];
      break;
    }
  }
  if (argv[1] == flag) {
    search_string = argv[2];
  }
  if (search_string == NULL) {
    if (!f.flag_s) {
      fprintf(stderr, "grep [-cefhilnosv] [pattern] [file ...]\n");
    }
    exit(1);
  }
  char *file[argc - file_i];  // имена файлов
  int j = 0;
  if (!bool_flags && search_string == NULL) {
    search_string = argv[1];
  }
  for (int i = 1; i < argc; i++) {  // поиск файлов
    if (argv[i] != search_string && argv[i] != flag) {
      file[j] = argv[i];
      j++;
    }
  }
  if (f.flag_i) {  // проверка на флаг i
    reg_flags = REG_ICASE;
  }
  if (flag != NULL && ((size_t)(f.flag_c + f.flag_e + f.flag_f + f.flag_h +
                                f.flag_i + f.flag_l + f.flag_n + f.flag_o +
                                f.flag_s + f.flag_v) != strlen(flag) - 1)) {
    fprintf(stderr, "grep [-cefhilnosv] [pattern] [file ...]\n");
  } else {
    regcomp(&regex, search_string, reg_flags);  //  компиляция regex
    for (int i = 0; i < argc - file_i - 1; i++) {
      FILE *open_file = NULL;  //  открытие файла
      if ((open_file = fopen(file[i], "r")) != NULL) {
        while ((getline(&line, &len, open_file)) != -1) {
          status = regexec(&regex, line, 0, NULL, 0);
          number_string++;
          status = logic_flag_v(f.flag_v, status);
          if (status == 0) {  //  вывод если всё подходит
            if (f.flag_c || f.flag_l) {
              string_i++;
            } else {
              if (argc - file_i - 1 > 1 && !f.flag_h) {
                printf("%s:", file[i]);
              }
              if (f.flag_n) {
                printf("%d:", number_string);
              }
              if (f.flag_o && !f.flag_v) {
                char *str = line;  // меняем адресс а не переменную
                while (!regexec(&regex, str, (size_t)1, &ff, 0)) {
                  str += ff.rm_eo;
                  printf("%s\n", search_string);
                }
              } else {
                printf("%s", line);
                if (line[strlen(line) - 1] !=
                    '\n') {  // добавление \n если его нет
                  printf("\n");
                }
              }
            }
          }
        }
      } else {
        error_flag_s(f.flag_s, i, file);
      }
      if (f.flag_c) {
        if (f.flag_l) {
          if (string_i != 0) {
            string_i = 1;
          }
        }
        if (argc - file_i - 1 > 1 && !f.flag_h) {
          printf("%s:", file[i]);
        }
        printf("%d\n", string_i);
      }
      namefile_flag_l(f.flag_l, string_i, file, i);
      string_i = 0;
      number_string = 0;
      fclose(open_file);
    }
    regfree(&regex);
    free(line);
  }
}
int flag_e(char *flag) { return (strrchr(flag, 'e') != NULL); }
int flag_i(char *flag) { return (strrchr(flag, 'i') != NULL); }
int flag_v(char *flag) { return (strrchr(flag, 'v') != NULL); }
int flag_c(char *flag) { return (strrchr(flag, 'c') != NULL); }
int flag_l(char *flag) { return (strrchr(flag, 'l') != NULL); }
int flag_h(char *flag) { return (strrchr(flag, 'h') != NULL); }
int flag_o(char *flag) { return (strrchr(flag, 'o') != NULL); }
int flag_s(char *flag) { return (strrchr(flag, 's') != NULL); }
int flag_n(char *flag) { return (strrchr(flag, 'n') != NULL); }
void namefile_flag_l(int flag_l, int string_i, char **file, int i) {
  if (flag_l) {
    if (string_i != 0) {
      printf("%s\n", file[i]);
    }
  }
}
void error_flag_s(int flag_s, int i, char **file) {
  if (!flag_s && file[i] != NULL) {
    fprintf(stderr, "./s21_grep: %s: No such file or directory\n", file[i]);
  }
}
int logic_flag_v(int flag_v, int status) {
  if (flag_v) {  // при активном флаге -v инвертирует
                 // логику
    status = !status;
  }
  return status;
}

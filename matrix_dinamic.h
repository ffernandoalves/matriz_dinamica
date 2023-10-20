#ifndef MATRIX_DINAMIC_H
#define MATRIX_DINAMIC_H

#include <stdio.h>
#include <stdlib.h>

#if defined(_WIN32)
#define CLEAR _system_clean("cls")
#elif defined(__linux__)
#define CLEAR _system_clean("clear")
#endif

static void _system_clean(const char *str) {
  int result = system(str);
  // if (result != 0) {
  //   // TODO: Tratar o caso de falha na execução do comando
  // }
}

#define DEFINE_TYPE(t) (compare(TYPE_NAME(t), "char"))
#define TYPE_NAME(Arg) #Arg

typedef enum { TYPE_INT = 1, TYPE_CHAR = 2 } VariableType;

typedef union {
  int **m_int;
  char **m_char;
} matriz;

typedef struct {
  int line;
  int col;
  VariableType type;
  matriz matriz;
} Mat;

int compare(const char *str, const char *type_name);
size_t string_len(const char *str);
VariableType convert_to(void);
void alloc_mat_int(int ***mat, int l, int c);
void alloc_mat_char(char ***mat, int l, int c);
void free_mat_int(int ***mat, int l, int c);
void free_mat_char(char ***mat, int l, int c);
void fill_mat_int(int **mat, int l, int c, int default_value);
void fill_mat_char(char **mat, int l, int c, char default_value);
void show_mat_int(int **mat, int l, int c);
void show_mat_char(char **mat, int l, int c);
void Mat_alloc(Mat *mat);
void Mat_free(Mat *mat);
void Mat_fill(Mat *mat);
void Mat_show(Mat *mat);

#endif // MATRIX_DINAMIC_H
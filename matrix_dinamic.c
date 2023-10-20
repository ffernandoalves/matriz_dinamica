#include "matrix_dinamic.h"

size_t string_len(const char *str) {
  const char *ptr = str;
  while (*ptr != '\0') {
    ptr++;
  }
  return ptr - str;
}

int compare(const char *str, const char *type_name) {
  size_t len_str = string_len(str);
  size_t len_type_name = string_len(type_name);
  if (len_str != len_type_name) {
    return 0;
  }
  for (size_t i = 0; i < len_str; i++) {
    if (str[i] != type_name[i]) {
      return 0;
    }
  }
  return 1;
}

VariableType convert_to() {
  printf("Escolha o tipo da matriz:\n");
  printf("[1] - int\n");
  printf("[2] - char\n");
  VariableType type;
  int t;
  int result = scanf("%d", &t);
  // if (result != 1) {
  //     // TODO: tratar caso algum elemento não tenha sido lido corretamente
  // }

  if (t == 1) {
    type = TYPE_INT;
  } else if (t == 2) {
    type = TYPE_CHAR;
  } else {
    CLEAR;
    convert_to();
  }
  return type;
}

void alloc_mat_int(int ***mat, int l, int c) {
  *mat = (int **)malloc(sizeof(int *) * l);
  for (int i = 0; i < l; i++) {
    (*mat)[i] = (int *)malloc(sizeof(int) * c);
  }
}

void alloc_mat_char(char ***mat, int l, int c) {
  *mat = (char **)malloc(sizeof(char *) * l);
  for (int i = 0; i < l; i++) {
    (*mat)[i] = (char *)malloc(sizeof(char) * c);
  }
}

void Mat_alloc(Mat *mat) {
  if (mat->type == TYPE_INT) {
    alloc_mat_int(&mat->matriz.m_int, mat->line, mat->col);
  } else if (mat->type == TYPE_CHAR) {
    alloc_mat_char(&mat->matriz.m_char, mat->line, mat->col);
  }
}

void free_mat_int(int ***mat, int l, int c) {
  for (int i = 0; i < l; i++) {
    free((*mat)[i]);
  }
  free((*mat));
}

void free_mat_char(char ***mat, int l, int c) {
  for (int i = 0; i < l; i++) {
    free((*mat)[i]);
  }
  free((*mat));
}

void Mat_free(Mat *mat) {
  if (mat->type == TYPE_INT) {
    free_mat_int(&mat->matriz.m_int, mat->line, mat->col);
  } else if (mat->type == TYPE_CHAR) {
    free_mat_char(&mat->matriz.m_char, mat->line, mat->col);
  }
}

void fill_mat_int(int **mat, int l, int c, int default_value) {
  for (int i = 0; i < l; i++) {
    for (int j = 0; j < c; j++) {
      mat[i][j] = default_value;
    }
  }
}

void fill_mat_char(char **mat, int l, int c, char default_value) {
  for (int i = 0; i < l; i++) {
    for (int j = 0; j < c; j++) {
      mat[i][j] = default_value;
    }
  }
}

void Mat_fill(Mat *mat) {
  if (mat->type == TYPE_INT) {
    fill_mat_int(mat->matriz.m_int, mat->line, mat->col, 0);
  } else if (mat->type == TYPE_CHAR) {
    fill_mat_char(mat->matriz.m_char, mat->line, mat->col, '*');
  }
}

void show_mat_int(int **mat, int l, int c) {
  for (int i = 0; i < l; i++) {
    for (int j = 0; j < c; j++) {
      printf("%d ", mat[i][j]);
    }
    printf("\n");
  }
}

void show_mat_char(char **mat, int l, int c) {
  for (int i = 0; i < l; i++) {
    for (int j = 0; j < c; j++) {
      printf("%c ", mat[i][j]);
    }
    printf("\n");
  }
}

void Mat_show(Mat *mat) {
  if (mat->type == TYPE_INT) {
    show_mat_int(mat->matriz.m_int, mat->line, mat->col);
  } else if (mat->type == TYPE_CHAR) {
    show_mat_char(mat->matriz.m_char, mat->line, mat->col);
  }
}

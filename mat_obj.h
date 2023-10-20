#ifndef MAT_OBJ_H
#define MAT_OBJ_H

#include "matrix_dinamic.h"

typedef void (*voidOperation)(void);
typedef int (*intOperation)(void);
typedef VariableType (*VariableTypeOperation)(void);
typedef matriz *(*matrizPointerOperation)(void);

typedef struct {
  VariableTypeOperation type;
  intOperation line;
  intOperation col;
  voidOperation alloc;
  voidOperation fill;
  voidOperation show;
  voidOperation free;
  matrizPointerOperation matriz;
} MatObj;

void m_alloc(void);
void m_fill(void);
void m_show(void);
void m_free(void);
int m_line(void);
int m_col(void);
int m_type(void);
matriz *m_matriz();
void init_MatObj(MatObj *mat_obj, Mat *mat, VariableType *type, int *l, int *c);
void destructor_MatObj(MatObj *mat_obj, Mat *mat);

#endif // MAT_OBJ_H
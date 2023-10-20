#include "mat_obj.h"

Mat *_mat;

void m_alloc() { Mat_alloc(_mat); }
void m_fill() { Mat_fill(_mat); }
void m_show() { Mat_show(_mat); }
void m_free() { Mat_free(_mat); }
int m_line() { return _mat->line; }
int m_col() { return _mat->line; }
int m_type() { return _mat->type; }
matriz *m_matriz() { return &_mat->matriz; }

void init_MatObj(MatObj *mat_obj, Mat *mat, VariableType *type, int *l,
                 int *c) {
  mat->type = *type;
  mat->line = *l;
  mat->col = *c;
  _mat = mat;

  mat_obj->alloc = m_alloc;
  mat_obj->fill = m_fill;
  mat_obj->show = m_show;
  mat_obj->free = m_free;
  mat_obj->line = m_line;
  mat_obj->col = m_col;
  mat_obj->matriz = m_matriz;

  mat_obj->alloc();
}

void destructor_MatObj(MatObj *mat_obj, Mat *mat) {
  if (mat_obj) {
    mat_obj->free();
  }
}
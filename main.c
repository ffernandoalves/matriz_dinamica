/*
compile:
$ gcc main.c mat_obj.c matrix_dinamic.c -o mat
*/

#include "mat_obj.h"

int main(void) {
  MatObj mob;
  Mat mat;

  VariableType type = convert_to();

  int x, y;

  printf("Digite a quantidade de linhas: ");
  int result_x = scanf("%d", &x);

  printf("Digite a quantidade de colunas: ");
  int result_y = scanf("%d", &y);

  init_MatObj(&mob, &mat, &type, &x, &y);

  mob.fill();
  mob.show();

  // printf("%d", mob.matriz()->m_int[0][0]);
  // mob.free();
  destructor_MatObj(&mob, &mat);

  return 0;
}
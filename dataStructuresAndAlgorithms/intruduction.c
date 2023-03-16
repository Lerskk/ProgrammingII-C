#include <stdio.h>

#define YES 1
#define NO 0

#line 3000

#ifndef TRUE

#else
#undef TRUE
#define TRUE 1
#endif

#ifdef TRUE
#undef TRUE
#define TRUE 1
#endif

#if (TRUE != 0)
#undef TRUE
#define TRUE 0
#else
#define FALSE 1
#endif

#define SQUARE_VOLUMEN(x) x *x *x
#define PI 3.1415
#define SPHERE_VOLUMEN(x) ((4.0 / 3.0) * PI * x * x * x)

#define SUM(x, y) x + y
#define MIN(x, y) ((x < y) ? x : y)

#define MIN2(x, y, z) (MIN(MIN(x, y), MIN(y, z)))

#define PRINT(x) printf("%s", x)

#define PRINTARR(x, n)                                                         \
  for (int i = 0, i < n, i++) {                                                \
    printf("%d ", x[i])                                                        \
  }

int main() {
  printf("%d\n", SQUARE_VOLUMEN(3));

  for (int i = 1; i < 10; i++)
    printf("%f\n", SPHERE_VOLUMEN(i));

  printf("The sum of 5 and 8 is %d\n", SUM(5, 8));

  int a, b, c;
  scanf("%d", &a);
  scanf("%d", &b);
  scanf("%d", &c);

  printf("The min between %d %d is %d\n", a, b, MIN(a, b));

  printf("The min between %d %d %d is %d\n", a, b, c, MIN2(a, b, c));
  PRINT("hello\n");

  PRINTARR([ 1, 8, 9 ], 3)
  return 0;
}

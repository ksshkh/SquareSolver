#include <TXLib.h>
#include <math.h>

int main() {
  double a, b, c, D, x1, x2, x;
  printf("¬ведите коэффициенты a, b, c, чтобы решить квадратное уравнение вида\nax^2 + bx + c = 0\n");
  printf("a = ");
  scanf("%lf", &a);
  printf("b = ");
  scanf("%lf", &b);
  printf("c = ");
  scanf("%lf", &c);
  D = b * b - 4 * a * c;
  if (D > 0) {
    x1 = (-b + sqrt(D)) / (2 * a);
    x2 = (-b - sqrt(D)) / (2 * a);
    printf("x1 = %.2lf\nx2 = %.2lf\n", x1, x2);
  }
  else if (D == 0) {
    x = (-b + sqrt(D)) / (2 * a);
    printf("x = %.2lf\n", x);
  }
  else
    printf("–ешений не существует.\n");
  return 0;
}

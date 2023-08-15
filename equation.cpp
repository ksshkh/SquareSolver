#include <TXLib.h>
#include <math.h>

#define EPS 1e-9

bool compare(double x, double y);

int main() {

  double a = 0;
  double b = 0;
  double c = 0;
  double D = 0;
  double x1 = 0;
  double x2 = 0;
  double x = 0;

  printf("Введите коэффициенты a, b, c, чтобы решить квадратное уравнение вида\nax^2 + bx + c = 0\n");
  printf("a = ");
  while (scanf("%lf", &a) != 1) {
    fflush(stdin);
    printf("Введите число, а не что-то другое\na = ");
  }
  printf("b = ");
  while (scanf("%lf", &b) != 1) {
    fflush(stdin);
    printf("Введите число, а не что-то другое\nb = ");
  }
  printf("c = ");
  while (scanf("%lf", &c) != 1) {
    fflush(stdin);
    printf("Введите число, а не что-то другое\nc = ");
  }

  if (compare(a, 0) == 1) {
    if (compare(b, 0) == 0) {
      x = (-c) / b;
      printf("x = %.2lf", x);
    }
    else {
      if (compare(c, 0) == 1) {
        printf("x - любое число.");
      }
      else {
        printf("Решений нет.");
      }
    }
  }
  else {
    D = b * b - 4 * a * c;
    if (D > 0) {
      x1 = (-b + sqrt(D)) / (2 * a);
      x2 = (-b - sqrt(D)) / (2 * a);
      printf("x1 = %.2lf\nx2 = %.2lf\n", x1, x2);
    }
    else if (compare(D, 0) == 1) {
      x = (-b + sqrt(D)) / (2 * a);
      printf("x = %.2lf\n", x);
    }
    else {
      printf("Решений не существует.\n");
    }
  }
  return 0;
}

bool compare(double x, double y) {
  return fabs(x - y) < EPS;
}

#include <TXLib.h>
#include <math.h>

#define EPS 1e-9

bool compare(double x, double y);
double discriminant(double a, double b, double c);
double root1(double b, double D, double a);
double root2(double b, double D, double a);

int main() {

  double a = 0;
  double b = 0;
  double c = 0;
  double D = 0;
  double x1 = 0;
  double x2 = 0;

  printf("Введите коэффициенты a, b, c, чтобы решить квадратное уравнение вида\nax^2 + bx + c = 0\n");
  printf("a = ");
  if (!scanf("%lf", &a)) {
    printf("Принимаются только числа. Запустите программу еще раз.");
    return 0;
  }
  printf("b = ");
  if (!scanf("%lf", &b)) {
    printf("Принимаются только числа. Запустите программу еще раз.");
    return 0;
  }
  printf("c = ");
  if (!scanf("%lf", &c)) {
    printf("Принимаются только числа. Запустите программу еще раз.");
    return 0;
  }

  if (compare(a, 0)) {
    if (!compare(b, 0)) {
      x1 = (-c) / b;
      printf("x = %.2lf", x1);
    }
    else {
      if (compare(c, 0)) {
        printf("x - любое число.");
      }
      else {
        printf("Решений нет.");
      }
    }
  }
  else {
    D = discriminant(a, b, c);
    if (D > 0) {
      x1 = root1(b, D, a);
      x2 = root2(b, D, a);
      printf("x1 = %.2lf\nx2 = %.2lf\n", x1, x2);
    }
    else if (compare(D, 0)) {
      x1 = root1(b, D, a);
      printf("x = %.2lf\n", x1);
    }
    else {
      printf("Решений не существует.\n");
    }
  }
  return 0;
}

double discriminant(double a, double b, double c) {
  return b * b - 4 * a * c;
}

bool compare(double x, double y) {
  return fabs(x - y) < EPS;
}

double root1(double b, double D, double a) {
  return (-b + sqrt(D)) / (2 * a);
}
double root2(double b, double D, double a) {
  return (-b - sqrt(D)) / (2 * a);
}

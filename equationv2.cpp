#include <TXLib.h>
#include <math.h>

#define EPS 1e-9

enum solutions {
  NO_ROOTS,
  SINGLE_ROOT,
  TWO_ROOTS,
  INFINITY_ROOTS
};

bool compare(double x, double y);
int root_finder(double a, double b, double c, double * x1, double * x2);
double input(char letter);

int main() {

  double a = 0;
  double b = 0;
  double c = 0;
  double x1 = 0;
  double x2 = 0;

  printf("Введите коэффициенты a, b, c, чтобы решить квадратное уравнение вида\nax^2 + bx + c = 0\n");
  a = input('a');
  b = input('b');
  c = input('c');

  switch (root_finder(a, b, c, &x1, &x2)) {
    case NO_ROOTS:
      printf("Решений нет.");
      break;
    case SINGLE_ROOT:
      printf("x = %.5lf", x1);
      break;
    case TWO_ROOTS:
      printf("x1 = %.5lf\nx2 = %.5lf", x1, x2);
      break;
    default:
      printf("x - любое число.");
      break;
  }

  return 0;
}

bool compare(double x, double y) {
  return fabs(x - y) < EPS;
}

double input(char letter) {
  double koef;
  printf("%c = ", letter);
  while (scanf("%lf", &koef) != 1 && koef != EOF) {
    scanf("%*s");
    printf("Введите число\n");
    printf("%c = ", letter);
  }
  return koef;
}

int root_finder(double a, double b, double c, double * x1, double * x2) {
  double D = 0;
  if (compare(a, 0)) {
    if (!compare(b, 0)) {
      *x1 = (-c) / b;
      return SINGLE_ROOT;
    }
    else {
      if (compare(c, 0)) {
        return INFINITY_ROOTS;
      }
      else {
        return NO_ROOTS;
      }
    }
  }
  else {
    D = b * b - 4 * a * c;
    if (D > 0) {
      *x1 = (-b + sqrt(D)) / (2 * a);
      *x2 = (-b - sqrt(D)) / (2 * a);
      return TWO_ROOTS;
    }
    else if (compare(D, 0)) {
        *x1 = (-b + sqrt(D)) / (2 * a);
        return SINGLE_ROOT;
      }
    else {
        return NO_ROOTS;
      }
  }
}

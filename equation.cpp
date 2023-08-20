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
void run_all_tests(void);
bool test_root_finder(double a, double b, double c, double x1_exp, double x2_exp, int num_exp);

#define RUN_TEST(a, b, c, x1_exp, x2_exp, num_exp) \
++counter; \
  if (test_root_finder(a, b, c, x1_exp, x2_exp, num_exp) == 1) { \
    ++counter_true; \
  } \
  else { \
    printf("%d\n", counter); \
  }

int main() {
  run_all_tests();
  return 0;

  double a = 0;
  double b = 0;
  double c = 0;
  double x1 = 0;
  double x2 = 0;

  printf("Введите коэффициенты a, b, c, чтобы решить квадратное уравнение вида\nax^2 + bx + c = 0\n");
  printf("(Программа принимает только числа)\n");
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
  if (scanf("%lf", &koef) != 1 || koef == EOF) {
    printf("Вы ввели не число. Запустите программу еще раз.");
    exit(EXIT_FAILURE);
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

bool test_root_finder(double a, double b, double c, double x1_exp, double x2_exp, int num_exp) {
	double x1 = 0;
  double x2 = 0;
	int num = root_finder(a, b, c, &x1, &x2);
  if (compare(x1_exp, x1) && compare(x2_exp, x2) && num == num_exp) {
	  return true;
  }
  else {
    return false;
  }
}

void run_all_tests(void) {

  int counter = 0, counter_true = 0;

	RUN_TEST(0, 0, 0, 0, 0, INFINITY_ROOTS);
	RUN_TEST(0, 0, 100, 0, 0, NO_ROOTS);
  RUN_TEST(0, 0, 5.6, 0, 0, NO_ROOTS);
  RUN_TEST(78, 2, 56, 0, 0, NO_ROOTS);
  RUN_TEST(-37, 16, -64, 0, 0, NO_ROOTS);
  RUN_TEST(0, 37, -74, 2, 0, SINGLE_ROOT);
  RUN_TEST(1, 2, 1, -1, 0, SINGLE_ROOT);
  RUN_TEST(1, 5, 6, -2, -3, TWO_ROOTS);
  RUN_TEST(56, -56, 0, 1, 0, TWO_ROOTS);
  RUN_TEST(55, 0, 46, 0, 0, NO_ROOTS);
  RUN_TEST(64, 0, -169, 1.625, -1.625, TWO_ROOTS);

	printf("%d\\%d tests passed!\n", counter_true, counter);
}

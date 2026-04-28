#include <math.h>

static const double msPerDay = 86400000.0;

static double TimeFromYear(double y);
static double pmod(double x, double y);
static int InLeapYear(double y);
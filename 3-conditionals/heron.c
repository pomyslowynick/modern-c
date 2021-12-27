#include <stdlib.h>
#include <stdio.h>

/* lower and upper iteration limits centered around 1.0 */
static double const eps1m01 = 1.0 - 0x1P-01;
static double const eps1p01 = 1.0 + 0x1P-01;
static double const eps1m24 = 1.0 - 0x1P-24;
static double const eps1p24 = 1.0 + 0x1P-24;

int main(int argc, char* argv[]) {
    for (int i = 1; i < argc; ++i)
    {                                        // process args
        double const a = strtod(argv[i], 0); // arg - > double
        double x = 1.0;
        for (;;)
        { // by powers of 2
            double prod = a * x;
            if (prod < eps1m01)
            {
                printf("%.5f\n x before doubling when prod smaller\n", x);
                x *= 2.0;
                printf("%.5f\n x when prod smaller than eps1m01\n\n", x);
            }
            else if (eps1p01 < prod)
            {
                printf("%.5f\n x before halving when prod bigger\n", x);
                x *= 0.5;
                printf("%.5f\n x when prod bigger than eps1p01\n\n", x);
            }
            else
            {
                break;
            }
        }
        for (;;)
        { // Heron approximation
            double prod = a * x;
            if ((prod < eps1m24) || (eps1p24 < prod))
            {
                x *= (2.0 - prod);
            }
            else
            {
                break;
            }
        }
        printf("heron :a=%.5e,\tx=%.5e,\ta *x=%.12f\n",
               a, x, a * x);
    }
    return EXIT_SUCCESS;
}
#include <stddef.h>

// void double_swap (double p0 [ static 1] , double p1 [ static 1]) {
//     double tmp = p0[0];
//     p0[0] = p1[0];
//     p1[0] = tmp;
// }

void double_swap ( double * p0 , double * p1 ) {
    double tmp = * p0 ;
    * p0 = * p1 ;
    * p1 = tmp ;
}

double sum1 ( size_t len , double const* a ) {
    double ret = 0.0;
    for (double const* p = a ; p < a + len ; ++ p) {
        ret += *p ;
    }
    return ret;
}
double sum2 ( size_t len , double const* a ) {
    double ret = 0.0;
    for (double const* const aStop = a + len ; a < aStop ; ++ a) {
        ret += *a ;
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    double a[10] = {0,1,2,3,4,5,6,7,8,9};
    double sum = sum2(10, &a[0]);
    double firstD = 10;
    double secondD = 20;
    double* pointerFirstD = &firstD;
    double_swap(pointerFirstD, &secondD);
    return 0;
}

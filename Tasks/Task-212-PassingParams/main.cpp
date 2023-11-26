#include "mbed.h"
#include <cstdio>

typedef struct {
  double real;
  double imag;
} ComplexNumber_C;

ComplexNumber_C complexAdd(const ComplexNumber_C a, const ComplexNumber_C b) {
    ComplexNumber_C y = a;
    y.real += b.real;
    y.imag += b.imag;
    return y;
}
ComplexNumber_C complexConjugate(const ComplexNumber_C a){
    ComplexNumber_C y = a;
    y.imag = -1*y.imag;
    return y;
}
ComplexNumber_C complexNegate(const ComplexNumber_C a){
    ComplexNumber_C y = a;
    y.real = -1*y.real;
    y.imag = -1*y.imag;
    return y;
}
ComplexNumber_C complexSubtract(const ComplexNumber_C a, const ComplexNumber_C b) {
    ComplexNumber_C c = complexNegate(b);
    ComplexNumber_C y = complexAdd(a,c);
    return y;
}
ComplexNumber_C complexMag(const ComplexNumber_C a){
    ComplexNumber_C result;
    result.real = sqrt(a.real*a.real + a.imag*a.imag);
    result.imag = 0;
    return result;
}
ComplexNumber_C complexMultiply(const ComplexNumber_C a, const ComplexNumber_C b) {
ComplexNumber_C y;
y.real = (a.real*b.real)-(a.imag*b.imag);
y.imag = (a.real*b.imag)+(b.real*a.imag);
return y;
}
ComplexNumber_C complexDivide(const ComplexNumber_C a, const ComplexNumber_C b) {
ComplexNumber_C e = (complexMultiply(a, complexConjugate(b)));
ComplexNumber_C y;
ComplexNumber_C n = complexMag(b);
double m = sqrt(n.real);
y.real = e.real/m;
y.imag = e.imag/m;
return y;
}
ComplexNumber_C complexArgument(const ComplexNumber_C a){
ComplexNumber_C arg;
arg.real = atan(a.imag/a.real);
arg.imag = 0;
return arg;
}

void complexDisplay(const char *strName, const ComplexNumber_C u) {
    printf("%s = %f + j%f\n", strName, u.real, u.imag);
}


// TASK - write and test complexConjugate, complexNegate, complexSubtract, complexMagnitude, complexMultiply and complexDivide

int main() {
    printf("\n\nTASK312\n");

    double realp;
    double imagp;
    double realq;
    double imagq;
    //Create instance of a complex number
    printf("Originally, p = 2 + 3j and q = 1 + j now enter some new values.");
    printf("Enter Re(p)");
    scanf("%lf" , &realp);
    printf("Enter Im(p)");
    scanf("%lf" , &imagp);

    printf("Enter Re(q)");
    scanf("%lf" , &realq);
    printf("Enter Im(q)");
    scanf("%lf", &imagq);


    ComplexNumber_C p = {realp, imagp};
    ComplexNumber_C q = {realq, imagq};
    complexDisplay("p", p);
    complexDisplay("q", q);
 
    ComplexNumber_C sum = complexAdd(p, q);
    complexDisplay("p+q", sum);
    ComplexNumber_C pbar = complexConjugate(p);
    complexDisplay("p*", pbar);
    ComplexNumber_C qbar = complexConjugate(q);
    complexDisplay("q*", qbar);
    ComplexNumber_C difference = complexSubtract(p, q);
    complexDisplay("p-q", difference);
    ComplexNumber_C magp = complexMag(p);
    ComplexNumber_C magq = complexMag(q);
    complexDisplay("|p|", magp);
    complexDisplay("|q|", magq);
    ComplexNumber_C product = complexMultiply(p, q);
    complexDisplay("pxq", product);
    ComplexNumber_C quotientponq = complexDivide(p,q);
    complexDisplay("p/q", quotientponq);
    ComplexNumber_C quotientqonp = complexDivide(q, p);
    complexDisplay("q/p", quotientqonp);
    ComplexNumber_C argp = complexArgument(p);
    complexDisplay("arg(p)", argp);
    ComplexNumber_C argq = complexArgument(q);
    complexDisplay("arg(q)", argq);
    
    while (true) {
    }
}

#include "mbed.h"

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


void complexDisplay(const char *strName, const ComplexNumber_C u) {
    printf("%s = %f + j%f\n", strName, u.real, u.imag);
}


// TASK - write and test complexConjugate, complexNegate, complexSubtract, complexMagnitude, complexMultiply and complexDivide

int main() {
    printf("\n\nTASK312\n");

    //Create instance of a complex number
    ComplexNumber_C p = {2.0, 3.0};
    ComplexNumber_C q = {1.0, 1.0};
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

    
    while (true) {
    }
}

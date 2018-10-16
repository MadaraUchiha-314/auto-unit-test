/*
* Lets define a complex number
*/
struct Complex {
    int real; // The real part
    int img; // The imaginary part
};

/*
* A simple function which takes a complex number returns the square of the modulo.
*/
int moduloSquareComplex(struct Complex c) {
    return c.real*c.real + c.img*c.img;
}

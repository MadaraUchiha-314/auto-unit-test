/*
* Lets define a complex number
*/
struct Point {
    int x; // The real part
    int y; // The imaginary part
};

struct Distance {
    struct Point p1;
    struct Point p2;
};

/*
* A simple function which takes a complex number returns the square of the modulo.
*/
int CalcDistanceSquare(struct Distance d) {
    return (d.p1.x - d.p2.x)*(d.p1.x - d.p2.x) + (d.p1.y - d.p2.y)*(d.p1.y - d.p2.y);
}

/*
* This is a Point
*/
struct Point {
    int x; // The real part
    int y; // The imaginary part
};

struct Point scalarMultiplication(struct Point p, int scalar) {
    return (struct Point) {
        .x = scalar * p.x,
        .y = scalar * p.y
    };
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Point {
    int x;
    int y;
} Point;

typedef struct Poly {
    int count;
    Point ** points;
} Poly;


/*
 * Initialize new point
 * @return Point
 */
Point * point_create (int x, int y)
{
    Point * p = malloc (1 * sizeof(* p));
    p->x = x;
    p->y = y;
    return p;
}

/*
 * Create new shape pointer
 * @return Poly
 */
Poly * shape_create ()
{
    Poly * shape = malloc(1 * sizeof(* shape));
    shape->count = 0;
    return shape;
}

/*
 * Add point into shape
 * @return void
 */
void shape_pointer_add (Poly * shape, Point * point)
{
    shape->count++;

    Point ** cache = realloc(shape->points, (shape->count * sizeof(Point *)));

    if (cache != NULL) {
        shape->points = cache;
        shape->points[shape->count - 1] = point;
    }
}

/*
 * Get distance zwischen 2 Points
 * @return double
 */
double point_distance (Point * p1, Point * p2)
{
    printf("%d, %d, %d, %d\n", p1->x, p2->x, p1->y, p2->y);

    return sqrt(pow( (p1->x - p2->x), 2) + pow( (p1->y - p2->y), 2));
}

/*
 * Calculate perimeter
 * @return double
 */
double shape_perimeter (Poly * shape)
{
    int i, p;
    for (i=1, p=0; i < shape->count; i++) {
        p += point_distance(shape->points[i-1], shape->points[i]);
    }
    return p;
}



int main (int argc, char *argv[])
{
    Poly * shape = shape_create ();


    shape_pointer_add(shape, point_create(0,0));
    shape_pointer_add(shape, point_create(0,1));
    shape_pointer_add(shape, point_create(0,2));
    shape_pointer_add(shape, point_create(0,3));
    shape_pointer_add(shape, point_create(3,0));
    shape_pointer_add(shape, point_create(3,1));
    shape_pointer_add(shape, point_create(3,2));
    shape_pointer_add(shape, point_create(3,3));
    shape_pointer_add(shape, point_create(0,3));
    shape_pointer_add(shape, point_create(1,3));
    shape_pointer_add(shape, point_create(2,3));
    shape_pointer_add(shape, point_create(3,3));


    printf("%f\n", shape_perimeter(shape));

    free(shape);

    return EXIT_SUCCESS;
}





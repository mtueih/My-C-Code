#include <stdio.h>
#include <math.h>

#define PI (4.0 * atan(1.0))
#define ANGLE_TO_RADIAN(X) ((X) * (PI / 180.0))

struct PolarCoordinates {
    float length;
    float angle;
};

struct CartesianCoordinates {
    float x;
    float y;
};

struct CartesianCoordinates polarToCartesian(struct PolarCoordinates polar_coordinates);

int main(void) {
    struct PolarCoordinates polar_coordinates_0;
    struct CartesianCoordinates cartesian_coordinates_0;


    printf("请输入极坐标的长度：");
    scanf("%f", &polar_coordinates_0.length);

    printf("请输入极坐标的角度值：");
    scanf("%f", &polar_coordinates_0.angle);

    cartesian_coordinates_0 = polarToCartesian(polar_coordinates_0);

    printf("对应的直角坐标：(%f, %f)\n", cartesian_coordinates_0.x, cartesian_coordinates_0.y);

    return 0;
}

struct CartesianCoordinates polarToCartesian(struct PolarCoordinates polar_coordinates) {
    struct CartesianCoordinates cartsian_coordinates;

    cartsian_coordinates.x = polar_coordinates.length * cos(ANGLE_TO_RADIAN(polar_coordinates.angle));
    cartsian_coordinates.y = polar_coordinates.length * sin(ANGLE_TO_RADIAN(polar_coordinates.angle));

    return cartsian_coordinates;
}
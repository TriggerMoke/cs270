// P1 Assignment
// Author: Aidan Michalos
// Date:   8/29/2022
// Class:  CS270
// Email:  aidanmih@colostate.edu

// Include files
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// example of a global array
double input[5], output[4];
double PI = 3.141593;

// this function can be used as a guide for the funtions you will implement
/*
void computeCircle(double radius, double *addressOfArea)
{
    // Compute area
    double result = 3.141593 * radius * radius;

    // Dereference pointer to return result
    *addressOfArea = result;
}*/

void computeSphere(double radius, double *out){
    double result = (4.0 / 3.0) * PI * radius * radius * radius;
    *out = result;
}
void computeCube(double side, double *out){
    double result = side * side * side;
    *out = result;
}
void computeTetrahedron(double side, double *out){
    double result = 0.117851 * side * side * side;
    *out = result;
}
void fun3(double inc, double *ouput){}
void computeCylinder(double radius, double height, double *out){
    double result = PI * radius * radius * height;
    *out = result;
}

int main(int argc, char *argv[])
{
    // Check number of arguments
    if (argc != 6) {
        printf("usage: ./P1 <double> <double> <double> <double> <double>\n");
        return EXIT_FAILURE;
    }

    // Parse arguments
    for(int i = 0; i < 5; i++)
    {
        input[i] = atof(argv[i+1]);
    }

    // Call function
    //computeCircle(radius, &area);
    computeSphere(input[0], &output[0]);
    computeCube(input[1], &output[1]);
    computeTetrahedron(input[2], &output[2]);
    computeCylinder(input[3], input[4], &output[3]);

    // Print area
    //printf("The area of a circle with radius %.5f equals %.5f.\n", radius, area);
    printf("SPHERE, radius = %.5f, volume = %.5f.\n", input[0], output[0]);
    printf("CUBE, side = %.5f, volume = %.5f.\n", input[1], output[1]);
    printf("TETRAHEDRON, side = %.5f, volume = %.5f.\n", input[2], output[2]);
    printf("CYLINDER, radius = %.5f, height = %.5f, volume = %.5f.\n", input[3], input[4], output[3]);

    // Return success
    return EXIT_SUCCESS;
}
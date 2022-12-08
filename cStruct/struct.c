/* CS270 
 *
 * Author: Your name here
 * Date:   2/12/2020
 */

#include "struct.h"
#include<stdio.h>
#include <stdlib.h>

/********** FUNCTION DEFINITIONS **********************************************/

void readStudentAndEnroll(Student **slot)
{
    //something calloc
    Student* temp = (Student*)calloc(1, sizeof(Student));
    scanf("%s", temp->firstName);
    scanf("%f", &temp->qualityPoints);
    scanf("%d", &temp->numCredits);
    *slot = temp;
}

void displayStudent(Student s)
{
    float gpa = s.qualityPoints / s.numCredits;
    printf("%s, %.2f\n", s.firstName, gpa);
}

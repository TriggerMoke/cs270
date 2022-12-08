 /** @mainpage 
   *  \htmlinclude "STRUCTS.html"
   */
/* CS270 
 *
 * Author: Your name here
 * Date:   2/12/2020
 */
#include<stdio.h>
#include <stdlib.h>
#include "struct.h"

int main(int argc, const char **argv)
{
  // TODO: Complete the main function
    int tempNumStud = 0;
    scanf("%d", &tempNumStud);
    ClassRoster roster;
    roster.numStudents = tempNumStud;
    roster.students = (Student**)calloc(tempNumStud, sizeof(Student*));

    for(int i = 0; i < tempNumStud; i++){
      readStudentAndEnroll(&roster.students[i]);
    }
    for(int i = 0; i <tempNumStud; i++){
      displayStudent(*roster.students[i]);
      free(roster.students[i]);
    }
    free(roster.students);

  return 0;
}

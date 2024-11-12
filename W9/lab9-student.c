/*
Author: Jack Dixon
Description: Takes input of student information and stores in a struct.
Stores only the first two students, before expanding with realloc if necessary.
Stores all remaining students before printing all student information.
Date: 11-11-2024
*/

// Included Libraries
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Type Declarations
typedef struct Student Student;

// Structure Declarations
struct Student
{
    char name[21];
    char programme[21];
    float grade;
};

// Function Prototypes
void grabStudents(Student *students, char *argv[], int length, int pos, int stuPos);
Student *expandStudents(Student *students, int lenStudents, int argc);
void printStudents(Student *students, int length);

// Main program
int main(int argc, char *argv[])
{
    Student *students = (Student *)malloc(2 * sizeof(Student));
    grabStudents(students, argv, 7, 1, 0);

    students = expandStudents(students, 2, argc - 1);

    grabStudents(students, argv, argc-1, 7, 2);

    printStudents(students, (argc / 3));

    free(students);
    
    return 0;
}

// Function for assigning all variables to struct array from argv
void grabStudents(Student *students, char *argv[], int length, int pos, int stuPos)
{
    // Initialise pointer to assign values
    Student *pStudent;

    // i iterates (on +3) through argv
    // j iterates through students
    for (int i = pos, j = stuPos; i < length; i += 3, j++)
    {
        pStudent = &students[j];
        strcpy(pStudent->name, argv[i]);
        strcpy(pStudent->programme, argv[i+1]);
        pStudent->grade = atof(argv[i+2]);
    }
    return;
}

// Reallocates memory for the students array of a new size
// Returns pointer to new memory location of students
Student *expandStudents(Student *students, int lenStudents, int argc)
{
    if (lenStudents < (argc / 3))
    {
        students = (Student *)realloc(students,(argc / 3) * sizeof(Student));
        return students;
    } else
    {
        printf("MEMORY RE-ALLOC FAILED");
        return students;
    }
    
}

// Prints all student information
void printStudents(Student *students, int length)
{
    Student *pStudent;

    for (int i = 0; i < length; i++)
    {
        pStudent = &students[i];
        printf("%s, ", pStudent->name);
        printf("%s, ", pStudent->programme);
        printf("%.2f\n", pStudent->grade);
    }
    return;
}

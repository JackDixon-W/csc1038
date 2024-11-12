/*
Author: Jack Dixon
Description: Takes an input of student information, finds the average grade of all students.
Then prints all CSCE students with an above average grade.
Date: 12-11-2024
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
float averageGrade(Student *students, int length);
void printBestCSCEStudents(Student *students, int length, float grade);

// Main program
int main(int argc, char *argv[])
{
    int length = (argc / 3);
    Student *students = (Student *)malloc(length * sizeof(Student));
    grabStudents(students, argv, argc-1, 1, 0);

    float avgGrade = averageGrade(students, length);
    printBestCSCEStudents(students, length, avgGrade);
    printf("Average grade: %.2f\n", avgGrade);

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

// Finds average grade of all students as a float
float averageGrade(Student *students, int length)
{
    Student *pStudent;
    float avg = 0;
    for (int i = 0; i < length; i++)
    {
        pStudent = &students[i];
        avg += pStudent->grade;
    }
    return avg / length;
}

// Prints all CSCE students with a grade above the input grade
void printBestCSCEStudents(Student *students, int length, float grade)
{
    Student *pStudent;

    for (int i = 0; i < length; i++)
    {
        pStudent = &students[i];
        // If the student isn't in CSCE or has a below average grade, skip
        if (strcmp(pStudent->programme, "CSCE") || pStudent->grade < grade)
        {
            continue;
        }
        printf("%s, ", pStudent->name);
        printf("%.2f\n", pStudent->grade);
    }
    return;
}

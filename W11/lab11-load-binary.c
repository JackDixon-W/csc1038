/*
Author: Jack Dixon
Description: Reads student details from binary file and assigns to struct.
Then, prints this struct's details with formatting and labelling.
Date: 21-11-24
*/

// Included Libraries
#include <stdlib.h>
#include <stdio.h>

// Type Declarations
typedef struct Student Student;

// Structure Declarations
struct Student
{
    char name[50];
    char college[20];
    int age;
    float grade;
};

// Function Prototypes
Student grabFile(FILE *pFile);
void printStudent(Student *cur);

// Main program
int main(int argc, char *argv[])
{
    // Declare file details
    FILE *pFile = NULL;
    char *filename = "studentBinary.bin";
    pFile = fopen(filename, "rb");

    // Check if file read was successful
    if (!pFile)
    {
        printf("Error opening %s\tProgram terminating\n", filename);
        exit(-1);
    }

    Student curStudent = grabFile(pFile);
    Student *pStudent = &curStudent;
    printStudent(pStudent);

    fclose(pFile);

    return 0;
}

// Grabs student details from pFile and returns the details as a struct
Student grabFile(FILE *pFile)
{
    Student cur;
    int tempLen;
    // Grab name
    fread(&tempLen, sizeof(int), 1, pFile);
    fread(cur.name, sizeof(char), tempLen, pFile);

    // Grab college
    fread(&tempLen, sizeof(int), 1, pFile);
    fread(cur.college, sizeof(char), tempLen, pFile);

    // Grab age
    fread(&cur.age, sizeof(int), 1, pFile);
    
    // Grab grade
    fread(&cur.grade, sizeof(float), 1, pFile);

    return cur;
}

// Prints all details of the student passed in
void printStudent(Student *cur)
{
    printf("Name: %s\n", cur->name);
    printf("College: %s\n", cur->college);
    printf("Age: %d\n", cur->age);
    printf("Grade: %.2f\n", cur->grade);
}

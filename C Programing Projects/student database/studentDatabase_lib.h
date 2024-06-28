/*
Lab 12 - Problem 1: Student Database Management System
Driver: Manish Choudhary (mc4323)
Navigator: Munendra choudhary (mp2893)
*/

#ifndef STUDENTDATABASE_LIB_H
#define STUDENTDATABASE_LIB_H

#include <stdio.h>
#include <stdlib.h>

// Global constants
#define MAX_COURSES 3 // Maximum number of courses
#define MAX_SIZE 100 // Maximum size of student database

// Enum for student grades
typedef enum {
    GRADE_A = 'A',
    GRADE_B = 'B',
    GRADE_C = 'C',
    GRADE_D = 'D',
    GRADE_F = 'F'
} grade;

// Enum for courses
typedef enum {
    MATH,
    PHYSICS,
    BIOLOGY
} course;

// Struct for report
typedef struct {
    course enrolledCourse;
    grade courseGrade;
} report;

// Struct for student
typedef struct {
    int ID;
    char name[MAX_SIZE];
    int courseCount;
    report transcript[MAX_COURSES];
} student;

// Function prototypes
void addStudent(student* studentDatabase, int* count);
void displayAllStudents(student* studentDatabase, int count);

#endif /* STUDENTDATABASE_LIB_H */

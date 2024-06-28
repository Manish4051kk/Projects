/*
Lab 12 - Problem 1: Student Database Management System
Driver: Manish Choudhary (mc4323)
Navigator: Munendra choudhary (mp2893)
*/

#include "studentDatabase_lib.h"

/**
 * Name: addStudent
 * Process: Adds a new student to the student database.
 * Function input/parameters:
 *     studentDatabase - Pointer to the array of student structures representing the database
 *     count - Pointer to an integer representing the current count of students in the database
 * Function output/parameters: None
 * Function output/returned: None
 * Dependencies: studentDatabase_lib.h for struct student definition and MAX_COURSES constant
 **/
void addStudent(student* studentDatabase, int* count) {
    // Declare a variable of type struct student
    student curStudent;

    // Request user input for student's name
    printf("Input student ID: ");
    scanf("%d", &curStudent.ID);
    printf("Input student name: ");
    scanf("%s", curStudent.name);
    printf("Input total number of courses: ");
    scanf("%d", &curStudent.courseCount);

    // Validate the total number of courses
    while (curStudent.courseCount <= 0 || curStudent.courseCount > MAX_COURSES) {
        printf("Invalid input. Total number of courses should be between 1 and %d.\n", MAX_COURSES);
        printf("Input total number of courses: ");
        scanf("%d", &curStudent.courseCount);
    }

    // Input enrolled courses and grades
    for (int i = 0; i < curStudent.courseCount; i++) {
        printf("Input %d for Maths, %d for Physics and %d for Biology: ", MATH, PHYSICS, BIOLOGY);
        int courseChoice;
        scanf("%d", &courseChoice);

        while (courseChoice < MATH || courseChoice > BIOLOGY) {
            printf("Invalid input. Please input %d for Maths, %d for Physics, or %d for Biology: ", MATH, PHYSICS, BIOLOGY);
            scanf("%d", &courseChoice);
        }

        curStudent.transcript[i].enrolledCourse = courseChoice;

        printf("Input grade for the enrolled course (A, B, C, D, F): ");
        char gradeChoice;
        scanf(" %c", &gradeChoice);

        while (gradeChoice != GRADE_A && gradeChoice != GRADE_B && gradeChoice != GRADE_C && gradeChoice != GRADE_D && gradeChoice != GRADE_F) {
            printf("Invalid input. Please input a valid grade (A, B, C, D, F): ");
            scanf(" %c", &gradeChoice);
        }

        curStudent.transcript[i].courseGrade = gradeChoice;
    }

    // Update student record in the database
    studentDatabase[*count] = curStudent;
    (*count)++;
}

/**
 * Name: displayAllStudents
 * Process: Displays the transcript of all students stored in the database.
 * Function input/parameters:
 *     studentDatabase - Pointer to the array of student structures representing the database
 *     count - Integer representing the current count of students in the database
 * Function output/parameters: None
 * Function output/returned: None
 * Dependencies: studentDatabase_lib.h for struct student definition and constants like MATH, PHYSICS, BIOLOGY, GRADE_A, GRADE_B, etc.
 **/

void displayAllStudents(student* studentDatabase, int count) {
    // Print a header indicating that the transcript of all students is being displayed.
    printf("\nTranscript of all students:\n");
    
    printf("----------------------------------------------\n");
    
    // Loop through each student in the database.
    for (int i = 0; i < count; i++) {
        // Print the name and ID of the current student.
        printf("Student name: %s\t  Student ID: %d\n", studentDatabase[i].name, studentDatabase[i].ID);
        
        printf("----------------------------------------------\n");
        
        // Loop through each course in the current student's transcript.
        for (int j = 0; j < studentDatabase[i].courseCount; j++) {
            // Switch statement to handle different course types and print corresponding grades.
            switch (studentDatabase[i].transcript[j].enrolledCourse) {
                case MATH:
                    printf("Maths: %c\n", studentDatabase[i].transcript[j].courseGrade);
                    break;
                case PHYSICS:
                    printf("Physics: %c\n", studentDatabase[i].transcript[j].courseGrade);
                    break;
                case BIOLOGY:
                    printf("Biology: %c\n", studentDatabase[i].transcript[j].courseGrade);
                    break;
            }
        }
        
        printf("----------------------------------------------\n");
    }
}

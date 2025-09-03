#ifndef CORE_H
#define CORE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Forward declarations
typedef struct student Student;
typedef struct course Course;
typedef struct grade Grade;
typedef struct University_system System;

// main structure
typedef struct University_system {
    Student* head_student;
    Course* head_course;
}System;

// structure for any course
typedef struct course {
    int course_code;
    char* course_name;
    int enrollment_count;
    Student** students_list;
    Course* next;
    double (*statistics)(System* heads, int course_code);
}Course;

// structure for each grade
typedef struct grade {
    char* course_name;
    double grade;
}Grade;

// sturcture for each student
typedef struct student {
    int id;
    char* name;
    Student* next;
    Grade* student_grades;
    int num_of_courses;
}Student;


// student.c functions declarations
Student* admit_student(int id, char* name, System* heads);

Student* check_student(System* heads, int ID);

void traverse_students(System* heads);

int add_grade(int ID, int course_code, double grade, System* heads);

double get_grade(int ID, int course_code, System* heads);

double get_grade_simple(const Student* ptr_student, char* coursename);

void add_student_to_list(System* heads, Student* new_student);

int get_grade_student(int ID, System* heads);

// course.c functions declarations
Course* create_course(int code, char* coursename, System* heads);

Course* check_course(System* heads, int course_code);

void traverse_courses(System* heads);

int enroll_student(int course_code, int student_ID, System* heads);

void Print_students_grades(System* heads, int course_code);

void add_course_to_list(System* heads, Course* new_course);

// cleanup.c functiosn declarations
void cleanup(System* heads);

void cleanup_all_students(Student* head);

void cleanup_student(Student* student);

void cleanup_all_courses(Course* head);

void cleanup_course(Course* course);

// stats.c functions declarations
double calculate_average(System* heads, int course_code);

double calculate_median(System* heads, int course_code);

// sort.c functions declarations
int compare_by_grade(const void *ptr1, const void *ptr2);

void sort_students_by_grade(System* heads, int course_code);

#endif




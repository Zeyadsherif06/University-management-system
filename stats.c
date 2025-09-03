#include "core.h"

// calculating the mean
double calculate_average(System* heads, int course_code) {
    Course* ptr_course = check_course(heads, course_code);
    if(ptr_course == NULL) {
        printf("the course with the following code: %d doesn't exist\n", course_code);
        return -1.0;
    }
    int enrollments = ptr_course->enrollment_count;
    if(enrollments == 0) {
        printf("There are no students with grades in this course\n");
        return -1.0;
    }
    double total_grades = 0.0;
    for(int i = 0; i < enrollments; i++) {
        Student* ptr_student = ptr_course->students_list[i];
        int student_courses = ptr_student->num_of_courses;
        for(int j = 0; j < student_courses; j++) {
                if(strcmp(ptr_student->student_grades[j].course_name, ptr_course->course_name) == 0) {
                double student_grade = ptr_student->student_grades[j].grade;
                total_grades += student_grade;
                break;
            }
        }
    }
    double average = (double) total_grades / enrollments;
    printf("the mean for the course: %s is %.2lf\n", ptr_course->course_name, average);
    return average;
}

// calculating the median
double calculate_median(System* heads, int course_code) {
    Course* ptr_course = check_course(heads, course_code);
    if(ptr_course == NULL) {
        printf("the course with the following code: %d doesn't exist\n", course_code);
        return -1.0;
    }
    sort_students_by_grade(heads, course_code);
    int enrollments = ptr_course->enrollment_count;
    if(enrollments == 0) {
        printf("There are no students with grades in this course\n");
        return -1.0;
    }
    double total = 0.0;
    if(enrollments % 2 == 0){
        int half = enrollments / 2;
        for(int i = half; i <= half + 1; i++) {
           total += get_grade_simple(ptr_course->students_list[i], ptr_course->course_name);
        }
        double median = (double) total / 2;
        printf("the median for this course is: %.2lf\n", median);
        return median;
    }
    else {
        int median_index = ceil(enrollments / 2);
        double median = get_grade_simple(ptr_course->students_list[median_index], ptr_course->course_name);
        printf("the median for this course is: %.2lf\n", median);
        return median;
    }
}



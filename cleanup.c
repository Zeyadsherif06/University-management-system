#include "core.h"

// the main cleanup function (to be used in the main function)
void cleanup(System* heads) {
    Student* student_head = heads->head_student;
    Course* course_head = heads->head_course;
    cleanup_all_students(student_head);
    cleanup_all_courses(course_head);
}

void cleanup_all_students(Student* head) {
    Student* student_head = head;
    Student* next_student;
    while(student_head != NULL){
        next_student = student_head->next;
        cleanup_student(student_head);
        student_head = next_student;
    }
}

void cleanup_all_courses(Course* head) {
    Course* course_head = head;
    Course* next_course;
    while(course_head != NULL){
        next_course = course_head->next;
        cleanup_course(course_head);
        course_head = next_course;
    }
}

void cleanup_student(Student* student) {
    free(student->name);
    int size = student->num_of_courses;
    for(int i = 0; i < size; i++) {
        free(student->student_grades[i].course_name);
    }
    free(student->student_grades);

}

void cleanup_course(Course* course) {
    free(course->course_name);
    free(course->students_list);

}
#include "core.h"

// create a new course on the system
Course* create_course(int code, char* coursename, System* heads) {
   Course* ptr_course = (Course*)malloc(sizeof(Course));
   if(ptr_course == NULL) {
    fprintf(stderr, "failed memory allocation for the new course\n");
    exit(EXIT_FAILURE);
   } 
   ptr_course->course_code = code;
   ptr_course->course_name = strdup(coursename);
    if(ptr_course->course_name == NULL) {
        fprintf(stderr, "failed memory allocation for the course name\n");
        exit(EXIT_FAILURE);
   } 
   ptr_course->enrollment_count = 0;
   ptr_course->next = NULL;
   ptr_course->students_list = NULL; 
   add_course_to_list(heads, ptr_course);
   printf("The course: %s was created successfully\n", coursename);
   return ptr_course;
}

void add_course_to_list(System* heads, Course* new_course) {
    if (heads->head_course == NULL) {
        heads->head_course = new_course;
        return;
    }
    Course* current = heads->head_course;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_course;
}

// check if a course exist on the list
Course* check_course(System* heads, int course_code) {
    Course* head = heads->head_course;
    while(head != NULL){
        if(head->course_code == course_code) {
            return head;
        }
        head = head->next;
    }
    printf("the course with the following code: %d doesn't exist\n", course_code);
    return NULL;
}

// print the list of courses
void traverse_courses(System* heads) {
    Course* head = heads->head_course;
    while(head != NULL){
        printf("Course name: %s - Course code: %d\n",head->course_name, head->course_code);
        head = head->next;
    }
}

// enroll a student in a course
int enroll_student(int course_code, int student_ID, System* heads) {
    Student* student_head = heads->head_student;
    Student* ptr_student = check_student(heads, student_ID);
    Course* course_head = heads->head_course;
    Course* ptr_course = check_course(heads, course_code);
    int num_courses = ptr_student->num_of_courses;
    for(int i = 0; i < num_courses; i++) {
        if(strcmp(ptr_student->student_grades[i].course_name, ptr_course->course_name) == 0) {
            printf("Student already enrolled in this course");
            exit(EXIT_FAILURE);
        }
    }
    if(ptr_student != NULL && ptr_course != NULL){
        // changes on the course struct
        ptr_course->enrollment_count += 1;
        int new_count = ptr_course->enrollment_count;
        ptr_course->students_list = (Student**)realloc(ptr_course->students_list , new_count*sizeof(Student*));
        if(ptr_course->students_list == NULL){
            ptr_course->enrollment_count -= 1;
            fprintf(stderr, "Failed memory reallocation\n");
            exit(EXIT_FAILURE);
        }
        ptr_course->students_list[new_count-1] = ptr_student;
        // changes on the student struct
        ptr_student->num_of_courses += 1;
        printf("the student: %s is now enrolled in the course: %s", ptr_student->name, ptr_course->course_name);
        return 1;
    }   
    return 0;
}

// print the grades of the students inside a course
void Print_students_grades(System* heads, int course_code) {
    Course* ptr_course = check_course(heads, course_code);
    if(ptr_course == NULL){
        exit(EXIT_FAILURE);
    }
    int enrollments = ptr_course->enrollment_count;
    for(int i = 0; i < enrollments; i++) {
        Student* ptr_student = ptr_course->students_list[i];
        int student_courses = ptr_student->num_of_courses;
        for(int j = 0; j < student_courses; j++) {
            if(strcmp(ptr_student->student_grades[j].course_name, ptr_course->course_name) == 0) {
                double student_grade = ptr_student->student_grades[j].grade;
                printf("the grade of the student: %s in the course: %s is %.2lf\n", ptr_student->name, ptr_course->course_name, ptr_student->student_grades[j].grade);
                break;
            }
        }
    }
}

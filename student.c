#include "core.h"

// add students to the university system
Student* admit_student(int id, char* name, System* heads) {
    while(heads->head_student != NULL) {
        if(heads->head_student->id == id) {
            printf("a student with the same ID already exist please try again with a different ID\n");
            return NULL;
        }
    }
    Student* ptr_student = (Student*)malloc(sizeof(Student));
    if(ptr_student == NULL) {
        fprintf(stderr, "Failed memory allocation\n");
        exit(EXIT_FAILURE);
    }
    ptr_student->id = id;
    ptr_student->name = strdup(name);
    if(ptr_student->name == NULL) {
        fprintf(stderr, "Failed memory allocation\n");
        exit(EXIT_FAILURE);
    }
    ptr_student->next = NULL;
    ptr_student->student_grades = NULL;
    ptr_student->num_of_courses = 0;
    add_student_to_list(heads, ptr_student);
    printf("Student was created successfully\n");
    return ptr_student;
}

void add_student_to_list(System* heads, Student* new_student) {
    if (heads->head_student == NULL) {
        heads->head_student = new_student;
        return;
    }
    Student* current = heads->head_student;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_student;
}

// chech if the student exist on the list
Student* check_student(System* heads, int ID) {
    Student* head = heads->head_student;
    while(head != NULL){
        if(head->id == ID ) {
            printf("The student exist on the list\n");
            return head;
        }
        head = head->next; 
    }
        printf("The student with ID: %d doesn't exist\n", ID);
        return NULL;
}

// print the students and their IDs
void traverse_students(System* heads) {
    Student* head = heads->head_student;
    if (head == NULL) {
        printf("Please add students there are no students yet\n");
        return;
    }
    while(head != NULL){
        printf("The student with the following name: %s has the ID: %d.\n",head->name , head->id);
        head = head->next;
    }
}

// add a grade to a student
int add_grade(int ID, int course_code, double grade, System* heads) {
    if(grade > 100 || grade < 0) {
        printf("Please enter grade between 0 and 100 and try again\n");
        return -1;
    }
    Student* ptr_student = check_student(heads, ID);
    Course* ptr_course = check_course(heads, course_code);
    if(ptr_student != NULL && ptr_course != NULL) {
        Grade student_grade;
        student_grade.course_name = strdup(ptr_course->course_name);
        if(student_grade.course_name == NULL){
            fprintf(stderr, "strdup function failled, the string wasn't copied\n");
            exit(EXIT_FAILURE);
        }
        student_grade.grade = grade;
        ptr_student->num_of_courses += 1;
        int count = ptr_student->num_of_courses;
        ptr_student->student_grades = realloc(ptr_student->student_grades, count * sizeof(Grade));
        if(ptr_student->student_grades == NULL){
            ptr_student->num_of_courses -= 1;
            fprintf(stderr, "failed memory reallocation\n");
            exit(EXIT_FAILURE);
        }
        ptr_student->student_grades[count-1] = student_grade;
        return 1;
    }
    return 0;
}

// get grade of one student and print it
double get_grade(int ID, int course_code, System* heads) {
    Student* ptr_student = check_student(heads, ID);
    Course* ptr_course = check_course(heads, course_code);
    if(ptr_student != NULL && ptr_course != NULL) {
        int courses = ptr_student->num_of_courses;
        for(int i = 0; i < courses; i++) {
            if(strcmp(ptr_student->student_grades[i].course_name, ptr_course->course_name) == 0) {
                printf("the grade of the student: %s in the course: %s is %.2lf\n", ptr_student->name, ptr_course->course_name, ptr_student->student_grades[i].grade);
                return ptr_student->student_grades[i].grade;
            }
        }
    }
    printf("Grade not found, please add a grade and try again\n");
    return -1.0;
}

// get all the grade of a specific student
int get_grade_student(int ID, System* heads) {
    Student* ptr_student = check_student(heads, ID);
    if(ptr_student != NULL) {
        int courses = ptr_student->num_of_courses;
        if(courses == 0) {
            printf("The student doesn't have any grades\n");
            return -1;
        }
        for(int i = 0; i < courses; i++) {
            printf("the grade of the student: %s in the course: %s is %.2lf\n", ptr_student->name, ptr_student->student_grades[i].course_name, ptr_student->student_grades[i].grade);
        }
        return 1;
    }
    printf("The student doesn't exist");
    return -1;
}

// a simple version of the previous function to be used in other functions
double get_grade_simple(const Student* ptr_student, char* coursename) {
    int courses = ptr_student->num_of_courses;
    for(int i = 0; i < courses; i++) {
        if(strcmp(coursename, ptr_student->student_grades[i].course_name) == 0){
            return ptr_student->student_grades[i].grade;
        }
    }
    return -1.0;
}

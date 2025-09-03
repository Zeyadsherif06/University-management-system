#include "core.h"

// a helping struct for sorting
typedef struct {
    char* coursename;
}sort_helper;

static sort_helper s_help;

// the main function to sort students by grade
void sort_students_by_grade(System* heads, int course_code) {
    Course* ptr_course = check_course(heads, course_code);
    if(ptr_course == NULL) {
        printf("the course with the following code: %d doesn't exist\n", course_code);
        return;
    }
    s_help.coursename = ptr_course->course_name;
    qsort(ptr_course->students_list, (size_t) ptr_course->enrollment_count, sizeof(Student*), compare_by_grade);
}

// the helping function that tell qsort how to work
int compare_by_grade(const void *ptr1, const void *ptr2) {
    const Student* student1 = *(const Student**)ptr1;
    const Student* student2 = *(const Student**)ptr2;

    double grade1 = get_grade_simple(student1, s_help.coursename);
    double grade2 = get_grade_simple(student2, s_help.coursename);

    if(grade1 > grade2) return 1;
    if (grade1 < grade2) return -1;
    return 0;
}
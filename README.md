# Student-Course Management System

This project implements a modular **Student-Course Management System** in C. It provides functionality for managing students, courses, enrollment, grades, and statistical analysis, while ensuring proper memory management and extensibility.

The system is organized into separate source files for clarity and maintainability:

* **student.c** – Student-related operations
* **course.c** – Course-related operations
* **cleanup.c** – Memory cleanup and resource management
* **stats.c** – Statistical calculations on grades
* **sort.c** – Sorting utilities

---

## 📌 Function Reference

### **student.c**

* `Student* admit_student(int id, char* name, System* heads);`
  Adds a new student to the system.

* `Student* check_student(System* heads, int ID);`
  Check if the student already exist.

* `void traverse_students(System* heads);`
  Iterates through and displays all students.

* `int add_grade(int ID, int course_code, double grade, System* heads);`
  Assigns a grade to a student for a specific course.

* `double get_grade(int ID, int course_code, System* heads);`
  Retrieves a student’s grade for a course.

* `double get_grade_simple(const Student* ptr_student, char* coursename);`
  Retrieves a grade directly by course name from a student record.

* `void add_student_to_list(System* heads, Student* new_student);`
  Appends a student to the student list.

* `void get_grade_student(int ID, System* heads);`
  Displays all grades for a given student.

---

### **course.c**

* `Course* create_course(int code, char* coursename, System* heads);`
  Creates and registers a new course.

* `Course* check_course(System* heads, int course_code);`
  Check if the course already exist.

* `void traverse_courses(System* heads);`
  Iterates through and displays all courses.

* `int enroll_student(int course_code, int student_ID, System* heads);`
  Enrolls a student into a course.

* `void Print_students_grades(System* heads, int course_code);`
  Displays all students and their grades for a course.

* `void add_course_to_list(System* heads, Course* new_course);`
  Appends a course to the course list.

---

### **cleanup.c**

* `void cleanup(System* heads);`
  Frees all system resources (students and courses).

* `void cleanup_all_students(Student* head);`
  Frees memory allocated for the student list.

* `void cleanup_student(Student* student);`
  Frees memory allocated for a single student.

* `void cleanup_all_courses(Course* head);`
  Frees memory allocated for the course list.

* `void cleanup_course(Course* course);`
  Frees memory allocated for a single course.

---

### **stats.c**

* `double calculate_average(System* heads, int course_code);`
  Computes the average grade for a course.

* `double calculate_median(System* heads, int course_code);`
  Computes the median grade for a course.

---

### **sort.c**

* `int compare_by_grade(const void *ptr1, const void *ptr2);`
  Comparison function for grade-based sorting.

* `void sort_students_by_grade(System* heads, int course_code);`
  Sorts students enrolled in a course by their grades.

---

## ⚙️ System Design Overview

* **Data Structures**: Students and courses are implemented as linked lists, supporting dynamic additions and removals.
* **Enrollment**: Students can be enrolled in multiple courses, with grades tracked per course.
* **Statistics**: Provides average and median grade computations.
* **Sorting**: Supports sorting enrolled students by their grades.
* **Memory Management**: Dedicated cleanup functions ensure no memory leaks occur.

---

## 🚀 Compilation & Execution

```bash
gcc student.c course.c cleanup.c stats.c sort.c main.c -o system
./system
```

---

## 📖 Example Workflow

1. **Admit a Student** using `admit_student`.
2. **Create a Course** using `create_course`.
3. **Enroll a Student** into the course with `enroll_student`.
4. **Assign Grades** using `add_grade`.
5. **Retrieve and Display Grades** with `get_grade` or `Print_students_grades`.
6. **Analyze Performance** using `calculate_average` and `calculate_median`.
7. **Sort Students** by grade with `sort_students_by_grade`.
8. **Clean Up Memory** before program termination with `cleanup`.

---

## ✅ Key Features

* Modular architecture with clear separation of concerns.
* Dynamic student and course management.
* Statistical tools for grade analysis.
* Safe memory management with cleanup utilities.



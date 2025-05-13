// Learning C++ 
// Challenge 04_05
// Calculate a GPA, by Eduardo Corpeño 

#include <iostream>
#include <vector>
#include "records.h"

int main(){
    float GPA = 0.0f;
    int id;
    
    std::vector<Student> students = {Student(1, "George P. Burdell"),
                                    Student(2, "Nancy Rhodes")};

    std::vector<Course> courses = {Course(1, "Algebra", 5),
                                Course(2, "Physics", 4),
                                Course(3, "English", 3),
                                Course(4, "Economics", 4)};

    std::vector<Grade> grades = {Grade(1, 1, 'B'), Grade(1, 2, 'A'), Grade(1, 3, 'C'),
                                Grade(2, 1, 'A'), Grade(2, 2, 'A'), Grade(2, 4, 'B')};


    // Calculate the GPA for the selected student.
    bool valid_student = false;
    Student *selected_student;
    do {
        std::cout << "Enter a student ID: " << std::flush;
        std::cin >> id;
        
        for (auto student : students) {
            if (id == student.get_id()) {
                selected_student = new Student(student.get_id(), student.get_name());
                valid_student = true;
                break;
            }
        }

        if (!valid_student) {
            std::cout << "Not a valid student ID. Try again." << std::endl;
        }
    } while (!valid_student);

    float total_points = 0.0f;
    float total_credits = 0.0f;
    auto student_id = selected_student->get_id();
    for (auto grade : grades) {
        if (grade.get_student_id() == student_id) {
            for (auto course : courses) {
                if (course.get_id() == grade.get_course_id()) {
                    float points;
                    switch (grade.get_grade()) {
                        case 'A':
                            points = 4.0f;
                            break;
                        case 'B':
                            points = 3.0f;
                            break;
                        case 'C':
                            points = 2.0f;
                            break;
                        case 'D':
                            points = 1.0f;
                            break;
                        default:
                            points = 0.0f;
                            break;
                    }
                    total_points += course.get_credits() * points;
                    total_credits += course.get_credits();
                    break;
                }
            }
        }
    }

    GPA = total_points / total_credits;

    std::string student_str;
    student_str = selected_student->get_name(); // Change this to the selected student's name

    std::cout << "The GPA for " << student_str << " is " << GPA << std::endl;
    
    std::cout << std::endl << std::endl;
    return (0);
}

#include <iostream>
#include "01_student.h"

int main() {
    Person p{"Professor Rice"};
    std::cout << p.to_string() << std::endl;
    Student s{"Encyclopedia Brown", 4.0};
    std::cout << s.to_string() << std::endl;
}

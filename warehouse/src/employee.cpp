#include "include/employee.hpp"
#include <iostream>


// Employee constructor
Employee::Employee(std::string name, bool forkliftCertificate) : name(name), forkliftCertificate(forkliftCertificate) {}


// Employee functions
std::string Employee::getName() {
    return name;
}

bool Employee::getBusy() {
    return busy;
}

void Employee::setBusy(bool busy) {
    this->busy = busy;
}

bool Employee::getForkliftCertificate() {
    return forkliftCertificate;
}

void Employee::setForkliftCertificate(bool forkliftCertificate) {
    this->forkliftCertificate = forkliftCertificate;
}

std::ostream &operator<<(std::ostream& os, Employee& e) {
    os << "(Name: " << e.name << ", Forklift Certificate: " << std::boolalpha << e.forkliftCertificate << ", Busy: " << std::boolalpha << e.busy << ")";
    return os;
}

#pragma once
#include <string>


class Employee {

    private:

        // Employee variables
        const std::string name;
        bool busy;
        bool forkliftCertificate;

    public:

        // Employee constructor
        Employee(std::string name, bool forkliftCertificate);
        
        // Employee functions
        std::string getName();
        bool getBusy();
        void setBusy(bool busy);
        bool getForkliftCertificate();
        void setForkliftCertificate(bool forkliftCertificate);
        
};
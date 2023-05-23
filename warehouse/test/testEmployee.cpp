#include "include/catch.hpp"
#include "../src/include/employee.hpp"


TEST_CASE("Test if constructor Employe", "constructor Employee") {
    Employee e("Avina", true);
    REQUIRE(e.getName() == "Avina");
    REQUIRE(e.getForkliftCertificate() == true);
}

TEST_CASE("Test if getName returns Avina", "getName()") {
    Employee e("Avina", true);
    REQUIRE(e.getName() == "Avina");
}

TEST_CASE("Test if setBusy works, getBusy returns true", "setBusy(), getBusy()") {
    Employee e("Avina", true);
    e.setBusy(true);
    REQUIRE(e.getBusy() == true);
}

TEST_CASE("Test if getForkliftCertificate returns true", "getForkliftCertificate()") {
    Employee e("Avina", true);
    REQUIRE(e.getForkliftCertificate() == true);
}

TEST_CASE("Test if setForkliftCertificate works", "setForkliftCertificate()") {
    Employee e("Avina", true);
    e.setForkliftCertificate(false);
    REQUIRE(e.getForkliftCertificate() == false);
}

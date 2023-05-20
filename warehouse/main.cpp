#include <iostream>
#include "src/include/employee.hpp"
#include "src/include/pallet.hpp"
#include "src/include/warehouse.hpp"
#include "src/include/shelf.hpp"


int main(void){
    std::cout << "Hello world" << std::endl;

    Warehouse w;

    Shelf s;

    for (size_t i = 0; i < s.pallets.size(); i++) {

        std::cout << s.pallets[i].getItemName() << "lol" << std::endl;

    }

    Employee e("Yunus", true);
    std::cout << e.getName() << std::endl;

    Pallet p;
    std::cout << p.getItemCount() << std::endl;

}

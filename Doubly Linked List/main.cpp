#include <iostream>
#include "list.h"

int main(){
    List list;
    bool rc = false;

    rc = list.insert_entry( "name_01", 1, 'M' );
    std::cout << "rc: " << rc << std::endl;

    rc = list.insert_entry( "name_02", 2, 'F' );
    std::cout << "rc: " << rc << std::endl;

    rc = list.insert_entry( "name_03", 3, 'M' );
    std::cout << "rc: " << rc << std::endl;

    rc = list.insert_entry( "name_04", 4, 'F' );
    std::cout << "rc: " << rc << std::endl;

    list.list_entries();

    rc = list.delete_entry( "name_01" );
    rc = list.delete_entry( "name_02" );
    rc = list.change_entry( "name_03", "NEW_name", 99, 'X' );

    std::cout << "rc: " << rc << std::endl;

    list.list_entries();

    list.list_inverted_entries();

    std::cout << std::endl;

    return 0;
}
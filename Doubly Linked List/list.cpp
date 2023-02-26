#include <iostream>
#include "list.h"
// ------------------------------------------------------------
List::List(){
    this->first_entry = NULL;
    this->last_entry = NULL;
}
// ------------------------------------------------------------
List::~List(){

}
// ------------------------------------------------------------
bool List::insert_entry( char * p_name, int p_age, char p_sex){
    struct _data * data;

    if ( !this->first_entry ){
        data = new struct _data;

        if ( !data ){
            return false;
        }

        data->name = p_name;
        data->age = p_age;
        data->sex = p_sex;
        data->prev = NULL;
        data->next = NULL;

        this->first_entry = data;
        this->last_entry = data;
        return true;
    }

    data = new struct _data;

    if ( !data ){
        return false;
    }

    last_entry->next = data;

    data->name = p_name;
    data->age = p_age;
    data->sex = p_sex;
    data->prev = this->last_entry;
    data->next = NULL;

    this->last_entry = data;
    return true;
}
// ------------------------------------------------------------
void List::list_entries( void ){
    struct _data * current_entry = this->first_entry;
    std::cout << "-----------------------------------" << std::endl;

    while( current_entry ){
        std::cout << current_entry->name << " "
                  << current_entry->age << " "
                  << current_entry->sex << std::endl;

        current_entry = current_entry->next;
    }
}
// ------------------------------------------------------------
void List::list_inverted_entries( void ){
    struct _data * current_entry = this->last_entry;
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "--- Inverted Listing ---" << std::endl;

    while( current_entry ){
        std::cout << current_entry->name << " "
                  << current_entry->age << " "
                  << current_entry->sex << std::endl;

        current_entry = current_entry->prev;
    }
}
// ------------------------------------------------------------
bool List::delete_entry( char * p_name ){
    if ( !p_name ){
        return false;
    }

    struct _data * current_entry = this->first_entry;

    while( current_entry ){
        if ( current_entry->name == p_name ){
            std::cout << "------ found and deleted --------" << std::endl;
            std::cout << current_entry->name << " "
                      << current_entry->age << " "
                      << current_entry->sex << std::endl;

            if ( current_entry->prev == NULL ){
                struct _data * next = current_entry->next;
                next->prev = NULL;
                this->first_entry = next;
                delete current_entry;
                return true;
            }

            struct _data * prev = current_entry->prev;
            struct _data * next = current_entry->next;
            prev->next = next;
            next->prev = prev;
            delete current_entry;

            return true;
        }
        current_entry = current_entry->next;
    }

    return false;
}
// ------------------------------------------------------------
bool List::change_entry(char * p_search, char * p_name, int p_age, char p_sex){
    struct _data * current_entry = this->first_entry;

    while( current_entry ){
        if ( current_entry->name == p_search ){
            current_entry->name = p_name;
            current_entry->age = p_age;
            current_entry->sex = p_sex;
            return true;
        }

        current_entry = current_entry->next;
    }

    return false;
}
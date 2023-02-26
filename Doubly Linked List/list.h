#ifndef LIST_H
#define LIST_H

#include <string>

class List{
    public:
        List();
        ~List();
        bool insert_entry( char *, int, char );
        void list_entries( void );
        void list_inverted_entries( void );
        bool delete_entry( char * );
        bool change_entry( char *, char *, int, char );

    private:
        struct _data{
            std::string name;
            int age;
            char sex;
            struct _data * prev;
            struct _data * next;
        };

        struct _data * first_entry;
        struct _data * last_entry;

};

#endif
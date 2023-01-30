#include <person_class.h>
#include <string>

Person::Person():id(0),age(0),lastname(""),firstname(""),password(""),isLoggedIn(false){};
void Person::printData(){
    std::cout<<"Id:"<<this->id<<"\n";
    std::cout<<"Age:"<<this->age<<"\n";
    std::cout<<"Firstname:"<<this->firstname<<"\n";
    std::cout<<"Lastname:"<<this->lastname<<"\n";
    std::cout<<"Password:"<<this->password<<"\n";
};

Person::~Person(){}
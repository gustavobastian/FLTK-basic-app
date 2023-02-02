#include <person_class.h>
#include <string>
#include <vector>
#include <sstream>

Person::Person():id(0),lastname(""),firstname(""),password(""),isLoggedIn(false){};

void Person::printData(){
    
    try {
    std::cout<<"Id:"<<this->id<<"\n";    
    
    
    
    std::cout<<"Firstname:"<<this->firstname<<"\n";
    
    
    std::cout<<"Lastname:"<<this->lastname<<"\n";

    std::cout<<"Username:"<<this->username<<"\n";
    
    
    std::cout<<"Password:"<<this->password<<"\n";
    }
    catch (const std::exception& e){
        std::cout<<e.what()<<std::endl;
    }
    
};

Person::Person(const std::string *a){

    std::string localString = (*a);
    for(unsigned int i =0;i<localString.size();i++){
        if(localString.at(i)== 0xA){
            localString.at(i) = 0x20;
        }
    }
    std::cout<<"Value:"<<localString<<std::endl;  
    std::vector<std::string> personValues;
    std::istringstream ss(localString);
    std::string token;
    while (std::getline(ss, token,',')){
        personValues.push_back(token);
    };
    
    for (auto it = personValues.begin();it != personValues.end();++it){
        std::cout<<"Value:"<<*it<<std::endl;
    }
    
    if(personValues.size()<6){
        this->id=0;
        this->firstname="";
        this->lastname="";
        this->mode="";
        this->username="";
        this->password="";
    }
    else{
    this->id=stoi(personValues.at(0));
    this->firstname=personValues.at(1);
    this->lastname=personValues.at(2);
    this->mode=personValues.at(3);
    this->username=personValues.at(4);
    this->password=personValues.at(5);
    }

}

Person::~Person(){}
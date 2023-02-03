#ifndef PERSON_CLASS_H_
#define PERSON_CLASS_H_


#include <string>
#include <iostream>

/**
 * @file person_class.h
 * @author Gustavo Bastian (bastian.gustavo@gmail.com)
 * @brief class that is used to retrieve/alter/create persons in the users table of the database
 * @version 0.1
 * @date 2023-01-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */


/**
 * @brief class representing the user
 * 
 */


class Person{
    private:
        int id;        
        std::string firstname;
        std::string lastname;
        std::string password;
        std::string username;
        std::string mode;
        bool isLoggedIn;
    public:
        Person();
        Person(const std::string *a);
        Person(int x, const std::string& a ,
        const std::string& n,const std::string& f ,
        const std::string& e,const std::string& s ):id(x),firstname(a),lastname(n),password(f),isLoggedIn(false),
        username(e),mode(s) {};

        /**
         * @brief Set the First Name object
         * 
         * @param nameP 
         */
        void setFirstName(std::string nameP){firstname=nameP;return;};
        /**
         * @brief Set the Last Name object
         * 
         * @param nameP 
         */
        void setLastName(std::string nameP){lastname=nameP;return;};
        /**
         * @brief Set the Password object
         * 
         * @param passP 
         */
        void setPassword(std::string passP){password=passP;return;};
        
        /**
         * @brief Set the Mode object
         * 
         * @param _mode 
         */
        void setMode(std::string _mode){mode=_mode;};
        /**
         * @brief Set the Username object
         * 
         * @param _username 
         */
        void setUsername(std::string _username){username=_username;};
        
        void setId(int idP){id=idP;return;};

        /**
         * @brief Get the First Name object
         * 
         * @return std::string 
         */

        std::string getFirstName(){return firstname;};
        /**
         * @brief Get the Last Name object
         * 
         * @return std::string 
         */
        std::string getLastName(){return lastname;};
        /**
         * @brief Get the Password object
         * 
         * @return std::string 
         */
        std::string getPassword(){return password;};
        /**
         * @brief Get the Mode object
         * 
         * @return std::string 
         */
        std::string getMode(){return mode;};
        /**
         * @brief Get the Username object
         * 
         * @return std::string 
         */
        std::string getUsername(){return username;};
        
        /**
         * @brief Get the Id object
         * 
         * @return int 
         */
        int getId(){return id;};

        /**
         * @brief Set the Logged In object
         * 
         */
        void setLoggedIn(){this->isLoggedIn=true;return;};
        /**
         * @brief Set the Logged Out object
         * 
         */
        void setLoggedOut(){this->isLoggedIn=false;return;};

        /**
         * @brief Get the Logged In object
         * 
         * @return true 
         * @return false 
         */
        bool getLoggedIn(){return this->isLoggedIn;};

        /**
         * @brief print class information in console 
         * 
         */
        void printData();

        /**
         * @brief set all the properties of the person as default
         * 
         */
        void clearData();

        /**
         * @brief generate string object in order to insert the person in the database
         * 
         * @return std::string objet to pass as parameter to the databaseService function
         */
        std::string generateStringDB();

        int setData(const std::string *a);

        ~Person();
};

#endif  // PERSON_CLASS_H_

#ifndef DATABASESERVICE_H
#define DATABASESERVICE_H

/**
 * @file databaseService.h
 * @author Gustavo Bastian (bastian.gustavo@gmail.com)
 * @brief Interface class that connects the application to a sqlite3 database
 * @version 0.1
 * @date 2023-01-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */



#include <sqlite3.h>
#include <string>
#include <person_class.h>
/**
 * @brief class used to communicate to de sqlite database
 * 
 */
class databaseService {
    private:
    std::string address;
    sqlite3 *db;
    int rc;

    public:
    databaseService(std::string addressP);
    
    int openDB();

    int createTable(std::string tableName);
    int insertElementTable(std::string Element, std::string tableName);
    std::string getElement(std::string tableName, std::string elementTag, std::string elementValue);
    std::string getAllElement();
    ~databaseService();

    //login services
    bool validateUser(std::string username, std::string password);

};
#endif // !1
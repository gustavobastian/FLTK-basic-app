#include <databaseService.h>
#include <sqlite3.h>
#include <iostream>
#include <sstream>
#include <string>

/**
 * @brief Construct a new database Service::database Service object
 * 
 * @param addressP string address of the database
 */
databaseService::databaseService(std::string addressP){
    this->address=addressP; 
    return;
}

/**
 * @brief This function open the database
 * 
 * @return int 0 if ok, -1 if error
 */
int databaseService::openDB(){
    this->rc = sqlite3_open("../data/generalDB", &(this->db));    
    if (this->rc) {
        std::cout << "Error opening database: " << sqlite3_errmsg(db) << std::endl;
        return -1;
    }
    else
    {
        return 0;
    }

}

int databaseService::createTable(std::string tableName){
      // create a table
    std::string sql = "CREATE TABLE IF NOT EXISTS person (id INTEGER PRIMARY KEY, name TEXT, age INTEGER);";
    rc = sqlite3_exec(db, 
    "CREATE TABLE IF NOT EXISTS person (id INTEGER PRIMARY KEY, name TEXT, age INTEGER);"
    , NULL, 0, NULL);

    if (rc != SQLITE_OK) {
        std::cout  << "Error creating table: " << sqlite3_errmsg(db) << std::endl;
        return -1;
    }
    return 0;
};

int databaseService::insertElementTable(std::string Element,std::string tableName){
    std::string sql = "INSERT INTO person VALUES(1, 'John Doe', 30);";
    this->rc = sqlite3_exec(this->db, sql.c_str(), NULL, 0, NULL);

    if (rc != SQLITE_OK) {
        std::cout << "Error inserting data: " << sqlite3_errmsg(db) << std::endl;
        return -1;
    }

    return 0;
};

std::string databaseService::getElement(std::string tableName, std::string elementTag, std::string elementValue){
    
    std::string sql = "SELECT name, age FROM person WHERE id = 1;";
    sqlite3_stmt *stmt;
    rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL);

    if (rc != SQLITE_OK) {
        std::cout << "Error querying table: " << sqlite3_errmsg(db) << std::endl;
        return "Error querying table: ";
    }

    rc = sqlite3_step(stmt);

    if (rc == SQLITE_ROW) {
        std::string name = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 0));
        int age = sqlite3_column_int(stmt, 1);
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }

    sqlite3_finalize(stmt);

    return "nothing";
};

std::string databaseService::getAllElement(){    
    std::stringstream ss;


    std::string output;
    std::string sql = "SELECT name, age FROM person WHERE id = 1;";
    sqlite3_stmt *stmt;
    rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL);

    if (rc != SQLITE_OK) {
        std::cout << "Error querying table: " << sqlite3_errmsg(db) << std::endl;
        //return -1;
        return "Error querying table: ";
    }

    rc = sqlite3_step(stmt);

    if (rc == SQLITE_ROW) {
        std::string name = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 0));
        int age = sqlite3_column_int(stmt, 1);
        //std::cout << "Name: " << name << ", Age: " << age << std::endl;
        ss<< "Name: " << name << ", Age: " << age << std::endl;
        output=ss.str();
    }

    sqlite3_finalize(stmt);

    return output;
};

/**
 * @brief contrast with database and validates the user login
 * 
 * @param username 
 * @param password 
 * @return true if it is a valid user
 * @return false if the pass or the user do not match
 */
bool databaseService::validateUser(std::string username, std::string password)
{
    bool state=false;
    if((username.size() ==0)||(password.size()==0)){
        return false;
    }
    else{
        std::string sql = "SELECT username,password FROM users WHERE password ="+password+";";
        
        sqlite3_stmt *stmt;
        rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL);        
        
        if (rc != SQLITE_OK) {
            std::cout << "Error querying table: " << sqlite3_errmsg(db) << std::endl;            
            return false;
        }

        rc = sqlite3_step(stmt);        

        if (rc == SQLITE_ROW) {
            std::string name = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 0));                        
            if(name.compare(username)==0)
            {
                state=true;
            }        
        }        
        sqlite3_finalize(stmt);
        if(state==false){
            return false;
            }
        else{    
            return true;
            }        
    }
};
 
databaseService::~databaseService(){
    sqlite3_close(this->db);
}
    
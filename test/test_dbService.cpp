#include <gtest/gtest.h>
#include <databaseService.h>
#include <string>
#include <map>
#include <iostream>
#include <vector>

using namespace std;

TEST(DBCREATION, TABLECREATION){
    std::string  data("../../data/generalDB.db");
    auto *myDb= new databaseService(data);
   

    myDb->openDB();

    auto output = myDb->createTable("myTable");
    
    EXPECT_EQ(output,0);

    delete myDb;
 }

 TEST(DBCREATION, TABLECREATION_COLUMNS){
    std::string  data("../../data/generalDB.db");
    auto *myDb= new databaseService(data);
    myDb->openDB();

    std::vector <std::string> columns;
    std::vector <std::string> columns2;

    columns.push_back("id INTEGER PRIMARY KEY");
    columns.push_back("firstname TEXT");
    columns.push_back("lastname TEXT");
    columns.push_back("age INTEGER");

    auto output = myDb->createTable("myTable",columns);    
    EXPECT_EQ(output,0);

    auto output1 = myDb->createTable("",columns);    
    EXPECT_EQ(output1,-1);

    auto output2 = myDb->createTable("MyTable",columns2);    
    EXPECT_EQ(output2,-1);

    auto output3 = myDb->dropTable("myTable");
    EXPECT_EQ(output3,0);
    
    vector<std::string>().swap(columns);

    delete myDb;
 }

TEST(DBCREATION, TABLEDROP){
    std::string  data("../../data/generalDB.db");
    auto *myDb= new databaseService(data);
    myDb->openDB();

    std::vector <std::string> columns;
    

    columns.push_back("id INTEGER PRIMARY KEY");
    columns.push_back("firstname TEXT");
    columns.push_back("lastname TEXT");
    columns.push_back("age INTEGER");

    auto output = myDb->createTable("myTable",columns);    
    EXPECT_EQ(output,0);

    auto output2 = myDb->dropTable("myTable");
    EXPECT_EQ(output2,0);

    vector<std::string>().swap(columns);
    delete myDb;
 } 

 TEST(DBINSERTION, INSERTELEMENT){
    std::string  data("../../data/generalDB.db");
    auto *myDb= new databaseService(data);
    myDb->openDB();

    std::vector <std::string> columns;
    
    //table for test
    columns.push_back("id INTEGER PRIMARY KEY");
    columns.push_back("firstname TEXT");
    columns.push_back("lastname TEXT");
    columns.push_back("age INTEGER");

    //element for test
    std::string value= "1, 'Pedro','Perez',20 ";
    std::string returnValue= "1,Pedro,Perez,20,;";
    //creation
    auto output = myDb->createTable("myTable",columns);    
    EXPECT_EQ(output,0);
    
    //test

    auto output1 = myDb->insertElementTable(value,"myTable");
    EXPECT_EQ(output1,0);

    auto output2 = myDb->findElement("myTable","id","1");
    
    EXPECT_EQ(output2,returnValue);

    //cleaning
    auto output3 = myDb->dropTable("myTable");
    EXPECT_EQ(output3,0);

    vector<std::string>().swap(columns);
    delete myDb;
 } 



 TEST(DBINSERTION, RETRIEVE_MULTIPLE_ELEMENTS){
    std::string  data("../../data/generalDB.db");
    auto *myDb= new databaseService(data);
    myDb->openDB();

    std::vector <std::string> columns;
    
    //table for test
    columns.push_back("id INTEGER PRIMARY KEY");
    columns.push_back("firstname TEXT");
    columns.push_back("lastname TEXT");
    columns.push_back("age INTEGER");

    //element for test
    std::string value= "1, 'Pedro','Perez',20 ";
    std::string value_2= "2, 'Juan','Perez',22 ";
    //creation
    auto output = myDb->createTable("myTable",columns);    
    EXPECT_EQ(output,0);
    
    //test

    auto output1 = myDb->insertElementTable(value,"myTable");
    EXPECT_EQ(output1,0);
    auto output2 = myDb->insertElementTable(value_2,"myTable");
    EXPECT_EQ(output2,0);

    auto output3 = myDb->getAllElement("myTable",3);
    

    //cleaning
    auto output4 = myDb->dropTable("myTable");
    EXPECT_EQ(output4,0);

    vector<std::string>().swap(columns);
    delete myDb;
 } 


 TEST(DBINSERTION, ALTERING){
    std::string  data("../../data/generalDB.db");
    auto *myDb= new databaseService(data);
    myDb->openDB();

    std::vector <std::string> columns;
    
    //table for test
    columns.push_back("id INTEGER PRIMARY KEY");
    columns.push_back("firstname TEXT");
    columns.push_back("lastname TEXT");
    columns.push_back("age INTEGER");

    //element for test
    std::string value= "1, 'Pedro','Perez',20 ";    

    std::string newValues= "firstname='Pedro2', lastname='Perez2', age=20 ";    
    std::string returnValue= "1,Pedro2,Perez2,20,;";  
    int index=1;
    //creation
    auto output = myDb->createTable("myTable",columns);    
    EXPECT_EQ(output,0);
    
    //test

    auto output1 = myDb->insertElementTable(value,"myTable");
    auto output2 = myDb->updateElementTable(newValues,"myTable",index);
    EXPECT_EQ(output2,0);
    auto output3 = myDb->findElement("myTable","id","1");
    
    EXPECT_EQ(output3,returnValue);

    
    

    //cleaning
    auto output4 = myDb->dropTable("myTable");
    EXPECT_EQ(output4,0);

    vector<std::string>().swap(columns);
    delete myDb;
 } 






int main(int argc, char **argv) {

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
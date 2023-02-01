#include<gtest/gtest.h>
#include<databaseService.h>
#include <string>
#include<iostream>
#include<vector>

using namespace std;

TEST(DBCREATION, TABLECREATION){
    std::string  data("myDB");
    auto *myDb= new databaseService(data);
    myDb->openDB();

    auto output = myDb->createTable("myTable");
    
    EXPECT_EQ(output,0);
 }

 TEST(DBCREATION, TABLECREATION_COLUMNS){
    std::string  data("myDB");
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
 }

TEST(DBCREATION, TABLEDROP){
    std::string  data("myDB");
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
 } 

int main(int argc, char **argv) {

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
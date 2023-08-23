#include<gtest/gtest.h>
#include<gmock/gmock.h>
#include<person_class.h>
#include <string>
#include <vector>
#include<iostream>

using namespace std;
using ::testing::AtLeast;
using ::testing::Return ;
using ::testing::_;


class DataBaseConnect{
public:
    virtual bool login(string username, string password){return true;};
    virtual bool logout(string username, string password){return true;};
    virtual int fetchRecord(){return -1;}
};


class MockDB : public DataBaseConnect{
public:
    MOCK_METHOD0(fetchRecord,int());
    MOCK_METHOD1(logout,bool (string username));
    MOCK_METHOD2(login,bool (string username,string password));

};

class myDb{
    DataBaseConnect &dbC;
public:
    myDb(DataBaseConnect & _dbC): dbC(_dbC){}
    int Init(string username, string password){
        if(dbC.login(username, password)!=true)
        {
            if(dbC.login(username, password)!=true)
            {
                cout<<"Login failed 2nd time"<<endl; 
                return -1;
            }
        }
        else {
            cout<<"Login success"<<endl; 
            return 1;
            }
            return 0;
    };
    
    ~myDb(){};
};

TEST(DBClassTest, Login){
    //prepare
    MockDB mdb;
    myDb db(mdb);
    EXPECT_CALL(mdb,login("term","hello"))
    .Times(1)
    .WillOnce(Return(true));
    //act
    int retValue = db.Init("term","hello");
    //test
    EXPECT_EQ(retValue,1);
}

TEST(DBClassTest, LoginFailure){
    //prepare
    MockDB mdb;
    myDb db(mdb);
    EXPECT_CALL(mdb,login(_,_))
    .Times(2)
    .WillRepeatedly(Return(false));
    //act
    int retValue = db.Init("term","hello");
    //test
    EXPECT_EQ(retValue,-1);
}
int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
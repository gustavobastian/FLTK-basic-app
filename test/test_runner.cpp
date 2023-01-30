#include<gtest/gtest.h>
#include<person_class.h>
#include <string>
#include<iostream>

using namespace std;

TEST(PersonClassTest, METHODS_TEST){
    
    const std::string firstName="jhon";
    const std::string lastName="jhonP";
    const std::string password="jhonPP";
    const std::string mode="administrador";
    const std::string username="myUser";

    Person *testPerson=new Person(1,21,firstName,lastName,password,username,mode);
    
    
    testPerson->setAge(13);
    auto result= testPerson->getAge();    
    auto ID= testPerson->getId();    
    auto name= testPerson->getFirstName();
    auto lastname= testPerson->getLastName();
    auto pass= testPerson->getPassword();
    auto user= testPerson->getUsername();
    auto modeTest= testPerson->getMode();

    delete testPerson;
    EXPECT_EQ(result, 13);
    EXPECT_STREQ(lastName.c_str(), lastname.c_str());
    EXPECT_STREQ(name.c_str(), firstName.c_str());
    EXPECT_STREQ(pass.c_str(), password.c_str());
    EXPECT_STREQ(username.c_str(), user.c_str());
    EXPECT_STREQ(mode.c_str(), modeTest.c_str());
    EXPECT_EQ(ID, 1);

}

TEST(PersonClassTest, INITIAL_STATE_NOT_LOGGED){

      const std::string firstName="jhon";
    const std::string lastName="jhonP";
    const std::string password="jhonPP";
    const std::string mode="administrador";
    const std::string username="myUser";

    Person *testPerson=new Person(1,21,firstName,lastName,password,username,mode);

    bool state= testPerson->getLoggedIn();
    EXPECT_EQ(state, false);
    
    delete testPerson;
}

TEST(PersonClassTest, LOGGING_IN_TEST){
    bool state(false);
    const std::string firstName="jhon";
    const std::string lastName="jhonP";
    const std::string password="jhonPP";
    const std::string mode="administrador";
    const std::string username="myUser";

    Person *testPerson=new Person(1,21,firstName,lastName,password,username,mode);
    testPerson->setLoggedIn();
    state= testPerson->getLoggedIn();
    EXPECT_EQ(state, true);
    

    delete testPerson;
}
TEST(PersonClassTest, LOGGING_OUT_TEST){
    bool state(false);
    const std::string firstName="jhon";
    const std::string lastName="jhonP";
    const std::string password="jhonPP";
    const std::string mode="administrador";
    const std::string username="myUser";

    Person *testPerson=new Person(1,21,firstName,lastName,password,username,mode);
    testPerson->setLoggedIn();    
    testPerson->setLoggedOut();
    state= testPerson->getLoggedIn();
    EXPECT_EQ(state, false);
    

    delete testPerson;    
}
int main(int argc, char **argv) {

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#include <iostream>
#include <sstream>
#include <FL/fl_ask.H>
#include <person_class.h>
#include <users_window.h>
#include <databaseService.h>

/*
constructors for the page
*/
users_Window::users_Window(int x, int y):Fl_Group(10,35,x-10,y-35,"Users")
{
    this->value=0;
    this->localDB=NULL;
    
    this->color(FL_DARK_YELLOW);
    this->selection_color(FL_DARK_YELLOW );

    labelId = new Fl_Box(50,125,150,25,"Id:");
    idInput = new Fl_Int_Input( 50,160,150,25);    

    search = new Fl_Button( 250,160,90,25,"Search"); 
    search->color(FL_DARK_CYAN);                
           
    this->end();
}
/**
 * @brief Construct a new users Window::users Window object
 * 
 * @param w 
 * @param h 
 * @param data 
 * @param localDB 
 * @param state 
 */
users_Window::users_Window(int w, int h, int data, databaseService *localDB, bool *state):Fl_Group(10,35,w-10,h-35,"Users")
{
    this->set_authorization(state);
    
    this->localUser= new Person();

    if(localDB == NULL){
        std::cerr<<"no database!\n";
        return;
    }
    else{
        this->localDB = localDB;
    }

    this->value=data;
    this->color(FL_DARK_YELLOW);
    this->selection_color(FL_DARK_YELLOW );
    
    /*Id input
    */
    labelId = new Fl_Box(40,140,25,25,"Id:");
    idInput = new Fl_Int_Input( 100,140,150,25);

    /*last Name input
    */
    labelLastName = new Fl_Box(40,175,25,25,"LastName:");
    labelLastName->hide();
    lastNameInput = new Fl_Input( 100,175,150,25);
    lastNameInput->callback(this->update_lastName_cb,(void*)this);
    lastNameInput->hide();
    /*first Name input
    */
    labelFirstName = new Fl_Box(40,210,25,25,"FirstName:");
    labelFirstName->hide();    
    firstNameInput = new Fl_Input( 100,210,150,25);
    firstNameInput->callback(this->update_firstName_cb,(void*)this);
    firstNameInput->hide();
        
    /*password
    */
    labelPassword = new Fl_Box(40,245,25,25,"Password:");
    labelPassword->hide();
    passwordInput = new Fl_Input( 100,245,150,25);
    passwordInput->callback(this->update_pass_cb,(void*)this);    
    passwordInput->hide();
    
    /*Mode
    */
    labelMode = new Fl_Box(40,280,25,25,"Mode:");
    labelMode->hide();
    modeInput = new Fl_Input( 100,280,150,25);
    modeInput->callback(this->update_mode_cb,(void*)this);
    modeInput->hide();
    


    /*username
    */
    labelUsername = new Fl_Box(40,315,25,25,"Username:");
    labelUsername->hide();
    usernameInput = new Fl_Input( 100,315,150,25);
    usernameInput->callback(this->update_username_cb,(void*)this);
    usernameInput->hide();
    

    /*Search button
    */
    search = new Fl_Button( w-125,160,90,25,"Search"); 
    search->color(FL_DARK_CYAN);  
    search->callback(this->search_cb,(void*)(this));                          

    /*Create button
    */
    create = new Fl_Button( w-125,200,90,25,"Create");  
    create->color(FL_DARK_CYAN);  
    create->callback(this->create_cb,(void*)(this));                          
    /*Update button
    */
    update = new Fl_Button( w-125,240,90,25,"Update");  
    update->color(FL_DARK_CYAN);  
    update->callback(this->update_cb,(void*)(this));                          
    

    quit = new Fl_Button( w-125,280,90,25,"Quit");  
    quit->color(FL_DARK_CYAN);  
    quit->callback(this->quit_cb,(void*)(this));                          
    quit->hide();



    send = new Fl_Button( w-125,315,90,25,"Send");  
    send->color(FL_DARK_CYAN);  
    send->callback(this->send_cb,(void*)(this));                          
    send->hide();

    


    this->end();
}
/**
 * @brief binds the object state to external state
 * 
 * @param _state 
 */
void users_Window::set_authorization(bool *_state)
{ 
    this->authorization = _state;
    if (*(this->get_authorization())==true){
         std::cout<<"true\n";
         } 
    else {
         std::cout<<"false\n";
    }
        
}
/**
 * @brief 
 * 
 * @return unsigned int 
 */
unsigned int users_Window::get_value() {
    return this->value;
}

/**
 * @brief set local value for the user window
 * 
 * @param valueP 
 * @return int 
 */
int users_Window::set_value(unsigned int valueP) {
    this->value=valueP;
    return 1;    
}
/**
 * @brief callback for looking for a user
 * 
 * @param w pointer to button
 * @param data pointer to parent window
 */
void users_Window::search_cb(Fl_Widget* w,void* data){  
    users_Window *myWindow = (users_Window*)data;          
    myWindow->modeUpdate=true;

    if(*(myWindow->get_authorization())==false){
        std::cout<<"Needs login..."<<std::endl;
        fl_alert("Not Logged!, needs login...");        
        return;
    }
 
 
    std::stringstream ss;
    ss<<myWindow->idInput->value();
    std::string localId=ss.str();

    const std::string myUser=myWindow->localDB->findElement("users","id",localId);
    
    if(myWindow->localUser->setData(&myUser)!=0){
        std::cerr<<"error setting data"<<std::endl;
    };
   
    const char *one=(myWindow->localUser->getFirstName()).c_str();
    myWindow->firstNameInput->value(one);
    
    const char *two=(myWindow->localUser->getLastName()).c_str();
    myWindow->lastNameInput->value(two);

    const char *three=(myWindow->localUser->getPassword()).c_str();
    myWindow->passwordInput->value(three);

    const char *four=(myWindow->localUser->getUsername()).c_str();
    myWindow->usernameInput->value(four);

    const char *five=(myWindow->localUser->getMode()).c_str();
    myWindow->modeInput->value(five);
    

    myWindow->idInput->deactivate();
    myWindow->labelFirstName->show();
    myWindow->firstNameInput->show();
    myWindow->labelLastName->show();
    myWindow->lastNameInput->show();
    myWindow->labelPassword->show();
    myWindow->passwordInput->show();
    myWindow->labelMode->show();
    myWindow->modeInput->show();
    myWindow->labelUsername->show();
    myWindow->usernameInput->show();
    
    myWindow->search->hide();
    myWindow->create->hide();
    myWindow->update->hide();
    myWindow->quit->show();
    myWindow->send->show();
    
    
    myWindow->redraw();
}

/**
 * @brief callback function for the create button
 * 
 * @param w pointer to the button
 * @param data pointer to the parent window
 */

void users_Window::create_cb(Fl_Widget* w,void* data){  
    users_Window *myWindow = (users_Window*)data;  
    std::stringstream ss;        
    
    myWindow->modeUpdate=false;

    myWindow->localUser->clearData();
    if(*(myWindow->get_authorization())==false){
        std::cout<<"Needs login..."<<std::endl;
        fl_alert("Not Logged!, needs login...");        
        return;
    } 
    
    std::cout<<"creating...."<<std::endl;

    long newIndex = (myWindow->localDB->getLastIndex("users"))+1;
    ss<<newIndex;
    std::string temp=ss.str();
    const char *one=(const char*)temp.c_str();
    myWindow->idInput->value(one);
    myWindow->idInput->deactivate();
    myWindow->labelFirstName->show();
    myWindow->firstNameInput->show();
    myWindow->labelLastName->show();
    myWindow->lastNameInput->show();
    myWindow->labelPassword->show();
    myWindow->passwordInput->show();
    myWindow->labelMode->show();
    myWindow->modeInput->show();
    myWindow->labelUsername->show();
    myWindow->usernameInput->show();
    
    myWindow->search->hide();
    myWindow->create->hide();
    myWindow->update->hide();
    myWindow->quit->show();
    myWindow->send->show();
    
    myWindow->redraw();
    
}

/**
 * @brief callback function for the update button
 * 
 * @param w pointer to the button
 * @param data pointer to the window
 */
void users_Window::update_cb(Fl_Widget* w,void* data){  
    users_Window *myWindow = (users_Window*)data;          
    
    if(*(myWindow->get_authorization())==false){
        std::cout<<"Needs login..."<<std::endl;
        fl_alert("Not Logged!, needs login...");        
        return;
    } 
    std::string dataDB=myWindow->localUser->generateStringDB();
    
}

/**
 * @brief callback function for the quit button, erases the current person and hide send button
 * 
 * @param w 
 * @param data 
 */

void users_Window::quit_cb(Fl_Widget* w,void* data){  
    users_Window *myWindow = (users_Window*)data;          

    if(*(myWindow->get_authorization())==false){
        std::cout<<"first needs login..."<<std::endl;
        fl_alert("Not Logged!, needs login...");        
        return;
    } 
    myWindow->modeUpdate=false;
    std::cout<<"quitting...."<<std::endl;
    myWindow->localUser->clearData();

    const char *one="";
    

    myWindow->firstNameInput->value(one);
    myWindow->lastNameInput->value(one);
    myWindow->passwordInput->value(one);
    myWindow->usernameInput->value(one);
    myWindow->modeInput->value(one);

    myWindow->idInput->activate();
    
    myWindow->labelFirstName->hide();
    myWindow->firstNameInput->hide();
    myWindow->labelLastName->hide();
    myWindow->lastNameInput->hide();
    myWindow->labelPassword->hide();
    myWindow->passwordInput->hide();
    myWindow->labelMode->hide();
    myWindow->modeInput->hide();
    myWindow->labelUsername->hide();
    myWindow->usernameInput->hide();
    
    myWindow->search->show();
    myWindow->create->show();
    myWindow->update->show();
    myWindow->quit->hide();
    myWindow->send->hide();
    myWindow->redraw();
    
}


/**
 * @brief callback that update the password object when the widget is modified
 * 
 * @param w pointer to the input
 * @param data pointer to the window
 */
void users_Window::update_pass_cb(Fl_Widget* w,void* data){        
    users_Window *myWindow = (users_Window*)data;
    Fl_Input *input=(Fl_Input*)(w);
    myWindow->localUser->setPassword(input->value());    
    return;
}
/**
 * @brief function that update the first name when the widget is modified
 * 
 * @param w pointer to the widget
 * @param data pointer to the window
 */
void users_Window::update_firstName_cb(Fl_Widget* w,void* data){        
    users_Window *myWindow = (users_Window*)data;
    
    Fl_Input *input=(Fl_Input*)(w);
    myWindow->localUser->setFirstName(input->value());    
    return;
}
/**
 * @brief function that update the last name when the widget is modified
 * 
 * @param w pointer to the widget
 * @param data pointer to the window
 */
void users_Window::update_lastName_cb(Fl_Widget* w,void* data){        
    users_Window *myWindow = (users_Window*)data;
    Fl_Input *input=(Fl_Input*)(w);
    myWindow->localUser->setLastName(input->value());    
    return;
}
/**
 * @brief function that update the mode when the widget is modified
 * 
 * @param w pointer to the widget modified 
 * @param data pointer to the window
 */
void users_Window::update_mode_cb(Fl_Widget* w,void* data){        
    users_Window *myWindow = (users_Window*)data;
    Fl_Input *input=(Fl_Input*)(w);
    myWindow->localUser->setMode(input->value());    
    return;
}

/**
 * @brief function that update the username when the widget is modified
 * 
 * @param w pointer to the widget
 * @param data pointer to the window
 */
void users_Window::update_username_cb(Fl_Widget* w,void* data){        
    users_Window *myWindow = (users_Window*)data;
    Fl_Input *input=(Fl_Input*)(w);
    myWindow->localUser->setUsername(input->value());    
    return;
}

/**
 * @brief callback to the send button. Check if the user is logged then submit the data to the database.
 * 
 * @param w pointer to the widget
 * @param data pointer to the window
 */

void users_Window::send_cb(Fl_Widget* w,void* data){  
    users_Window *myWindow = (users_Window*)data;     
    if(*(myWindow->get_authorization())==false){
        std::cout<<"first needs login..."<<std::endl;
        fl_alert("Not Logged!, first needs login...");        
        return;
    } 

    myWindow->localUser->setId(std::stoi(myWindow->idInput->value()));
    std::string dataDB=myWindow->localUser->generateStringDB();
    std::cout<<"updating....:"<<dataDB<<std::endl;

    if(myWindow->modeUpdate==false){
        int returned = myWindow->localDB->insertElementTable(dataDB,"users");
        if(returned ==-1)
            {
                fl_alert("Error inserting user into db!\n");
            }
        else{
                fl_alert("User inserted!\n");
            }    
    }else{

        std::string dbData;  
        dbData= myWindow->localUser->generateUpdateDB();
        std::cout<<dbData<<std::endl;
        int returned = myWindow->localDB->updateElementTable(dbData,"users",myWindow->localUser->getId());
         if(returned ==-1)
            {
                fl_alert("Error altering user into db!\n");
            }
        else{
                fl_alert("User modified!\n");
            } 
    }

}


/**
 * @brief Destroy the users Window::users Window object
 * 
 */

users_Window::~users_Window(){ 
    delete(this->labelId);
    delete(this->idInput);
    delete(this->labelFirstName);
    delete(this->firstNameInput);

    delete(this->labelLastName);
    delete(this->lastNameInput);

    delete (this->labelPassword);
    delete (this->passwordInput);
    delete (this->labelMode) ;
    delete (this->modeInput);
    delete (this->labelUsername );
    delete (this->usernameInput);
    delete (this->search ); 
    delete (this->create ); 
    delete (this->update ); 
    delete (this->quit ); 
    delete (this->send ); 
    delete this->localUser;
}
#include <users_window.h>
#include <databaseService.h>
#include <iostream>
#include <sstream>
#include <FL/fl_ask.H>
#include <person_class.h>


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
users_Window::users_Window(int w, int h, int data, databaseService *localDB, bool *state):Fl_Group(10,35,w-10,h-35,"Users")
{
    this->set_authorization(state);
    

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
    lastNameInput = new Fl_Int_Input( 100,175,150,25);
    lastNameInput->hide();
    /*first Name input
    */
    labelFirstName = new Fl_Box(40,210,25,25,"FirstName:");
    labelFirstName->hide();
    firstNameInput = new Fl_Int_Input( 100,210,150,25);
    firstNameInput->hide();
        
    /*password
    */
    labelPassword = new Fl_Box(40,245,25,25,"Password:");
    labelPassword->hide();
    passwordInput = new Fl_Int_Input( 100,245,150,25);
    passwordInput->hide();
    
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


int users_Window::set_value(unsigned int valueP) {
    this->value=valueP;
    return 1;    
}

void users_Window::search_cb(Fl_Widget* w,void* data){  
    users_Window *myWindow = (users_Window*)data;          
    

    if(*(myWindow->get_authorization())==false){
        std::cout<<"first needs login..."<<std::endl;
        fl_alert("Not Logged!, first needs login...");        
        return;
    }
 
    std::cout<<"searching...."<<std::endl;
    std::cout<<"id:"<<myWindow->idInput->value()<<std::endl;
    std::stringstream ss;
    ss<<myWindow->idInput->value();
    std::string localId=ss.str();

    const std::string myUser=myWindow->localDB->findElement("users","id",localId);
    std::cout<<"user:"<<myUser<<std::endl;
    myWindow->localUser= new Person(&myUser);

    const char *one=(myWindow->localUser->getFirstName()).c_str();
    const char *two=(myWindow->localUser->getLastName()).c_str();
    const char *three=(myWindow->localUser->getPassword()).c_str();

    myWindow->firstNameInput->value(one);
    myWindow->lastNameInput->value(two);
    myWindow->passwordInput->value(three);

    
    myWindow->labelFirstName->show();
    myWindow->firstNameInput->show();
    myWindow->labelLastName->show();
    myWindow->lastNameInput->show();
    myWindow->labelPassword->show();
    myWindow->passwordInput->show();
    
    myWindow->search->hide();
    myWindow->create->hide();
    myWindow->quit->show();
    
    myWindow->localUser->clearData();
    myWindow->redraw();
}

void users_Window::create_cb(Fl_Widget* w,void* data){  
    users_Window *myWindow = (users_Window*)data;          

    if(*(myWindow->get_authorization())==false){
        std::cout<<"first needs login..."<<std::endl;
        fl_alert("Not Logged!, first needs login...");        
        return;
    } 
    
    std::cout<<"creating...."<<std::endl;

    
}

void users_Window::update_cb(Fl_Widget* w,void* data){  
    users_Window *myWindow = (users_Window*)data;          

    if(*(myWindow->get_authorization())==false){
        std::cout<<"first needs login..."<<std::endl;
        fl_alert("Not Logged!, first needs login...");        
        return;
    } 
    
    std::cout<<"updating...."<<std::endl;
    
}

void users_Window::quit_cb(Fl_Widget* w,void* data){  
    users_Window *myWindow = (users_Window*)data;          

    if(*(myWindow->get_authorization())==false){
        std::cout<<"first needs login..."<<std::endl;
        fl_alert("Not Logged!, first needs login...");        
        return;
    } 
    
    std::cout<<"quitting...."<<std::endl;


    
    myWindow->labelFirstName->hide();
    myWindow->firstNameInput->hide();
    myWindow->labelLastName->hide();
    myWindow->lastNameInput->hide();
    myWindow->labelPassword->hide();
    myWindow->passwordInput->hide();
    
    myWindow->search->show();
    myWindow->create->show();
    myWindow->quit->hide();
    myWindow->redraw();
    
}


users_Window::~users_Window(){ 
    delete this->localUser;
}
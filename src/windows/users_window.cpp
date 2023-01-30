#include <users_window.h>
#include <databaseService.h>
#include <iostream>
#include <FL/fl_ask.H>


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
    
    
    labelId = new Fl_Box(50,125,150,25,"Id:");
    idInput = new Fl_Int_Input( 50,160,150,25);

    
    
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

users_Window::~users_Window(){ }
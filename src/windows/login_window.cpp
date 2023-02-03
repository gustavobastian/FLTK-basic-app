#include <login_window.h>
#include <FL/fl_ask.H>
#include <string>
#include <stdio.h>
#include <iostream>



/**
 * @brief Construct a new Login Window::products Window object
 * 
 * @param w width of the window
 * @param h height of the window
 */
login_Window::login_Window(int w, int h):Fl_Group(10,35,w-10,h-35,"login")
{
    this->value=0;
    this->localDB=NULL;
    int x_position= (w-10)/2;

    
    this->color(FL_DARK_YELLOW );
    this->selection_color(FL_DARK_YELLOW );
    label1 = new Fl_Box(x_position-75,125,150,25,"Login:");
    label2 = new Fl_Box(x_position-75-35,160,30,25,"User:");                
    name = new Fl_Input( x_position-75,160,150,25);
    label3 = new Fl_Box(x_position-75-70,200,70,25,"Password:");
    password = new Fl_Input( x_position-75,200,150,25);
    login = new Fl_Button( x_position-45,250,90,25,"Send");                                 
            
            
    this->end();
}
/**
 * @brief Construct a new products Window::products Window object
 *  
 * @param w width of the window
 * @param h height of the window
 * @param data local parameter
 * @param localDB pointer to a database object 
 */
login_Window::login_Window(int w, int h, int data, databaseService *localDB, bool *state):Fl_Group(10,35,w-10,h-50,"login")
{
    this->stateLocal=state;
    if(localDB == NULL){
        std::cerr<<"no database!\n";
        return;
    }
    else{
        this->localDB = localDB;
    }
    this->value=data;
    int x_position= (w-10)/2;

    this->color(FL_DARK_CYAN);
    this->selection_color(FL_DARK_CYAN );
    label1 = new Fl_Box(x_position-75,125,150,25,"Login:");
    label2 = new Fl_Box(x_position-75-35,160,30,25,"User:");                                
    label3 = new Fl_Box(x_position-75-70,200,70,25,"Password:");
    
    name = new Fl_Input( x_position-75,160,150,25);
    name->when(FL_WHEN_CHANGED);
    name->callback(this->update_name_cb,(void*)(this));
    
    password = new Fl_Input( x_position-75,200,150,25);                                
    password->type(FL_SECRET_INPUT);
    password->when(FL_WHEN_CHANGED);
    password->callback(this->update_pass_cb,(void*)(this));               


    login = new Fl_Button( x_position-45,250,90,25,"Send");               
    
    login->color(135U);
    login->callback(this->send_values_cb, (void*)(this));
            
    this->end();
}

/**
 * @brief This function is used to monitor the value of the class
 * 
 * @return unsigned int class's internal value
 */
unsigned int login_Window::get_value() 
{
    return this->value;
}

/**
 * @brief This function set the value of the class
 * 
 * @param valueP new value
 * @return int for check
 */
int login_Window::set_value(unsigned int valueP) 
{
    
    this->value=valueP;
    return 1;
    
}


/**
 * @brief updates the name property of the login Window object
 * 
 * @param w widget containing the new name
 * @param data pointer to the login window
 */
void login_Window::update_name_cb(Fl_Widget* w,void* data){    
    login_Window *myWindow = (login_Window*)data;
    Fl_Input *input=(Fl_Input*)(w);
    myWindow->set_Name(input->value());    
    return;
}

/**
 * @brief updates the password property of the login Window object
 * 
 * @param w widget containing the new password
 * @param data pointer to the login window
 */
void login_Window::update_pass_cb(Fl_Widget* w,void* data){        
    login_Window *myWindow = (login_Window*)data;
    Fl_Input *input=(Fl_Input*)(w);
    myWindow->set_Password(input->value());    
    return;
}

/**
 * @brief Send password and username to the databaseService class in order to compare against the database
 * 
 * @param w pointer to the button object
 * @param data pointer to the login window object
 */
void login_Window::send_values_cb(Fl_Widget*w,void* data){
    login_Window *myWindow = (login_Window*)data;
    
    
    if(myWindow->localDB->validateUser(myWindow->get_Name(), myWindow->get_Password())){        
        fl_alert("Logged!\n");
        myWindow->set_State(true);        
    }
    else{        
        fl_alert("Not Logged!, error in password or username\n");
        myWindow->set_State(false);        
    }    

    return;
};
/**
 * @brief Destroy the products Window::products Window object
 * 
 */
login_Window::~login_Window(){ 
    delete this->localDB;
    delete this->stateLocal;
}
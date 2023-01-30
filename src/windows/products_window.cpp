#include <products_window.h>
#include <FL/Fl_Button.H>
#include <iostream>
/**
 * @brief Construct a new products Window::products Window object
 * 
 * @param x width of the window
 * @param y height of the window
 */
products_Window::products_Window(int x, int y):Fl_Group(10,35,x-10,y-35,"Products")
{
    this->value=0;    
    this->localDB=NULL;
    products->color(FL_DARK_YELLOW );
    products->selection_color(FL_DARK_YELLOW );
 
 /*   out = new Fl_Box(50,125,150,25,"Product:");
    I2 = new Fl_Int_Input( 50,160,150,25);
    b1 = new Fl_Button(250,160,90,25,"Search");
    b1->color(FL_DARK_CYAN);                
    b3 = new Fl_Button(340,160,90,25,"Create"); 
    b3->color(FL_DARK_CYAN);                
 */           
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
products_Window::products_Window(int w, int h, int data, databaseService *localDB, bool *state):Fl_Group(10,35,w-10,h-35,"Products")
{
    this->stateLocal = state;
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
   /* out = new Fl_Box(50,125,150,25,"Product:");
    I2 = new Fl_Int_Input( 50,160,150,25);
    b1 = new Fl_Button( 250,160,90,25,"Search"); 
    b1->color(FL_DARK_CYAN);                 
    
    b3 = new Fl_Button( 340,160,90,25,"Create"); 
    b3->color(FL_DARK_CYAN);   
    if(*(this->stateLocal)==true){
        b3->show();
    }             
    else{
        b3->hide();
    }
      */
    this->end();
}

/**
 * @brief This function is used to monitor the value of the class
 * 
 * @return unsigned int class's internal value
 */
unsigned int products_Window::get_value() 
{
    return this->value;
}

/**
 * @brief This function set the value of the class
 * 
 * @param valueP new value
 * @return int for check
 */
int products_Window::set_value(unsigned int valueP) 
{
    
    this->value=valueP;
    return 1;
    
}
/**
 * @brief Destroy the products Window::products Window object
 * 
 */
products_Window::~products_Window(){}
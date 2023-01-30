#include <stock_window.h>
#include <databaseService.h>
#include <iostream>
/**
 * @brief Construct a new stock Window::stock Window object
 * 
 * @param x width of the window
 * @param y height of the window
 */
stock_Window::stock_Window(int x, int y):Fl_Group(10,35,x-10,y-35,"Stock")
{
    this->value=0;
    this->localDB=NULL;
    
    this->color(FL_DARK_YELLOW);
    this->selection_color(FL_DARK_YELLOW );
    Fl_Box *out = new Fl_Box(50,125,150,25,"Code:");
    Fl_Int_Input *b2 = new Fl_Int_Input( 50,160,150,25);
    Fl_Button *b1 = new Fl_Button( 250,160,90,25,"Search"); b1->color(FL_DARK_CYAN);                

            
    this->end();
}
/**
 * @brief Construct a new stock Window::stock Window object
 * 
 * @param w width of the window
 * @param h height of the window
 * @param data local parameter
 * @param localDB pointer to a database object 
 */
stock_Window::stock_Window(int w, int h, int data,databaseService *localDB): Fl_Group(10,35,w-10,h-35,"Stock")
{
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
    /*
    
    out = new Fl_Box(50,125,150,25,"Code:");
    b2 = new Fl_Int_Input( 50,160,150,25);
    b1 = new Fl_Button( 250,160,90,25,"Search"); 
    b1->color(FL_DARK_CYAN);       
    */
            
    this->end();
}

/**
 * @brief returns the private value
 * 
 * @return unsigned int value
 */
unsigned int stock_Window::get_stock() 
{
    return this->value;
}

/**
 * @brief set the private value
 * 
 * @param valueP 
 * @return int 1:value ok
 */
int stock_Window::set_stock(unsigned int valueP) 
{
    
    this->value=valueP;
    return 1;
    
}

/**
 * @brief Destroy the stock Window::stock Window object
 * 
 */
stock_Window::~stock_Window(){ }   
#ifndef PRODUCTS_H
#define PRODUCTS_H
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_JPEG_Image.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Int_Input.H>
#include <FL/Fl_Multiline_Output.H>
#include <databaseService.h>


/**
 * @file products_window.h
 * @author Gustavo Bastian (bastian.gustavo@gmail.com)
 * @brief simple window derived from Fl_Group that is used to alter the products table of the system.
 * @version 0.1
 * @date 2023-01-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 * @brief class representing the product creation/modification window
 * 
 */
class products_Window:public Fl_Group
{
    private:
        unsigned int value;
        Fl_Group *products; 
        Fl_Box *out;
        Fl_Int_Input *I2;
        Fl_Button *b1;    
        Fl_Button *b3 ;
        databaseService *localDB;
    public:
        bool *stateLocal;
        products_Window(int x, int y);
        products_Window(int x, int y, int data,databaseService *localDB, bool *state);

        unsigned int get_value();
        int set_value(unsigned int valueP);
        ~products_Window();
};

#endif
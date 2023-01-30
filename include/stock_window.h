#ifndef STOCK_H
#define STOCK_H
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
 * @file stock_window.h
 * @author Gustavo Bastian (bastian.gustavo@gmail.com)
 * @brief simple window derived from Fl_Group that is used to alter the stock table of the system.
 * @version 0.1
 * @date 2023-01-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 * @brief class representing the stock's manager window
 * 
 */
class stock_Window:public Fl_Group
{
    private:
        unsigned int value;
        databaseService *localDB;        
        Fl_Box *out ;
        Fl_Int_Input *b2;
        Fl_Button *b1; 
    public:
        stock_Window(int x, int y);
        stock_Window(int x, int y, int data,databaseService *localDB);

        unsigned int get_stock();
        int set_stock(unsigned int valueP);
        ~stock_Window();
};

#endif

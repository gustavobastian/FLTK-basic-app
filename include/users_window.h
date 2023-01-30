#ifndef USERS_H
#define USERS_H

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
 * @file users_window.h
 * @author Gustavo Bastian (bastian.gustavo@gmail.com)
 * @brief simple window derived from Fl_Group that is used to alter the users table of the system.
 * @version 0.1
 * @date 2023-01-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */



/**
 * @brief class representing the user's window manager
 * 
 */

class users_Window:public Fl_Group
{
    private:
        unsigned int value;        
        databaseService *localDB;
        Fl_Box *labelId ;
        Fl_Int_Input *idInput;
        Fl_Button *search ; 
        Fl_Button *create ; 
        Fl_Button *update ; 
        
        bool *authorization;
    public:
        users_Window(int x, int y);
        users_Window(int w, int h, int data, databaseService *localDB, bool *state);

        unsigned int get_value();
        int set_value(unsigned int valueP);
        static void search_cb(Fl_Widget* w,void* data);      
        static void create_cb(Fl_Widget* w,void* data);      
        static void update_cb(Fl_Widget* w,void* data);      
        

        bool *get_authorization(){ return this->authorization; }  
        void set_authorization(bool *_state);
        ~users_Window();
};

#endif
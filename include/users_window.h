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
#include <FL/Fl_Input.H>
#include <FL/Fl_Multiline_Output.H>
#include <databaseService.h>
#include <person_class.h>

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

        Person *localUser;

        Fl_Box *labelFirstName ;
        Fl_Input *firstNameInput;
        Fl_Box *labelLastName ;
        Fl_Input *lastNameInput;
        Fl_Box *labelPassword ;
        Fl_Input *passwordInput;
        Fl_Box *labelMode ;
        Fl_Input *modeInput;
        Fl_Box *labelUsername ;
        Fl_Input *usernameInput;

        Fl_Button *search ; 
        Fl_Button *create ; 
        Fl_Button *update ; 
        Fl_Button *quit ; 
        
        bool *authorization;
    public:
        users_Window(int x, int y);
        users_Window(int w, int h, int data, databaseService *localDB, bool *state);

        unsigned int get_value();
        int set_value(unsigned int valueP);
        static void search_cb(Fl_Widget* w,void* data);      
        static void create_cb(Fl_Widget* w,void* data);      
        static void update_cb(Fl_Widget* w,void* data);      
        static void quit_cb(Fl_Widget* w,void* data);      
        

        bool *get_authorization(){ return this->authorization; }  
        void set_authorization(bool *_state);

        static void update_pass_cb(Fl_Widget* w,void* data);        
        static void update_firstName_cb(Fl_Widget* w,void* data);        
        static void update_lastName_cb(Fl_Widget* w,void* data);        
        static void update_mode_cb(Fl_Widget* w,void* data);        
        static void update_username_cb(Fl_Widget* w,void* data);        

        ~users_Window();

};

#endif
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

        bool modeUpdate=false;

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
        Fl_Button *send ; 
        
        bool *authorization;
    public:
        users_Window(int x, int y);
        /**
         * @brief Construct a new users Window::users Window object
         * 
         * @param w 
         * @param h 
         * @param data 
         * @param localDB 
         * @param state 
         */

        users_Window(int w, int h, int data, databaseService *localDB, bool *state);

        unsigned int get_value();
        /**
         * @brief set local value for the user window
         * 
         * @param valueP 
         * @return int 
         */
        int set_value(unsigned int valueP);
        /**
         * @brief callback for looking for a user
         * 
         * @param w pointer to button
         * @param data pointer to parent window
         */
        static void search_cb(Fl_Widget* w,void* data);   
        /**
         * @brief callback function for the create button
         * 
         * @param w pointer to the button
         * @param data pointer to the parent window
         */
   
        static void create_cb(Fl_Widget* w,void* data);
        /**
         * @brief callback function for the update button
         * 
         * @param w pointer to the button
         * @param data pointer to the window
         */      
        static void update_cb(Fl_Widget* w,void* data); 
                
        /**
         * @brief callback function for the quit button, erases the current person and hide send button
         * 
         * @param w 
         * @param data 
         */     
        static void quit_cb(Fl_Widget* w,void* data);      
        static void send_cb(Fl_Widget* w,void* data);      
        

        /**
         * @brief Checks if a user is logged in the system and enables functionalities
         * 
         * @param _state 
         */
        bool *get_authorization(){ return this->authorization; }  
        /**
         * @brief binds the object state to external state
         * 
         * @param _state 
         */
        void set_authorization(bool *_state);


        /**
         * @brief callback that update the password object when the widget is modified
         * 
         * @param w pointer to the input
         * @param data pointer to the window
         */
        static void update_pass_cb(Fl_Widget* w,void* data);        

        /**
         * @brief function that update the first name when the widget is modified
         * 
         * @param w pointer to the widget
         * @param data pointer to the window
         */
        static void update_firstName_cb(Fl_Widget* w,void* data);        
        /**
         * @brief function that update the last name when the widget is modified
         * 
         * @param w pointer to the widget
         * @param data pointer to the window
         */
        static void update_lastName_cb(Fl_Widget* w,void* data);
        /**
         * @brief function that update the mode when the widget is modified
         * 
         * @param w pointer to the widget modified 
         * @param data pointer to the window
         */
        static void update_mode_cb(Fl_Widget* w,void* data);        

        /**
         * @brief function that update the username when the widget is modified
         * 
         * @param w pointer to the widget
         * @param data pointer to the window
         */
        static void update_username_cb(Fl_Widget* w,void* data);        
        /**
         * @brief Destroy the users Window::users Window object
         * 
         */
        ~users_Window();

};

#endif
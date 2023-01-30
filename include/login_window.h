#ifndef LOGIN_H
#define LOGIN_H

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
#include <FL/Fl_Secret_Input.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Widget.H>
#include <databaseService.h>
#include <string>
#include <iostream>


/**
 * @file login_window.h
 * @author Gustavo Bastian (bastian.gustavo@gmail.com)
 * @brief simple window derived from Fl_Group that is used login to the system.
 * @version 0.1
 * @date 2023-01-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 * @brief class representing the login window
 * 
 */

class login_Window:public Fl_Group
{
    private:
        unsigned int value;                
        /**
         * @brief Local storage for name
         * 
         */
        std::string nameS="";
        /**
         * @brief Local storage for password
         * 
         */
        std::string passwordS="";
        /**
         * @brief Pointer to the label 1:"Login"
         * 
         */
        Fl_Box *label1 ;
        /**
         * @brief Pointer to the label 2:"Username"
         * 
         */
        Fl_Box *label2 ;
        /**
         * @brief Pointer to the label 3:"Password"
         * 
         */
        Fl_Box *label3;
        /**
         * @brief Pointer to the input where is stored the name
         * 
         */
        Fl_Input *name;
        /**
         * @brief Pointer to the input where is stored the password
         * 
         */
        Fl_Input *password;  
        /**
         * @brief Pointer to the button "login"
         * 
         */
        Fl_Button *login;        

    public:
        /**
         * @brief Pointer to the databaseService class
         * 
         */

        databaseService *localDB;
        /**
         * @brief Pointer to a bool where is saved the status logged("true")/not logged("false") of the system
         * 
         */
        bool *stateLocal;

        /**
         * @brief Construct a new login Window object
         * 
         * @param x width of window
         * @param y height of window
         */
        login_Window(int x, int y);

        /**
         * @brief Construct a new login Window object
         * 
         * @param w width of window
         * @param h height of window
         * @param data 
         * @param localDB pointer to the databaseService class
         * @param state pointer to the status of the system(Logged or not logged)
         */
        login_Window(int w, int h, int data, databaseService *localDB, bool *state);



        /**
         * @brief Get the Name object
         * 
         * @return std::string with the name
         */
        std::string get_Name(){return this->nameS;};
        /**
         * @brief Get the Password object
         * 
         * @return std::string with the password
         */
        std::string get_Password(){return this->passwordS;};
        /**
         * @brief Set the Name object
         * 
         * @param name
         */
        void set_Name(std::string param){this->nameS=param;return;};
        /**
         * @brief Set the Password object
         * 
         * @param param new password
         */
        void set_Password(std::string param){this->passwordS=param;return;};

        /**
         * @brief Get the State object
         * 
         * @return true 
         * @return false 
         */
        bool get_State(){return this->stateLocal;};
        /**
         * @brief Set the State object
         * 
         * @param stateP 
         */
        void set_State(bool stateP){*(this->stateLocal)=stateP; return;};

        /**
         * @brief Callback that updates the object component name when the widget is updated
         * 
         * @param w pointer to the widget that calls
         * @param data pointer to the parent login_window object
         */
        static void update_name_cb(Fl_Widget* w,void* data);    

        /**
         * @brief Callback that updates the object component password when the widget is updated
         * 
         * @param w pointer to the widget that calls
         * @param data pointer to the parent login_window object
         */
        static void update_pass_cb(Fl_Widget* w,void* data);    

        /**
         * @brief Callback that sends values to the database service and check if it is a valid login
         * 
         * @param w pointer to the widget that calls
         * @param data pointer to the parent login_window object
         */
        static void send_values_cb(Fl_Widget* w,void* data);    

        /**
         * @brief Get the value object
         * 
         * @return unsigned int with value of the class
         */
        unsigned int get_value();
        /**
         * @brief Set the value object of the class
         * 
         * @param valueP new value
         * @return int 
         */
        int set_value(unsigned int valueP);
        ~login_Window();
};

#endif
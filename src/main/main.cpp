#include <iostream>
#include <string>

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Widget.H>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_JPEG_Image.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Int_Input.H>
#include <FL/Fl_Multiline_Output.H>
#include <FL/fl_ask.H>
#include <FL/Enumerations.H>


#include <login_window.h>
#include <stock_window.h>
#include <products_window.h>
#include <users_window.h>

#include <person_class.h>
#include <databaseService.h>
#include <sqlite3.h>
#include <definitions.h>



/**
 * @brief main logout callback
 * 
 * @param w 
 * @param data 
 */
void logout_cb(Fl_Widget* w,void* data){
    auto *mystate= (bool*)data;
    

    if(*mystate==false)
    {
    std::cout<<"not logged"<<std::endl;
    fl_alert("Not Logged!\n");    
    return;
    }

    std::cout<<"logging out"<<std::endl;
    *mystate=false;
    fl_alert("Logged out!\n");
    

}  

int main(int argc, char **argv) {    
    
    std::string  data(dBAddress);
    auto *myDb= new databaseService(data);
    myDb->openDB();
        
    //windows parameters
    auto w=W_Width;
    auto h=W_Height;


    //TODO replace with person
    auto state=false;

    
    auto *login= new login_Window(w-10, h-50, 10 ,myDb, &state);
    auto *persons = new users_Window(w-10, h-50, 10 ,myDb, &state);

    Fl_Window *win = new Fl_Window(w,h,"DB Management");
    {   
        win->color(222U);                
        auto *localState=&state;    
        auto *tabs = new Fl_Tabs(5,5,w-10,h-50);    
        
        {
            tabs->selection_color(FL_YELLOW);
            //login tab

            tabs->add(login);            

            // users tab
            tabs->add(persons);


            
            
        }
        tabs->end();    
    }

    auto *logout = new Fl_Button( w-95,10,90,25,"Logout"); 
    logout->color(247);  
    logout->callback(logout_cb,&state);

    win->end();
    win->show();
    int retval = 1;
    if (Fl::run()){
       return retval = 0;
    }                 
    
    //cleaning pointers
    delete(login);    
    delete(persons);
    delete(myDb);    
    delete(logout);
    delete(win);

    return retval ;
    
}

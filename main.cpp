#include "MainMenu.h"
#include "game.h"
#include<cstring>

class error{
private:
    char msg[25];
public:
    error(){}
    error(char err[]){strcpy(msg,err);}
    void error_msg(){
        cerr<<msg<<endl;
    }
};

int main()
{
    try{
    MainMenu menu;
    if(menu.show()){
        error e("Error showing menu! ");
        throw e;
    }
    int opt= menu.Selected();
    cout<<opt<<endl;
    do{
        switch(opt){

        case 0:{
            Game Baagchal;
            if(Baagchal.run()){
                error e("Error running game! ");
                throw e;
            }
            if(menu.show()){
                error e("Error showing menu! ");
                throw e;
            }
            break;
        }
        case 1:{
            if(menu.Howtoplay()){
                error e("Error showing How to play!");
                throw e;
            }
            break;
        }
        case 2:{
            if(menu.About()){
                error e("Error showing About!");
                throw e;
            }
            break;
        }
        case 3:{
            cout<<"Good days to come\nSee you again";
            return 0;
        }
        default:
            break;
        }
        opt= menu.Selected();
    }while(opt!=3);

    }catch(error er){
    er.error_msg();
    }
    return 0;
}

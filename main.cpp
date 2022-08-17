#include "MainMenu.h"
#include "game.h"
#include<cstring>
class error{
private:
    char msg[25];
public:
    error(char err[]){strcpy(msg,err);}
    void error_msg(){
        cout<<msg<<endl;
    }
};


int main()
{
  try{
    MainMenu menu;
    int opt = menu.show();
    cout<<opt<<endl;
    switch(opt){

    case(0):{
        Game Baagchal;
        if(Baagchal.run()!=0){
            error e("...Error running game!");
            throw e;
        }
        break;
    }

    case(1):
        if(!menu.Options()){
            error e("Error showing options!");
            throw e;
        }
        break;

    case(2):
        if(!menu.About()){
            error e("Error showing About info!");
            throw e;
        }
        break;
    case(3):
        cout<<"Good days to come\nSee you again";
        return 0;

    default:{
        error e("Error from my side \"_\'");
        throw e;
        break;
    }
    }
  }
  catch(error er){
    er.error_msg();
  }

  return 0;
}

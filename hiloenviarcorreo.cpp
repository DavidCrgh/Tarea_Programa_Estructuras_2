#include "hiloenviarcorreo.h"
#include "unistd.h"
#include <cstdlib>
#include <iostream>
using namespace std;

HiloEnviarCorreo::HiloEnviarCorreo()
{
    ejecucion="";
    stop=false;
    pause=true;

}

void HiloEnviarCorreo::run(){
    chdir("C:\\Users\\Francisco Contreras\\workspace\\pruebaCorreo\\src\\pruebaCorreo\\");
    while(!stop){

        while(pause){
         msleep(10);
        }

        mute.lock();
        system(ejecucion);
        mute.unlock();
        pause=true;

    }

}

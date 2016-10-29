#include "ventanalistamundo.h"
#include "ui_ventanalistamundo.h"


VentanaListaMundo::VentanaListaMundo(QWidget *parent,QString* pNombrePecado,ListaMundo* pListaMundo) :
    QMainWindow(parent),
    ui(new Ui::VentanaListaMundo)
{
    ui->setupUi(this);
    nombrePecado=pNombrePecado;
    listaMundo=pListaMundo;
   //humanoTemporal= listaMundo->primerHumano;
  // contadorHumanos=0;

}

VentanaListaMundo::~VentanaListaMundo()
{
    delete ui;
}


void VentanaListaMundo::on_actualizar_clicked()
{
   // int cuantosHumanos=10;
   // int indice=0;

    ui->informacionHumanos->setText(listaMundo->imprimirListaMundo(nombrePecado));//,cuantosHumanos,humanoTemporal,contadorHumanos));
    /*    while(indice<cuantosHumanos){
            humanoTemporal= humanoTemporal->siguiente;
            indice++;

        }
        contadorHumanos+=10;*/
}

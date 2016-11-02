#include "ventanaconsultasfamilia.h"
#include "ui_ventanaconsultasfamilia.h"

VentanaConsultasFamilia::VentanaConsultasFamilia(QWidget *parent,ListaMundo* pListaMundo) :
    QMainWindow(parent),
    ui(new Ui::VentanaConsultasFamilia)
{
    ui->setupUi(this);
    ui->idFamilias->setRange(0,9999999);
    listaMundo=pListaMundo;

}

VentanaConsultasFamilia::~VentanaConsultasFamilia()
{
    delete ui;
}

void VentanaConsultasFamilia::on_aceptar_clicked()
{
    int id= ui->idFamilias->value();

    if(listaMundo->arbolMundo!=NULL){
    NodoHumano* personaEncontrada=listaMundo->buscar(id,listaMundo->arbolMundo);

    if(personaEncontrada!=NULL){
        ui->infoFamilia->setText(imprimirNodo(personaEncontrada));

    }
    else{

        ui->infoFamilia->setText("El Humano de ID:"+QString::number(id)+" no existe.");
    }

    }
}

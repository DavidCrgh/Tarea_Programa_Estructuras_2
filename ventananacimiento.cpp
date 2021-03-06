#include "ventananacimiento.h"
#include "ui_ventananacimiento.h"
#include <cstdlib>
#include <iostream>

using namespace std;


VentanaNacimiento::VentanaNacimiento(QWidget *parent,QString* pApellidos, QString* pNombres,
    QString* pPaises,QString* pCreencias,QString* pProfesiones,QString* pNombrePecado,ListaMundo* pListaMundo,
                              ArbolVida* pArbolVida,Paraiso* pParaiso,QString* pContinentes):


    QMainWindow(parent),
    ui(new Ui::VentanaNacimiento)
{
    ui->setupUi(this);
    QStringList listaApellidos;
    apellidos= pApellidos;

    for(int i=0;i<1000;i++)
        listaApellidos.append(apellidos[i]);

    ui->cBoxApellidos->addItems(listaApellidos);



    ui->casillaHumanos->setRange(0,9999999);
    nombres=pNombres;
    paises=pPaises;
    creencias=pCreencias;
    profesiones=pProfesiones;
    nombrePecado= pNombrePecado;
    listaMundo=pListaMundo;
    ventanaHumanos= new VentanaListaMundo(NULL,nombrePecado,listaMundo);
    arbolVida = pArbolVida;
    paraiso= pParaiso;
    continentes=pContinentes;
    ui->casillaHumanos->setDisabled(true);
    ui->casillaHumanos->setValue(10000);

    hiloCrearHumanos = new HiloCrearHumanos(NULL,listaMundo,apellidos,nombres,paises,creencias,
                                            profesiones,arbolVida,paraiso,continentes);
    //hiloCrearHumanos->pause=true;
    hiloCrearHumanos->start();
}

VentanaNacimiento::~VentanaNacimiento()
{
    delete ui;
}

void VentanaNacimiento::on_aceptar_clicked()
{

    int cantidadHumanosCrear= ui->casillaHumanos->value();
    hiloCrearHumanos->cantidadHumanos=cantidadHumanosCrear;
    hiloCrearHumanos->pause=false;


    ui->casillaHumanos->setDisabled(false);
    ui->casillaHumanos->setValue(0);

}

void VentanaNacimiento::actualizarVentana(){
    ui->cantidadHumanos->setText(QString::number(listaMundo->cantidadHumanos()));
    ui->casillaHumanos->setRange(0,9999999-(listaMundo->cantidadHumanos()));
}

void VentanaNacimiento::on_botonHumanos_clicked()
{
    ventanaHumanos->show();
    close();
}

void VentanaNacimiento::on_botonMundo_clicked()
{
    ui->cBoxApellidos->setEnabled(false);
    if(listaMundo->arbolMundo != NULL){
        ui->displayArbol->clear();
        ui->displayArbol->addTopLevelItem(crearTreeWidgetItem(listaMundo->arbolMundo));
    }
}

void VentanaNacimiento::on_botonApellidos_clicked()
{
    ui->cBoxApellidos->setEnabled(true);
    if(listaMundo->arregloArbolesApellido[ui->cBoxApellidos->currentIndex()] != NULL){
        ui->displayArbol->clear();
        ui->displayArbol->addTopLevelItem(crearTreeWidgetItem(listaMundo->arregloArbolesApellido[ui->cBoxApellidos->currentIndex()]));
}
}

void VentanaNacimiento::on_cBoxApellidos_currentIndexChanged(int index)
{

}

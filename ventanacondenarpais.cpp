#include "ventanacondenarpais.h"
#include "ui_ventanacondenarpais.h"

VentanaCondenarPais::VentanaCondenarPais(QWidget *parent,Infierno* pInfierno,ListaMundo* pListaMundo,QString* pPaises) :
    QMainWindow(parent),
    ui(new Ui::VentanaCondenarPais)
{
    ui->setupUi(this);
    paises=pPaises;
    QStringList listaPaises;
    for(int i=0;i<242;i++)
        listaPaises.append(paises[i]);

    ui->paisesLista->addItems(listaPaises);
    infierno= pInfierno;
    listaMundo=pListaMundo;
}

VentanaCondenarPais::~VentanaCondenarPais()
{
    delete ui;
}

void VentanaCondenarPais::on_aceptar_clicked()
{
    QString pais= ui->paisesLista->currentText();
    infierno->condenar(pais,listaMundo);
}

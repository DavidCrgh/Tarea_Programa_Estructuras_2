#include "ventanacondenarpais.h"
#include "ui_ventanacondenarpais.h"

VentanaCondenarPais::VentanaCondenarPais(QWidget *parent,QString* pPaises) :
    QMainWindow(parent),
    ui(new Ui::VentanaCondenarPais)
{
    ui->setupUi(this);
    paises=pPaises;
    QStringList listaPaises;
    for(int i=0;i<242;i++)
        listaPaises.append(paises[i]);

    ui->paisesLista->addItems(listaPaises);
}

VentanaCondenarPais::~VentanaCondenarPais()
{
    delete ui;
}

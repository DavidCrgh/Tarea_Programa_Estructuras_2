#include "ventanatop5salvados.h"
#include "ui_ventanatop5salvados.h"

VentanaTop5Salvados::VentanaTop5Salvados(QWidget *parent,ListaMundo* pListaMundo,QString* pPaises) :
    QMainWindow(parent),
    ui(new Ui::VentanaTop5Salvados)
{
    ui->setupUi(this);
    listaMundo= pListaMundo;
    paises= pPaises;
}

VentanaTop5Salvados::~VentanaTop5Salvados()
{
    delete ui;
}

void VentanaTop5Salvados::on_actualizar_clicked()
{
    ui->top5paises->setText(listaMundo->paisesPecadores(paises,false));
}


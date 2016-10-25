#include "ventanatop5salvados.h"
#include "ui_ventanatop5salvados.h"

VentanaTop5Salvados::VentanaTop5Salvados(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VentanaTop5Salvados)
{
    ui->setupUi(this);
}

VentanaTop5Salvados::~VentanaTop5Salvados()
{
    delete ui;
}

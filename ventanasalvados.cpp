#include "ventanasalvados.h"
#include "ui_ventanasalvados.h"

VentanaSalvados::VentanaSalvados(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VentanaSalvados)
{
    ui->setupUi(this);
}

VentanaSalvados::~VentanaSalvados()
{
    delete ui;
}

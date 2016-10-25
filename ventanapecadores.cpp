#include "ventanapecadores.h"
#include "ui_ventanapecadores.h"

VentanaPecadores::VentanaPecadores(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VentanaPecadores)
{
    ui->setupUi(this);
}

VentanaPecadores::~VentanaPecadores()
{
    delete ui;
}

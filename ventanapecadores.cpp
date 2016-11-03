#include "ventanapecadores.h"
#include "ui_ventanapecadores.h"

VentanaPecadores::VentanaPecadores(QWidget *parent,QString* pPaises,QString* pApellidos,QString* pCreencias,QString* pProfesiones) :
    QMainWindow(parent),
    ui(new Ui::VentanaPecadores)
{
    ui->setupUi(this);
    paises=pPaises;
    apellidos=pApellidos;
    creencias=pCreencias;
    profesiones=pProfesiones;
}

VentanaPecadores::~VentanaPecadores()
{
    delete ui;
}

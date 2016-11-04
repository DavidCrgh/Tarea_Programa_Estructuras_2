#include "ventanaconsultaapellido.h"
#include "ui_ventanaconsultaapellido.h"

VentanaConsultaApellido::VentanaConsultaApellido(QWidget *parent, QString* ) :
    QMainWindow(parent),
    ui(new Ui::VentanaConsultaApellido)
{
    ui->setupUi(this);

}

VentanaConsultaApellido::~VentanaConsultaApellido()
{
    delete ui;
}

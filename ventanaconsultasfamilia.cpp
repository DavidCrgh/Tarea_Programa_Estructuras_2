#include "ventanaconsultasfamilia.h"
#include "ui_ventanaconsultasfamilia.h"

VentanaConsultasFamilia::VentanaConsultasFamilia(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VentanaConsultasFamilia)
{
    ui->setupUi(this);

}

VentanaConsultasFamilia::~VentanaConsultasFamilia()
{
    delete ui;
}

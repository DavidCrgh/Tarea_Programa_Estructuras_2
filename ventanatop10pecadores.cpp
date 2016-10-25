#include "ventanatop10pecadores.h"
#include "ui_ventanatop10pecadores.h"

VentanaTop10Pecadores::VentanaTop10Pecadores(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VentanaTop10Pecadores)
{
    ui->setupUi(this);
}

VentanaTop10Pecadores::~VentanaTop10Pecadores()
{
    delete ui;

}

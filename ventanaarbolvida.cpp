#include "ventanaarbolvida.h"
#include "ui_ventanaarbolvida.h"

VentanaArbolVida::VentanaArbolVida(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VentanaArbolVida)
{
    ui->setupUi(this);
}

VentanaArbolVida::~VentanaArbolVida()
{
    delete ui;
}

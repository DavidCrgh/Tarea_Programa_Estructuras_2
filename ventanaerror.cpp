#include "ventanaerror.h"
#include "ui_ventanaerror.h"

VentanaError::VentanaError(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VentanaError)
{
    ui->setupUi(this);
}

VentanaError::~VentanaError()
{
    delete ui;
}

void VentanaError::on_aceptar_clicked()
{
    close();
}

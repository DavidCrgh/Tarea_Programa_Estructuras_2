#include "ventanamundo.h"
#include "ui_ventanamundo.h"

VentanaMundo::VentanaMundo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VentanaMundo)
{
    ui->setupUi(this);
}

VentanaMundo::~VentanaMundo()
{
    delete ui;
}

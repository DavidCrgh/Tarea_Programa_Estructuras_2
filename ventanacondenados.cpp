#include "ventanacondenados.h"
#include "ui_ventanacondenados.h"

VentanaCondenados::VentanaCondenados(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VentanaCondenados)
{
    ui->setupUi(this);
}

VentanaCondenados::~VentanaCondenados()
{
    delete ui;
}

#include "ventanatop10pecadores.h"
#include "ui_ventanatop10pecadores.h"

VentanaTop10Pecadores::VentanaTop10Pecadores(QWidget *parent,ListaMundo* pListaMundo,QString* pPaises) :
    QMainWindow(parent),
    ui(new Ui::VentanaTop10Pecadores)
{
    ui->setupUi(this);
    listaMundo=pListaMundo;
    paises=pPaises;
}

VentanaTop10Pecadores::~VentanaTop10Pecadores()
{
    delete ui;

}

void VentanaTop10Pecadores::on_actualizar_clicked()
{
    ui->top10paises->setText(listaMundo->paisesPecadores(paises,true));
}

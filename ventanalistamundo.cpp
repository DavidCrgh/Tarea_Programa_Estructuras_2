#include "ventanalistamundo.h"
#include "ui_ventanalistamundo.h"


VentanaListaMundo::VentanaListaMundo(QWidget *parent,QString* pNombrePecado,ListaMundo* pListaMundo) :
    QMainWindow(parent),
    ui(new Ui::VentanaListaMundo)
{
    ui->setupUi(this);
    nombrePecado=pNombrePecado;
    listaMundo=pListaMundo;

}

VentanaListaMundo::~VentanaListaMundo()
{
    delete ui;
}


void VentanaListaMundo::on_actualizar_clicked()
{

    ui->informacionHumanos->setText(listaMundo->imprimirListaMundo(nombrePecado));
}

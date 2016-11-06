#include "ventananonacidos.h"
#include "ui_ventananonacidos.h"

VentanaNoNacidos::VentanaNoNacidos(QWidget *parent, ListaMundo* pMundo,
                                   Infierno* pInfierno, Paraiso* pParaiso, ArbolVida* pArbolVida) :
    QMainWindow(parent),
    ui(new Ui::VentanaNoNacidos)
{
    ui->setupUi(this);
    mundo = pMundo;
    infierno = pInfierno;
    paraiso = pParaiso;
    arbolVida = pArbolVida;
}

VentanaNoNacidos::~VentanaNoNacidos()
{
    delete ui;
}

void VentanaNoNacidos::on_botonActualizar_clicked()
{
    if(mundo->arbolMundo != NULL){
        ui->cuadroIds->setText(generarNoNacidos(mundo,infierno,paraiso,arbolVida));
    }
}

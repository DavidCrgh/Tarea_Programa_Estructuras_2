#include "ventanasalvados.h"
#include "ui_ventanasalvados.h"

VentanaSalvados::VentanaSalvados(QWidget *parent, Paraiso* pParaiso, QString* pNombrePecados) :
    QMainWindow(parent),
    ui(new Ui::VentanaSalvados)
{
    ui->setupUi(this);
    paraiso = pParaiso;
    nombrePecados = pNombrePecados;
}

VentanaSalvados::~VentanaSalvados()
{
    delete ui;
}

void VentanaSalvados::on_actualizar_clicked()
{
   ui->informacionSalvados->setText(paraiso->listaParaiso->listaCondenadosSalvadosOrdenada(false));
   if(paraiso->arbolParaiso != NULL){
       ui->arbolAVL->clear();
       ui->arbolAVL->addTopLevelItem(crearTreeWidgetItem(paraiso->arbolParaiso));
   }
}

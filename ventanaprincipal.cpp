#include "ventanaprincipal.h"
#include "ui_ventanaprincipal.h"

VentanaPrincipal::VentanaPrincipal(QWidget *parent,QString* pApellidos,QString* pNombres,QString* pPaises,
                                   QString* pCreencias, QString* pProfesiones,QString* pNombrePecados,
                                    ListaMundo*pListaMundo, ArbolApellidos* pArbolesApellido[]):
    QMainWindow(parent),
    ui(new Ui::VentanaPrincipal)
{
    ui->setupUi(this);
    apellidos=pApellidos;
    nombres=pNombres;
    paises=pPaises;
    creencias=pCreencias;
    profesiones=pProfesiones;
    nombrePecado= pNombrePecados;
    listaMundo=pListaMundo;
    arbolesApellidos = pArbolesApellido;

    ventanaMundo = new VentanaMundo(NULL,apellidos,nombres,paises,creencias,profesiones,nombrePecado,listaMundo);

}

VentanaPrincipal::~VentanaPrincipal()
{
    delete ui;
}

void VentanaPrincipal::on_pushButton_clicked()
{

    ventanaMundo->show();
    close();

}

#include "ventananacimiento.h"
#include "ui_ventananacimiento.h"


VentanaNacimiento::VentanaNacimiento(QWidget *parent,QString* pApellidos, QString* pNombres,
    QString* pPaises,QString* pCreencias,QString* pProfesiones,QString* pNombrePecado,ListaMundo* pListaMundo,
                              ArbolVida* pArbolVida,Paraiso* pParaiso):
                                     /*ArbolApellidos** pArbolesApellidos*/

    QMainWindow(parent),
    ui(new Ui::VentanaNacimiento)
{
    ui->setupUi(this);
    QStringList listaApellidos;
    apellidos= pApellidos;

    for(int i=0;i<1000;i++)
        listaApellidos.append(apellidos[i]);

    ui->cBoxApellidos->addItems(listaApellidos);



    ui->casillaHumanos->setRange(0,9999999);
    nombres=pNombres;
    paises=pPaises;
    creencias=pCreencias;
    profesiones=pProfesiones;
    nombrePecado= pNombrePecado;
    listaMundo=pListaMundo;
    ventanaHumanos= new VentanaListaMundo(NULL,nombrePecado,listaMundo);
    arbolVida = pArbolVida;
    paraiso= pParaiso;
    //ui->casillaHumanos->setDisabled(true);
    ui->casillaHumanos->setValue(10000);
    //arbolesApellidos = pArbolesApellidos;
}

VentanaNacimiento::~VentanaNacimiento()
{
    delete ui;
}

void VentanaNacimiento::on_aceptar_clicked()
{

    int cantidadHumanos= ui->casillaHumanos->value();

    ui->casillaHumanos->setDisabled(false);
    ui->casillaHumanos->setValue(0);

    hiloCrearHumanos = new HiloCrearHumanos(NULL,listaMundo,apellidos,nombres,paises,creencias,
                                            profesiones,cantidadHumanos,arbolVida,paraiso);

    hiloCrearHumanos->start();

}

void VentanaNacimiento::actualizarVentana(){

    ui->cantidadHumanos->setText(QString::number(listaMundo->cantidadHumanos()));
    ui->casillaHumanos->setRange(0,9999999-(listaMundo->cantidadHumanos()));
    }

void VentanaNacimiento::on_botonHumanos_clicked()
{

    ventanaHumanos->show();
    close();
}

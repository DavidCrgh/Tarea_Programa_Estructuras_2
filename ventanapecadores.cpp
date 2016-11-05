#include "ventanapecadores.h"
#include "ui_ventanapecadores.h"

VentanaPecadores::VentanaPecadores(QWidget *parent,QString* pPaises,QString* pApellidos,QString* pCreencias,QString* pProfesiones) :
    QMainWindow(parent),
    ui(new Ui::VentanaPecadores)
{
    ui->setupUi(this);
    paises=pPaises;
    apellidos=pApellidos;
    creencias=pCreencias;
    profesiones=pProfesiones;
    QString continentes[] ={"America","Africa","Europa","Asia","Oceania"};

    QStringList listaPaises;
    QStringList listaApellidos;
    QStringList listaCreencias;
    QStringList listaProfesiones;
    QStringList listaContinentes;

    for(int i=0;i<242;i++){
        listaPaises.append(paises[i]);
    }
    ui->listaPaises->addItems(listaPaises);

    for(int i=0;i<1000;i++){
        listaApellidos.append(apellidos[i]);
    }

    ui->listaApellidos->addItems(listaApellidos);
    for(int i=0;i<10;i++){
        listaCreencias.append(creencias[i]);
    }
    ui->listaCreencias->addItems(listaCreencias);

    for(int i=0;i<50;i++){
        listaProfesiones.append(profesiones[i]);

    }
    ui->listaProfesiones->addItems(listaProfesiones);
    for(int i=0;i<5;i++){
        listaContinentes.append(continentes[i]);
    }
    ui->listaContinentes->addItems(listaContinentes);

    ui->listaApellidos->setDisabled(true);
    ui->listaContinentes->setDisabled(true);
    ui->listaCreencias->setDisabled(true);
    ui->listaProfesiones->setDisabled(true);
    ui->listaPaises->setDisabled(true);


}

VentanaPecadores::~VentanaPecadores()
{
    delete ui;
}

void VentanaPecadores::on_botonContinentes_clicked(bool checked)
{
    ui->listaApellidos->setDisabled(true);
    ui->listaContinentes->setDisabled(false);
    ui->listaCreencias->setDisabled(true);
    ui->listaProfesiones->setDisabled(true);
    ui->listaPaises->setDisabled(true);

}

void VentanaPecadores::on_botonApellidos_clicked(bool checked)
{
    ui->listaApellidos->setDisabled(false);
    ui->listaContinentes->setDisabled(true);
    ui->listaCreencias->setDisabled(true);
    ui->listaProfesiones->setDisabled(true);
    ui->listaPaises->setDisabled(true);

}

void VentanaPecadores::on_botonPaises_clicked(bool checked)
{
    ui->listaApellidos->setDisabled(true);
    ui->listaContinentes->setDisabled(true);
    ui->listaCreencias->setDisabled(true);
    ui->listaProfesiones->setDisabled(true);
    ui->listaPaises->setDisabled(false);

}

void VentanaPecadores::on_botonCreencias_clicked(bool checked)
{
    ui->listaApellidos->setDisabled(true);
    ui->listaContinentes->setDisabled(true);
    ui->listaCreencias->setDisabled(false);
    ui->listaProfesiones->setDisabled(true);
    ui->listaPaises->setDisabled(true);

}

void VentanaPecadores::on_botonProfesiones_clicked(bool checked)
{
    ui->listaApellidos->setDisabled(true);
    ui->listaContinentes->setDisabled(true);
    ui->listaCreencias->setDisabled(true);
    ui->listaProfesiones->setDisabled(false);
    ui->listaPaises->setDisabled(true);

}

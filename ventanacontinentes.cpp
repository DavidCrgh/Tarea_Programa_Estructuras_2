#include "ventanacontinentes.h"
#include "ui_ventanacontinentes.h"

VentanaContinentes::VentanaContinentes(QWidget *parent,ListaMundo* pListaMundo) :
    QMainWindow(parent),
    ui(new Ui::VentanaContinentes)
{
    ui->setupUi(this);
    listaMundo=pListaMundo;
    QString continentes[]={"america","europa","asia","africa","oceania"};

    QString degradacion[]={"negro","rojo","anaranjado","amarillo","verde"};

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){

            colores[i][j]=":/imagenes/recursos/imagenes/" +degradacion[j]+continentes[i]+".png";

        }


    }
    QString descripcion;

    descripcion+= "Negro: 1er Pecador\n\n";
    descripcion+= "Rojo:  2do Pecador\n\n";
    descripcion+= "Anaranjado: 3er Pecador\n\n";
    descripcion+= "Amarillo: 4to Pecador\n\n";
    descripcion+= "Verde: 5to Pecador\n\n";

    ui->etiqueta->setText(descripcion);

}

VentanaContinentes::~VentanaContinentes()
{
    delete ui;
}

void VentanaContinentes::on_pushButton_clicked()
{

    std::vector<Continente*>arregloContinentes= listaMundo->mapaCalor();

    Continente* caca;
    for(int i=0;i<5;i++){
        caca=arregloContinentes[i];
        qDebug()<<caca->nombreContinente<<""<<caca->pecadosTotales;
    }

    for(int i=0;i<arregloContinentes.size();i++){
        Continente* continenteTemporal= arregloContinentes[i];

        if(continenteTemporal->nombreContinente=="America")
            ui->america->setPixmap(QPixmap(colores[0][i]));
        else if(continenteTemporal->nombreContinente=="Europa")
            ui->europa->setPixmap(QPixmap(colores[1][i]));
        else if(continenteTemporal->nombreContinente=="Asia")
            ui->asia->setPixmap(QPixmap(colores[2][i]));
        else if(continenteTemporal->nombreContinente=="Africa")
            ui->africa->setPixmap(QPixmap(colores[3][i]));
        else
            ui->oceania->setPixmap(QPixmap(colores[4][i]));

    }


   // ui->america->setPixmap(QPixmap(colores[0][3]));
}

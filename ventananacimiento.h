#ifndef VENTANANACIMIENTO_H
#define VENTANANACIMIENTO_H

#include <QMainWindow>
#include "ventanalistamundo.h"
#include "arbolvida.h"
#include "listamundo.h"
#include "hilocrearhumanos.h"
#include "paraiso.h"
#include "creartreewidgetitem.h"
//#include "arbolapellidos.h"

namespace Ui {
class VentanaNacimiento;
}

class VentanaNacimiento : public QMainWindow
{
    Q_OBJECT

public:
    explicit VentanaNacimiento(QWidget *parent = 0,QString * apellidos=0,QString* nombres=0,QString*paises=0,
     QString* creencias=0,QString* profesiones=0,QString* nombrePecado=0,ListaMundo* listaMundo=0,
                               ArbolVida* arbolVida=0,Paraiso* paraiso =0);
    ~VentanaNacimiento();

public:
    Ui::VentanaNacimiento *ui;
    QString* apellidos;
    QString* nombres;
    QString* paises;
    QString* creencias;
    QString* profesiones;
    QString* nombrePecado;
    ListaMundo* listaMundo;
    VentanaListaMundo* ventanaHumanos;
    HiloCrearHumanos* hiloCrearHumanos;
    ArbolVida* arbolVida;
    Paraiso* paraiso;

    //ArbolApellidos** arbolesApellidos;

public slots:
    void on_aceptar_clicked();
    void on_botonHumanos_clicked();
    void actualizarVentana();

private slots:
    void on_botonMundo_clicked();
    void on_botonApellidos_clicked();
    void on_cBoxApellidos_currentIndexChanged(int index);
};

#endif // VENTANANACIMIENTO_H

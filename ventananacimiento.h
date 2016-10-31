#ifndef VENTANANACIMIENTO_H
#define VENTANANACIMIENTO_H

#include <QMainWindow>
#include "ventanalistamundo.h"
#include "listamundo.h"
#include "hilocrearhumanos.h"
//#include "arbolapellidos.h"

namespace Ui {
class VentanaNacimiento;
}

class VentanaNacimiento : public QMainWindow
{
    Q_OBJECT

public:
    explicit VentanaNacimiento(QWidget *parent = 0,QString * apellidos=0,QString* nombres=0,QString*paises=0,
     QString* creencias=0,QString* profesiones=0,QString* nombrePecado=0,ListaMundo* listaMundo=0/*,
                               ArbolApellidos** arbolesApellidos=0*/);
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
    //ArbolApellidos** arbolesApellidos;

public slots:
    void on_aceptar_clicked();
    void on_botonHumanos_clicked();
    void actualizarVentana();

};

#endif // VENTANANACIMIENTO_H

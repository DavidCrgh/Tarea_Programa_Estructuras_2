#ifndef VENTANACONSULTAAPELLIDO_H
#define VENTANACONSULTAAPELLIDO_H

#include <QMainWindow>
#include "listamundo.h"
#include "paraiso.h"
#include "infierno.h"

namespace Ui {
class VentanaConsultaApellido;
}

class VentanaConsultaApellido : public QMainWindow
{
    Q_OBJECT

public:
    explicit VentanaConsultaApellido(QWidget *parent = 0,QString* apellidos=0,QString* paises=0,
            ListaMundo* listaMundo=0,Paraiso* paraiso=0,Infierno* infierno=0);
    ~VentanaConsultaApellido();

public:
    Ui::VentanaConsultaApellido *ui;
    QString* apellidos;
    QString* paises;
    ListaMundo* listaMundo;
    Paraiso* paraiso;
    Infierno* infierno;
private slots:

    void on_aceptar_clicked();
};

#endif // VENTANACONSULTAAPELLIDO_H

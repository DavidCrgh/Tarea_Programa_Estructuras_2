#ifndef VENTANACONSULTAAPELLIDO_H
#define VENTANACONSULTAAPELLIDO_H

#include <QMainWindow>

namespace Ui {
class VentanaConsultaApellido;
}

class VentanaConsultaApellido : public QMainWindow
{
    Q_OBJECT

public:
    explicit VentanaConsultaApellido(QWidget *parent = 0,QString* apellidos=0,QString* paises=0);
    ~VentanaConsultaApellido();

public:
    Ui::VentanaConsultaApellido *ui;
    QString* apellidos;
    QString* paises;
};

#endif // VENTANACONSULTAAPELLIDO_H

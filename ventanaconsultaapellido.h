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
    explicit VentanaConsultaApellido(QWidget *parent = 0);
    ~VentanaConsultaApellido();

private:
    Ui::VentanaConsultaApellido *ui;
};

#endif // VENTANACONSULTAAPELLIDO_H

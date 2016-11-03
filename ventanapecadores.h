#ifndef VENTANAPECADORES_H
#define VENTANAPECADORES_H

#include <QMainWindow>

namespace Ui {
class VentanaPecadores;
}

class VentanaPecadores : public QMainWindow
{
    Q_OBJECT

public:
    explicit VentanaPecadores(QWidget *parent = 0,QString* paises=0,QString* apellidos=0,QString* creencias=0,
                              QString* profesiones=0);
    ~VentanaPecadores();

public:
    Ui::VentanaPecadores *ui;
    QString* paises;
    QString* apellidos;
    QString* creencias;
    QString* profesiones;
};

#endif // VENTANAPECADORES_H

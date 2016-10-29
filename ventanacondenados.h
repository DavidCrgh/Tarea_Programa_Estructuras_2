#ifndef VENTANACONDENADOS_H
#define VENTANACONDENADOS_H

#include <QMainWindow>
#include "infierno.h"

namespace Ui {
class VentanaCondenados;
}

class VentanaCondenados : public QMainWindow
{
    Q_OBJECT

public:
    explicit VentanaCondenados(QWidget *parent = 0,Infierno* infierno=0,QString* nombrePecados=0);
    ~VentanaCondenados();

private slots:
    void on_actualizar_clicked();

public:
    Ui::VentanaCondenados *ui;
    Infierno* infierno;
    QString* nombrePecados;
};

#endif // VENTANACONDENADOS_H

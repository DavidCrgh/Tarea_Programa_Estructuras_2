#ifndef VENTANAARBOLVIDA_H
#define VENTANAARBOLVIDA_H

#include <QMainWindow>
#include "hiloarbolvida.h"
#include "arbolvida.h"

namespace Ui {
class VentanaArbolVida;
}

class VentanaArbolVida : public QMainWindow
{
    Q_OBJECT

public:
    explicit VentanaArbolVida(QWidget *parent = 0,HiloArbolVida* hiloArbolVida=0,ArbolVida* arbolVida=0);
    ~VentanaArbolVida();

public:
    Ui::VentanaArbolVida *ui;
    HiloArbolVida* hiloArbolVida;
    ArbolVida* arbolVida;
private slots:
    void on_aceptar_clicked();
    void on_detener_clicked();


    void on_pushButton_clicked();
};

#endif // VENTANAARBOLVIDA_H

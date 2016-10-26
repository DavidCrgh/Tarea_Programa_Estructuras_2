#ifndef VENTANATOP10PECADORES_H
#define VENTANATOP10PECADORES_H

#include <QMainWindow>
#include "listamundo.h"

namespace Ui {
class VentanaTop10Pecadores;
}

class VentanaTop10Pecadores : public QMainWindow
{
    Q_OBJECT

public:
    explicit VentanaTop10Pecadores(QWidget *parent = 0,ListaMundo* listaMundo=0,QString* paises=0);
    ~VentanaTop10Pecadores();

public:
    Ui::VentanaTop10Pecadores *ui;
    ListaMundo* listaMundo;
    QString* paises;
private slots:
    void on_actualizar_clicked();
};

#endif // VENTANATOP10PECADORES_H

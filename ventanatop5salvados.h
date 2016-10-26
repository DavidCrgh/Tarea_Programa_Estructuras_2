#ifndef VENTANATOP5SALVADOS_H
#define VENTANATOP5SALVADOS_H

#include <QMainWindow>
#include "listamundo.h"

namespace Ui {
class VentanaTop5Salvados;
}

class VentanaTop5Salvados : public QMainWindow
{
    Q_OBJECT

public:
    explicit VentanaTop5Salvados(QWidget *parent = 0,ListaMundo* listaMundo=0,QString* paises=0);
    ~VentanaTop5Salvados();

public:
    Ui::VentanaTop5Salvados *ui;
    ListaMundo* listaMundo;
    QString* paises;
private slots:
    void on_actualizar_clicked();
};

#endif // VENTANATOP5SALVADOS_H

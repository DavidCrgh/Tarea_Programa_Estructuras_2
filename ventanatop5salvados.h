#ifndef VENTANATOP5SALVADOS_H
#define VENTANATOP5SALVADOS_H

#include <QMainWindow>

namespace Ui {
class VentanaTop5Salvados;
}

class VentanaTop5Salvados : public QMainWindow
{
    Q_OBJECT

public:
    explicit VentanaTop5Salvados(QWidget *parent = 0);
    ~VentanaTop5Salvados();

private:
    Ui::VentanaTop5Salvados *ui;
};

#endif // VENTANATOP5SALVADOS_H

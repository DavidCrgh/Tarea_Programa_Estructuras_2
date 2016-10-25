#ifndef VENTANATOP10PECADORES_H
#define VENTANATOP10PECADORES_H

#include <QMainWindow>

namespace Ui {
class VentanaTop10Pecadores;
}

class VentanaTop10Pecadores : public QMainWindow
{
    Q_OBJECT

public:
    explicit VentanaTop10Pecadores(QWidget *parent = 0);
    ~VentanaTop10Pecadores();

private:
    Ui::VentanaTop10Pecadores *ui;
};

#endif // VENTANATOP10PECADORES_H

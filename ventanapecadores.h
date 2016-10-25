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
    explicit VentanaPecadores(QWidget *parent = 0);
    ~VentanaPecadores();

private:
    Ui::VentanaPecadores *ui;
};

#endif // VENTANAPECADORES_H

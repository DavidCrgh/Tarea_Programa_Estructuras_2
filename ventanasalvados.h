#ifndef VENTANASALVADOS_H
#define VENTANASALVADOS_H

#include <QMainWindow>

namespace Ui {
class VentanaSalvados;
}

class VentanaSalvados : public QMainWindow
{
    Q_OBJECT

public:
    explicit VentanaSalvados(QWidget *parent = 0);
    ~VentanaSalvados();

private:
    Ui::VentanaSalvados *ui;
};

#endif // VENTANASALVADOS_H

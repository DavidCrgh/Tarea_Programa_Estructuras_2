#ifndef VENTANACONDENADOS_H
#define VENTANACONDENADOS_H

#include <QMainWindow>

namespace Ui {
class VentanaCondenados;
}

class VentanaCondenados : public QMainWindow
{
    Q_OBJECT

public:
    explicit VentanaCondenados(QWidget *parent = 0);
    ~VentanaCondenados();

private:
    Ui::VentanaCondenados *ui;
};

#endif // VENTANACONDENADOS_H

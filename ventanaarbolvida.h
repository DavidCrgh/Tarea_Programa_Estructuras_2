#ifndef VENTANAARBOLVIDA_H
#define VENTANAARBOLVIDA_H

#include <QMainWindow>

namespace Ui {
class VentanaArbolVida;
}

class VentanaArbolVida : public QMainWindow
{
    Q_OBJECT

public:
    explicit VentanaArbolVida(QWidget *parent = 0);
    ~VentanaArbolVida();

private:
    Ui::VentanaArbolVida *ui;
};

#endif // VENTANAARBOLVIDA_H

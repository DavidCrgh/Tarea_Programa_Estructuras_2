#ifndef VENTANAERROR_H
#define VENTANAERROR_H

#include <QMainWindow>

namespace Ui {
class VentanaError;
}

class VentanaError : public QMainWindow
{
    Q_OBJECT

public:
    explicit VentanaError(QWidget *parent = 0);
    ~VentanaError();

private slots:
    void on_aceptar_clicked();

private:
    Ui::VentanaError *ui;
};

#endif // VENTANAERROR_H

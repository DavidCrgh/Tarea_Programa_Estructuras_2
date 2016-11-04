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
    explicit VentanaPecadores(QWidget *parent = 0,QString* paises=0,QString* apellidos=0,QString* creencias=0,
                              QString* profesiones=0);
    ~VentanaPecadores();

public:
    Ui::VentanaPecadores *ui;
    QString* paises;
    QString* apellidos;
    QString* creencias;
    QString* profesiones;
private slots:
    void on_botonContinentes_clicked(bool checked);
    void on_botonApellidos_clicked(bool checked);
    void on_botonPaises_clicked(bool checked);
    void on_botonCreencias_clicked(bool checked);
    void on_botonProfesiones_clicked(bool checked);
};

#endif // VENTANAPECADORES_H

#ifndef VENTANAPRINCIPAL_H
#define VENTANAPRINCIPAL_H

#include <QMainWindow>
#include "ventanamundo.h"
#include "listamundo.h"


namespace Ui {
class VentanaPrincipal;
}

class VentanaPrincipal : public QMainWindow
{
    Q_OBJECT

public:
    explicit VentanaPrincipal(QWidget *parent = 0,QString*apellidos=0,QString*nombres=0,
    QString* paises=0, QString*creencias=0, QString*profesiones=0,QString* nombrePecado=0,
    ListaMundo*listaMundo=0,ArbolApellidos** arbolesApellidos=0);
    ~VentanaPrincipal();

private slots:
    void on_pushButton_clicked();

public:
    Ui::VentanaPrincipal *ui;
    QString*apellidos;
    QString*nombres;
    QString* paises;
    QString*creencias;
    QString*profesiones;
    QString* nombrePecado;
    ListaMundo* listaMundo;
    VentanaMundo* ventanaMundo;
    ArbolApellidos** arbolesApellidos;

};

#endif // VENTANAPRINCIPAL_H

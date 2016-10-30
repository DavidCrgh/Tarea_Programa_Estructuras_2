#ifndef VENTANACONDENARPAIS_H
#define VENTANACONDENARPAIS_H

#include <QMainWindow>
#include "infierno.h"
#include "listamundo.h"
#include "ventanaerror.h"



namespace Ui {
class VentanaCondenarPais;
}

class VentanaCondenarPais : public QMainWindow
{
    Q_OBJECT

public:
    explicit VentanaCondenarPais(QWidget *parent = 0, Infierno* infierno=0,ListaMundo* listaMundo=0,QString* paises=0);
    ~VentanaCondenarPais();

public:
    Ui::VentanaCondenarPais *ui;
    QString* paises;
    Infierno* infierno;
    ListaMundo* listaMundo;
    VentanaError* ventanaError;
private slots:
    void on_aceptar_clicked();
};

#endif // VENTANACONDENARPAIS_H

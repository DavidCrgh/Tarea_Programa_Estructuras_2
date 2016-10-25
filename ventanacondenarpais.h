#ifndef VENTANACONDENARPAIS_H
#define VENTANACONDENARPAIS_H

#include <QMainWindow>

namespace Ui {
class VentanaCondenarPais;
}

class VentanaCondenarPais : public QMainWindow
{
    Q_OBJECT

public:
    explicit VentanaCondenarPais(QWidget *parent = 0,QString* paises=0);
    ~VentanaCondenarPais();

public:
    Ui::VentanaCondenarPais *ui;
    QString* paises;
};

#endif // VENTANACONDENARPAIS_H

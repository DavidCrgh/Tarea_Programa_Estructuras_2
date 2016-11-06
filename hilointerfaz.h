#ifndef HILOINTERFAZ_H
#define HILOINTERFAZ_H

#include <QtCore>
#include "ventanaprincipal.h"

class HiloInterfaz : public QThread
{
        Q_OBJECT
public:
    HiloInterfaz(QObject* parent=0,VentanaPrincipal* ventanaPrincipal=0);
    VentanaPrincipal* ventanaPrincipal;
    bool stop;
    bool pause;
    void run();

signals:
    void actualizarVentanaNacimiento();
    void actualizarVentanaHumanos();
    void actualizarVentanaPecadores();
};

#endif // HILOINTERFAZ_H

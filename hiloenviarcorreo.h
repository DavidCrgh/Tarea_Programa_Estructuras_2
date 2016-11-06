#ifndef HILOENVIARCORREO_H
#define HILOENVIARCORREO_H
#include "windows.h"
#include <QtCore>
#include <QMutex>

class HiloEnviarCorreo : public QThread
{
    Q_OBJECT
public:
    HiloEnviarCorreo();
    const char* ejecucion;
    bool stop;
    bool pause;
    void run();
    QMutex mute;
};

#endif // HILOENVIARCORREO_H

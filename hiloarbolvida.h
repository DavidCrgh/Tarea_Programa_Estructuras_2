#ifndef HILOARBOLVIDA_H
#define HILOARBOLVIDA_H
#include <QtCore>
#include "math.h"
#include "arbolvida.h"
#include "paraiso.h"
#include "infierno.h"
#include "hiloenviarcorreo.h"

class HiloArbolVida : public QThread
{
    Q_OBJECT
public:
    HiloArbolVida(QObject* parent = 0, ArbolVida* arbolVida = 0, ListaMundo* mundo = 0,
                  Infierno* Infierno = 0, Paraiso* paraiso = 0);
    ArbolVida* arbolVida;
    Paraiso* paraiso;
    ListaMundo* mundo;
    Infierno* infierno;
    bool stop;
    bool pause;
    int tiempo;
    void run();

};

#endif // HILOARBOLVIDA_H

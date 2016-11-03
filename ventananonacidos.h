#ifndef VENTANANONACIDOS_H
#define VENTANANONACIDOS_H

#include <QMainWindow>
#include "listamundo.h"
#include "paraiso.h"
#include "infierno.h"
#include "arbolvida.h"
#include "generarnonacidos.h"

namespace Ui {
class VentanaNoNacidos;
}

class VentanaNoNacidos : public QMainWindow
{
    Q_OBJECT

public:
    ListaMundo* mundo;
    Infierno* infierno;
    Paraiso* paraiso;
    ArbolVida* arbolVida;
    explicit VentanaNoNacidos(QWidget *parent = 0, ListaMundo* pMundo = 0,
                              Infierno* pInfierno = 0, Paraiso* pParaiso = 0, ArbolVida* pArbolVida = 0);
    ~VentanaNoNacidos();

private slots:
    void on_botonActualizar_clicked();

private:
    Ui::VentanaNoNacidos *ui;
};

#endif // VENTANANONACIDOS_H

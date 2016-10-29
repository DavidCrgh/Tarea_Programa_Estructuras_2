#ifndef VENTANAMUNDO_H
#define VENTANAMUNDO_H

#include <QDebug>
#include "listamundo.h"
#include "ventanaarbolvida.h"
#include "ventanacondenados.h"
#include "ventanacondenarpais.h"
#include "ventanaconsultaapellido.h"
#include "ventanaconsultasfamilia.h"
#include "ventanacontinentes.h"
#include "ventanamundo.h"
#include "ventananacimiento.h"
#include "ventanapecadores.h"
#include "ventanasalvados.h"
#include "ventanatop10pecadores.h"
#include "ventanatop5salvados.h"
#include "arbolapellidos.h"
#include "infierno.h"

#include <QWidget>

namespace Ui {
class VentanaMundo;
}

class VentanaMundo : public QWidget
{
    Q_OBJECT

public:
    explicit VentanaMundo(QWidget *parent = 0,QString*apellidos=0,QString*nombres=0,
     QString* paises=0, QString*creencias=0, QString*profesiones=0,QString*nombrePecado=0,
     ListaMundo*listaMundo=0,ArbolApellidos** arbolesApellidos=0);//, ArbolApellidos* pArbolesApellidos[] = 0);
    ~VentanaMundo();

private slots:
    void on_botonArbol_clicked();

    void on_botonSalvados_clicked();

    void on_botonNacimiento_clicked();

    void on_botonPecar_clicked();

    void on_botonFamilia_clicked();

    void on_botonTop10_clicked();

    void on_botonTop5_clicked();

    void on_botonMapa_clicked();

    void on_botonPecadores_clicked();

    void on_botonApellido_clicked();

    void on_botonCondenar_clicked();

    void on_botonCondenados_clicked();

public:
    Ui::VentanaMundo *ui;
    QString*apellidos;
    QString*nombres;
    QString* paises;
    QString*creencias;
    QString*profesiones;
    QString* nombrePecado;
    ListaMundo* listaMundo;
    ArbolApellidos** arbolesApellidos;
    Infierno* infierno;

    VentanaArbolVida* ventanaArbolVida;
    VentanaSalvados* ventanaSalvados;
    VentanaNacimiento* ventanaNacimiento;
    VentanaConsultasFamilia* ventanaConsultasFamilia;
    VentanaTop10Pecadores* ventanaTop10;
    VentanaTop5Salvados* ventanaTop5;
    VentanaContinentes* ventanaContinentes;
    VentanaPecadores* ventanaPecadores;
    VentanaConsultaApellido* ventanaConsultaApellido;
    VentanaCondenarPais* ventanaCondenarPais;
    VentanaCondenados* ventanaCondenados;
};

#endif // VENTANAMUNDO_H

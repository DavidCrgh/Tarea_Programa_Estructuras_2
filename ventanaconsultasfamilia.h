#ifndef VENTANACONSULTASFAMILIA_H
#define VENTANACONSULTASFAMILIA_H

#include <QMainWindow>
#include "listamundo.h"

namespace Ui {
class VentanaConsultasFamilia;
}

class VentanaConsultasFamilia : public QMainWindow
{
    Q_OBJECT

public:
    explicit VentanaConsultasFamilia(QWidget *parent = 0,ListaMundo* listaMundo=0);
    ~VentanaConsultasFamilia();

public:
    Ui::VentanaConsultasFamilia *ui;
    ListaMundo* listaMundo;
private slots:
    void on_aceptar_clicked();
};

#endif // VENTANACONSULTASFAMILIA_H

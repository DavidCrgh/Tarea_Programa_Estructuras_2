#ifndef VENTANASALVADOS_H
#define VENTANASALVADOS_H

#include <QMainWindow>
#include "paraiso.h"

namespace Ui {
class VentanaSalvados;
}

class VentanaSalvados : public QMainWindow
{
    Q_OBJECT

public:
    explicit VentanaSalvados(QWidget *parent = 0, Paraiso* pParaiso = 0, QString* nombrePecados=0);
    ~VentanaSalvados();

public slots:
    void on_actualizar_clicked();

private:
    Ui::VentanaSalvados *ui;
    Paraiso* paraiso;
    QString* nombrePecados;
};

#endif // VENTANASALVADOS_H

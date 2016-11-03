#ifndef VENTANACONTINENTES_H
#define VENTANACONTINENTES_H

#include <QMainWindow>
#include "listamundo.h"

namespace Ui {
class VentanaContinentes;
}

class VentanaContinentes : public QMainWindow
{
    Q_OBJECT

public:
    explicit VentanaContinentes(QWidget *parent = 0,ListaMundo* listaMundo=0);
    ~VentanaContinentes();

private slots:
    void on_pushButton_clicked();

public:
    Ui::VentanaContinentes *ui;
    ListaMundo* listaMundo;
    QString colores[5][5];
};

#endif // VENTANACONTINENTES_H

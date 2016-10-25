#ifndef VENTANALISTAMUNDO_H
#define VENTANALISTAMUNDO_H

#include <QMainWindow>
#include "listamundo.h"

namespace Ui {
class VentanaListaMundo;
}

class VentanaListaMundo : public QMainWindow
{
    Q_OBJECT

public:
    explicit VentanaListaMundo(QWidget *parent = 0, QString* nombrePecado=0, ListaMundo* listaMundo=0);
    ~VentanaListaMundo();

public:
    Ui::VentanaListaMundo *ui;
    QString* nombrePecado;
    ListaMundo * listaMundo;

private slots:
    void on_actualizar_clicked();
};

#endif // VENTANALISTAMUNDO_H

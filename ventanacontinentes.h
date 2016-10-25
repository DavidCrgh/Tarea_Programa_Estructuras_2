#ifndef VENTANACONTINENTES_H
#define VENTANACONTINENTES_H

#include <QMainWindow>

namespace Ui {
class VentanaContinentes;
}

class VentanaContinentes : public QMainWindow
{
    Q_OBJECT

public:
    explicit VentanaContinentes(QWidget *parent = 0);
    ~VentanaContinentes();

private:
    Ui::VentanaContinentes *ui;
};

#endif // VENTANACONTINENTES_H

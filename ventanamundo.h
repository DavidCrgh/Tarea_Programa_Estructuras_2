#ifndef VENTANAMUNDO_H
#define VENTANAMUNDO_H

#include <QWidget>

namespace Ui {
class VentanaMundo;
}

class VentanaMundo : public QWidget
{
    Q_OBJECT

public:
    explicit VentanaMundo(QWidget *parent = 0);
    ~VentanaMundo();

private:
    Ui::VentanaMundo *ui;
};

#endif // VENTANAMUNDO_H

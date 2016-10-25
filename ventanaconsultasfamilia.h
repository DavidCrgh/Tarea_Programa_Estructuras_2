#ifndef VENTANACONSULTASFAMILIA_H
#define VENTANACONSULTASFAMILIA_H

#include <QMainWindow>

namespace Ui {
class VentanaConsultasFamilia;
}

class VentanaConsultasFamilia : public QMainWindow
{
    Q_OBJECT

public:
    explicit VentanaConsultasFamilia(QWidget *parent = 0);
    ~VentanaConsultasFamilia();

private:
    Ui::VentanaConsultasFamilia *ui;
};

#endif // VENTANACONSULTASFAMILIA_H

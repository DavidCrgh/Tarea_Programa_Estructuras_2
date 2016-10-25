#include "ventanacontinentes.h"
#include "ui_ventanacontinentes.h"

VentanaContinentes::VentanaContinentes(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VentanaContinentes)
{
    ui->setupUi(this);
}

VentanaContinentes::~VentanaContinentes()
{
    delete ui;
}

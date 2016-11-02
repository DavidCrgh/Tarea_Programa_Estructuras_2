#include "ventanaarbolvida.h"
#include "ui_ventanaarbolvida.h"

VentanaArbolVida::VentanaArbolVida(QWidget *parent,HiloArbolVida* pHiloArbolVida,ArbolVida* pArbolVida) :
    QMainWindow(parent),
    ui(new Ui::VentanaArbolVida)
{
    ui->setupUi(this);
    hiloArbolVida=pHiloArbolVida;
    arbolVida= pArbolVida;
    ui->tiempoArbol->setRange(1,1000);
}

VentanaArbolVida::~VentanaArbolVida()
{
    delete ui;
}

void agregarHijos(QTreeWidgetItem* item, NodoVida* raiz){
    if(raiz != NULL){
        if(raiz->derecha != NULL){
            QStringList lista;
            lista.append(QString::number(raiz->derecha->id));
            QTreeWidgetItem* hijo = new QTreeWidgetItem(lista,0);
            item->addChild(hijo);
            agregarHijos(hijo, raiz->derecha);
        }
        if(raiz->izquierda != NULL){
            QStringList lista;
            lista.append(QString::number(raiz->izquierda->id));
            QTreeWidgetItem* hijo = new QTreeWidgetItem(lista,0);
            item->addChild(hijo);
            agregarHijos(hijo, raiz->izquierda);
        }
    }
}

QTreeWidgetItem* crearTreeWidgetItem(ArbolVida* arbolVida){
    QStringList lista;
    lista.append(QString::number(arbolVida->raiz->id));
    QTreeWidgetItem* raiz = new QTreeWidgetItem(lista,0);
    agregarHijos(raiz,arbolVida->raiz);
    return raiz;
}

void VentanaArbolVida::on_aceptar_clicked()
{
    int tiempoArbol= ui->tiempoArbol->value();

    hiloArbolVida->tiempo=tiempoArbol;

    hiloArbolVida->pause=false;


}

void VentanaArbolVida::on_detener_clicked()
{
    hiloArbolVida->pause=true;
}


void VentanaArbolVida::on_pushButton_clicked()
{
    ui->treeWidget->clear();
    if(arbolVida->raiz != NULL){
    ui->treeWidget->addTopLevelItem(crearTreeWidgetItem(arbolVida));
    }
}

void VentanaArbolVida::on_pushButton_2_clicked()
{
    arbolVida->limpiarArbol();
}

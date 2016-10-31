#include "ventanacondenados.h"
#include "ui_ventanacondenados.h"

VentanaCondenados::VentanaCondenados(QWidget *parent, Infierno* pInfierno,QString* pNombrePecados) :
    QMainWindow(parent),
    ui(new Ui::VentanaCondenados)
{
    ui->setupUi(this);
    infierno=pInfierno;
    nombrePecados=pNombrePecados;
}

VentanaCondenados::~VentanaCondenados()
{
    delete ui;
}

void agregarHijos(QTreeWidgetItem* item, NodoArbolSplay* raiz){
    if(raiz != NULL){
        if(raiz->derecha != NULL){
            QStringList lista;
            lista.append(QString::number(raiz->derecha->id));
            lista.append(raiz->derecha->humano->pais);
            QTreeWidgetItem* hijo = new QTreeWidgetItem(lista,0);
            item->addChild(hijo);
            agregarHijos(hijo, raiz->derecha);
        }
        if(raiz->izquierda != NULL){
            QStringList lista;
            lista.append(QString::number(raiz->izquierda->id));
            lista.append(raiz->izquierda->humano->pais);
            QTreeWidgetItem* hijo = new QTreeWidgetItem(lista,0);
            item->addChild(hijo);
            agregarHijos(hijo, raiz->izquierda);
        }
    }
}

QTreeWidgetItem* crearTreeWidgetItem(ArbolSplay* infierno){
    QStringList lista;
    lista.append(QString::number(infierno->raiz->id));
    lista.append(infierno->raiz->humano->pais);
    QTreeWidgetItem* raiz = new QTreeWidgetItem(lista,0);
    agregarHijos(raiz,infierno->raiz);
    return raiz;
}

void VentanaCondenados::on_actualizar_clicked()
{
   ui->informacionCondenados->setText(infierno->listaCondenados->listaCondenadosSalvadosOrdenada(true));
   if(infierno->arbolInfierno->raiz != NULL){
       ui->arbolSplay->clear();
       ui->arbolSplay->addTopLevelItem(crearTreeWidgetItem(infierno->arbolInfierno));
   }
}

#include "ventanasalvados.h"
#include "ui_ventanasalvados.h"

VentanaSalvados::VentanaSalvados(QWidget *parent, Paraiso* pParaiso, QString* pNombrePecados) :
    QMainWindow(parent),
    ui(new Ui::VentanaSalvados)
{
    ui->setupUi(this);
    paraiso = pParaiso;
    nombrePecados = pNombrePecados;
}

VentanaSalvados::~VentanaSalvados()
{
    delete ui;
}

void agregarHijos(QTreeWidgetItem* item, NodoArbolAvl* raiz){
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

QTreeWidgetItem* crearTreeWidgetItem(ArbolAvl* paraiso){
    QStringList lista;
    lista.append(QString::number(paraiso->raiz->id));
    lista.append(paraiso->raiz->humano->pais);
    QTreeWidgetItem* raiz = new QTreeWidgetItem(lista,0);
    agregarHijos(raiz,paraiso->raiz);
    return raiz;
}

void VentanaSalvados::on_actualizar_clicked()
{
   ui->informacionSalvados->setText(paraiso->listaParaiso->listaCondenadosSalvadosOrdenada(false));
   if(paraiso->arbolParaiso->raiz != NULL){
       ui->arbolAVL->clear();
       ui->arbolAVL->addTopLevelItem(crearTreeWidgetItem(paraiso->arbolParaiso));
   }
}

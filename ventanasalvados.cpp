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

void agregarHijos(QTreeWidgetItem* item, node* raiz){
    if(raiz != NULL){
        if(raiz->right != NULL){
            QStringList lista;
            lista.append(QString::number(raiz->right->humano->id));
            lista.append(raiz->right->humano->pais);
            QTreeWidgetItem* hijo = new QTreeWidgetItem(lista,0);
            item->addChild(hijo);
            agregarHijos(hijo, raiz->right);
        }
        if(raiz->left != NULL){
            QStringList lista;
            lista.append(QString::number(raiz->left->humano->id));
            lista.append(raiz->left->humano->pais);
            QTreeWidgetItem* hijo = new QTreeWidgetItem(lista,0);
            item->addChild(hijo);
            agregarHijos(hijo, raiz->left);
        }
    }
}

QTreeWidgetItem* crearTreeWidgetItem(node* paraiso){
    QStringList lista;
    lista.append(QString::number(paraiso->humano->id));
    lista.append(paraiso->humano->pais);
    QTreeWidgetItem* raiz = new QTreeWidgetItem(lista,0);
    agregarHijos(raiz,paraiso);
    return raiz;
}

void VentanaSalvados::on_actualizar_clicked()
{
   ui->informacionSalvados->setText(paraiso->listaParaiso->listaCondenadosSalvadosOrdenada(false));
   if(paraiso->arbolParaiso != NULL){
       ui->arbolAVL->clear();
       ui->arbolAVL->addTopLevelItem(crearTreeWidgetItem(paraiso->arbolParaiso));
   }
}

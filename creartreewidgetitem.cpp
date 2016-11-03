#include "creartreewidgetitem.h"

void agregarHijos(QTreeWidgetItem* item, node* raiz){
    if(raiz != NULL){
        if(raiz->right != NULL){
            QStringList lista;
            lista.append(QString::number(raiz->right->humano->id));
            lista.append(raiz->right->humano->apellido);
            lista.append(raiz->right->humano->nombre);
            lista.append(raiz->right->humano->pais);
            QTreeWidgetItem* hijo = new QTreeWidgetItem(lista,0);
            item->addChild(hijo);
            agregarHijos(hijo, raiz->right);
        }
        if(raiz->left != NULL){
            QStringList lista;
            lista.append(QString::number(raiz->left->humano->id));
            lista.append(raiz->left->humano->apellido);
            lista.append(raiz->left->humano->nombre);
            lista.append(raiz->left->humano->pais);
            QTreeWidgetItem* hijo = new QTreeWidgetItem(lista,0);
            item->addChild(hijo);
            agregarHijos(hijo, raiz->left);
        }
    }
}

QTreeWidgetItem* crearTreeWidgetItem(node* raiz){
    QStringList lista;
    lista.append(QString::number(raiz->humano->id));
    lista.append(raiz->humano->apellido);
    lista.append(raiz->humano->nombre);
    lista.append(raiz->humano->pais);
    QTreeWidgetItem* qTreeWidgetItem = new QTreeWidgetItem(lista,0);
    agregarHijos(qTreeWidgetItem,raiz);
    return qTreeWidgetItem;
}

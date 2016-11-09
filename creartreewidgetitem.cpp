#include "creartreewidgetitem.h"

/*
 * Entradas: QTreeWidgetItem y el nodo AVL que está representando
 * Salidas: Ninguna
 *
 * Funcion recursiva que le agrega hijos a un modelo de jerarquia de arbol
 * nativo a Qt a partir de un arbol AVL.
 */
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

/*
 * Entradas: nodo raiz del arbol AVL que se va a modelar
 * Salidas: modelo de jerarquia de arbol creado a partir del AVL
 * ingresado
 *
 * Crea un QTreeWidget item a partir del nodo raiz del arbol AVL
 * ingresado y luego llama a la funcion agregarHijos para bajar
 * en el arbol y asignarle sus hijos.
 * Una vez completada la recursividad retorna el QTreeWidget item de
 * mas alto nivel.
 */
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

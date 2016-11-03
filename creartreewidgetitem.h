#ifndef CREARTREEWIDGETITEM_H
#define CREARTREEWIDGETITEM_H
#include <QtCore>
#include <QMainWindow>
#include <QTreeWidgetItem>
#include "paraiso.h"

void agregarHijos(QTreeWidgetItem* item, node* raiz);
QTreeWidgetItem* crearTreeWidgetItem(node* paraiso);

#endif // CREARTREEWIDGETITEM_H

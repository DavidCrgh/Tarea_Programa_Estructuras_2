#ifndef GLOBALES_H
#define GLOBALES_H
#include <QFile>
#include <QTextStream>
#include <QDebug>
//#include "arbolapellidos.h"
/*
#include <QDebug>
#include "ventanaarbolvida.h"
#include "ventanacondenados.h"
#include "ventanacondenarpais.h"
#include "ventanaconsultaapellido.h"
#include "ventanaconsultasfamilia.h"
#include "ventanacontinentes.h"
#include "ventanamundo.h"
#include "ventananacimiento.h"
#include "ventanapecadores.h"
#include "ventanasalvados.h"
#include "ventanatop10pecadores.h"
#include "ventanatop5salvados.h"
*/

QString* cargarApellidos();
QString* cargarNombres();
QString* cargarPaises();
QString* cargarCreencias();
QString* cargarProfesiones();
QString* cargarPecados();
QString* cargarContinentes();
//ArbolApellidos** popularArbolesApellido();

#endif // GLOBALES_H

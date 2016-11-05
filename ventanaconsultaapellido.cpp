#include "ventanaconsultaapellido.h"
#include "ui_ventanaconsultaapellido.h"
#include "cstdlib"
#include <iostream>
using namespace std;

VentanaConsultaApellido::VentanaConsultaApellido(QWidget *parent, QString*pPaises, QString*pApellidos,
                                                 ListaMundo* pListaMundo,Paraiso* pParaiso,Infierno*pInfierno) :
    QMainWindow(parent),
    ui(new Ui::VentanaConsultaApellido)
{
    ui->setupUi(this);
    paises=pPaises;
    apellidos=pApellidos;
    listaMundo= pListaMundo;
    paraiso=pParaiso;
    infierno=pInfierno;

    QStringList listaPaises;
    QStringList listaApellidos;

    for(int i=0;i<242;i++)
        listaPaises.append(paises[i]);
    for(int i=0;i<1000;i++)
        listaApellidos.append(apellidos[i]);

    ui->cajaPaises->addItems(listaPaises);
    ui->cajaApellidos->addItems(listaApellidos);

}

VentanaConsultaApellido::~VentanaConsultaApellido()
{
    delete ui;
}



void VentanaConsultaApellido::on_aceptar_clicked()
{
    QString apellido=ui->cajaApellidos->currentText();
    QString pais= ui->cajaPaises->currentText();
    QString filtrado;

    std::vector<NodoHumano*> filtroMundo= listaMundo->filtroApellidoPais(apellido,pais);
    std::vector<NodoHumano*> filtroInfierno= infierno->listaCondenados->filtroApellidoPais(apellido,pais);
    std::vector<NodoHumano*> filtroParaiso= paraiso->listaParaiso->filtroApellidoPais(apellido,pais);

    cout<<"Filtro Mundo:"<<" "<<filtroMundo.size()<<endl;
    cout<<"Filtro Infierno:"<<" "<<filtroInfierno.size()<<endl;
    cout<<"Filtro Paraiso:"<<" "<<filtroParaiso.size()<<endl;

    filtroMundo.insert(filtroMundo.end(),filtroInfierno.begin(),filtroInfierno.end());
    filtroMundo.insert(filtroMundo.end(),filtroParaiso.begin(),filtroParaiso.end());

    cout<<"Filtro Mundo Total:"<<" "<<filtroMundo.size()<<endl;
    filtroMundo=ordenarPecadores(filtroMundo,filtroMundo.size());
    if(filtroMundo.size()!=0){
        for(int i=0;i<filtroMundo.size();i++)
            filtrado+=imprimirHumano(filtroMundo[i]);
        ui->informacionFiltrados->setText(filtrado);

    }
    else
        ui->informacionFiltrados->setText("Su búsqueda no produjo resultados");

}

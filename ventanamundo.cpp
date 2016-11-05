#include "ventanamundo.h"
#include "ui_ventanamundo.h"

VentanaMundo::VentanaMundo(QWidget *parent,QString* pApellidos,QString* pNombres,QString* pPaises,
                           QString* pCreencias, QString* pProfesiones,QString* pNombrePecado,
                           ListaMundo* pListaMundo,QString* pContinentes/*,ArbolApellidos ** pArbolesApellidos*/):
    QWidget(parent),
    ui(new Ui::VentanaMundo)
{
    ui->setupUi(this);
    apellidos = pApellidos;
    nombres = pNombres;
    paises = pPaises;
    creencias = pCreencias;
    profesiones = pProfesiones;
    nombrePecado = pNombrePecado;
    listaMundo = pListaMundo;
    continentes=pContinentes;
    infierno = new Infierno();
    paraiso = new Paraiso();
    arbolVida = new ArbolVida();
    hiloArbolVida = new HiloArbolVida(NULL,arbolVida,listaMundo,infierno,paraiso);
    hiloArbolVida->start();

    ventanaArbolVida = new VentanaArbolVida(NULL,hiloArbolVida,arbolVida);
    ventanaSalvados = new VentanaSalvados(NULL, paraiso,nombrePecado);
    ventanaNacimiento = new VentanaNacimiento(NULL,apellidos,nombres,paises,creencias,profesiones,
                                             nombrePecado,listaMundo,arbolVida,paraiso,continentes);
    ventanaConsultasFamilia = new VentanaConsultasFamilia(NULL,listaMundo);
    ventanaTop10 = new VentanaTop10Pecadores(NULL,listaMundo,paises);
    ventanaTop5 = new VentanaTop5Salvados(NULL,listaMundo,paises);
    ventanaContinentes = new VentanaContinentes(NULL,listaMundo);
    ventanaPecadores = new VentanaPecadores(NULL,paises,apellidos,creencias,profesiones);
    ventanaConsultaApellido = new VentanaConsultaApellido(NULL,paises,apellidos,listaMundo,paraiso,infierno);
    ventanaCondenarPais = new VentanaCondenarPais(NULL,infierno,listaMundo,paises);
    ventanaCondenados = new VentanaCondenados(NULL,infierno,nombrePecado);
    ventanaNoNacidos = new VentanaNoNacidos(NULL, listaMundo, infierno, paraiso,arbolVida);
}

VentanaMundo::~VentanaMundo()
{
    delete ui;
}

void VentanaMundo::on_botonArbol_clicked()
{

    ventanaArbolVida->show();

}

void VentanaMundo::on_botonSalvados_clicked()
{

    ventanaSalvados->show();

}

void VentanaMundo::on_botonNacimiento_clicked()
{

    ventanaNacimiento->show();

}

void VentanaMundo::on_botonPecar_clicked()
{
   listaMundo->otorgarPecados();
}

void VentanaMundo::on_botonFamilia_clicked()
{

    ventanaConsultasFamilia->show();

}

void VentanaMundo::on_botonTop10_clicked()
{

    ventanaTop10->show();
}

void VentanaMundo::on_botonTop5_clicked()
{

    ventanaTop5->show();
}

void VentanaMundo::on_botonMapa_clicked()
{

     ventanaContinentes->show();
}

void VentanaMundo::on_botonPecadores_clicked()
{

    ventanaPecadores->show();
}

void VentanaMundo::on_botonApellido_clicked()
{

    ventanaConsultaApellido->show();
}

void VentanaMundo::on_botonCondenar_clicked()
{

    ventanaCondenarPais->show();
}

void VentanaMundo::on_botonCondenados_clicked()
{

    ventanaCondenados->show();
}

void VentanaMundo::on_botonNoNacidos_clicked()
{
    ventanaNoNacidos->show();
}

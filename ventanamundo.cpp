#include "ventanamundo.h"
#include "ui_ventanamundo.h"

VentanaMundo::VentanaMundo(QWidget *parent,QString* pApellidos,QString* pNombres,QString* pPaises,
                           QString* pCreencias, QString* pProfesiones,QString* pNombrePecado,
                           ListaMundo* pListaMundo, ArbolApellidos* pArbolesApellidos[]) :
    QWidget(parent),
    ui(new Ui::VentanaMundo)
{
    ui->setupUi(this);
    apellidos=pApellidos;
    nombres=pNombres;
    paises=pPaises;
    creencias=pCreencias;
    profesiones=pProfesiones;
    nombrePecado=pNombrePecado;
    listaMundo=pListaMundo;
    arbolesApellidos = pArbolesApellidos;


    ventanaArbolVida = new VentanaArbolVida();
    ventanaSalvados= new VentanaSalvados();
    ventanaNacimiento= new VentanaNacimiento(NULL,apellidos,nombres,paises,creencias,profesiones,
                                             nombrePecado,listaMundo);
    ventanaConsultasFamilia= new VentanaConsultasFamilia();
    ventanaTop10 = new VentanaTop10Pecadores(NULL,listaMundo,paises);
    ventanaTop5= new VentanaTop5Salvados(NULL,listaMundo,paises);
    ventanaContinentes = new VentanaContinentes();
    ventanaPecadores = new VentanaPecadores();
    ventanaConsultaApellido = new VentanaConsultaApellido();
    ventanaCondenarPais = new VentanaCondenarPais(NULL,paises);
    ventanaCondenados= new VentanaCondenados();


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

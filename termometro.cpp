#include "termometro.h"
#include "ui_termometro.h"

#include <QtDebug>

Termometro::Termometro(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Termometro)
{
    ui->setupUi(this);


    //conctar signal y slots es decir el dial de cent con fahrenheit pero sin su proyeccion
    connect(ui->cmdCent, SIGNAL(valueChanged(int)),
            this, SLOT(cent2fahr(int)));

    connect(ui->cmdFahr, SIGNAL(valueChanged(int)),
            this, SLOT(fahr2Cent(int)));

    //conectar slot de fahrenheit a kelvin

    connect(ui->cmdFahr, SIGNAL(valueChanged(int)),
            this, SLOT(fahr2Kelv(int)));

    //conectrar de celcius a kelvin

    connect(ui->cmdCent, SIGNAL(valueChanged(int)),
            this, SLOT(cent2kalv(int)));

    //conectar de kelvin a celius

    connect(ui->cmdKel, SIGNAL(valueChanged(int)),
            this, SLOT(kelv2cent(int)));

    //conectar de kelvin a fahrenheit

    connect(ui->cmdKel, SIGNAL(valueChanged(int)),
            this, SLOT(kelv2fahr(int)));
}

Termometro::~Termometro()
{
    delete ui;
}

void Termometro::cent2fahr(int valor)
{

    if(ui->cmdCent->hasFocus()){

    float f = valor *9.0/5 + 32;

    //seteamos el dial para igualar cantidades

    ui->cmdFahr->setValue(f);

    }

}

void Termometro::fahr2Cent(int valor)
{
    // comversion de far a cent

    if(ui->cmdFahr->hasFocus()){

    float c = (valor-32)*5.0/9;

    ui->cmdCent->setValue(c);

    }
}

void Termometro::fahr2Kelv(int valor)
{

    //conversion de fahrenheit a kelvin

    if(ui->cmdFahr->hasFocus()){

    float k = (valor+459.67) * 5.0/9;

    ui->cmdKel->setValue(k);

    }

}

void Termometro::cent2kalv(int valor)
{
    //conversion de celcius a kelvin

    if(ui->cmdCent->hasFocus()){

    float cak = valor + 273.15;

    ui->cmdKel->setValue(cak);

    }

}

void Termometro::kelv2cent(int valor)
{
    // convertimos el valor de kelv a celcius

    if(ui->cmdKel->hasFocus()){

    float kac = valor - 273.15;

    ui->cmdCent->setValue(kac);

    }

}

void Termometro::kelv2fahr(int valor)
{
    //convertimos de kelvin a fahrenheit

    if(ui->cmdKel->hasFocus()){

    float kaf = (valor - 273.15) * 9.0/5 + 32;

    ui->cmdFahr->setValue(kaf);

    }

}


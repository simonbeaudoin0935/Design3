#include "pid_chart.h"

#include <QtCharts/QAbstractAxis>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>
#include <QtCore/QDebug>

PID_Chart::PID_Chart(QGraphicsItem *parent, Qt::WindowFlags wFlags):
    QChart(QChart::ChartTypeCartesian, parent, wFlags),

    m_serieVmax(new QLineSeries(this)),
    m_serieConsignePosition(new QLineSeries(this)),
    m_serieConsigneVitesse(new QLineSeries(this)),
    m_serieVitesse(new QLineSeries(this)),
    m_seriePosition(new QLineSeries(this)),
    m_seriePIDOutput(new QLineSeries(this)),

    m_x_index(0.0),

    m_play(true)



{

    QPen pen1(Qt::black);
    pen1.setWidth(1);
    m_serieVmax->setPen(pen1);
    m_serieVmax->setName("PID_1 consigne vitesse");

    QPen pen2(Qt::magenta);
    pen2.setWidth(1);
    m_serieConsignePosition->setPen(pen2);
    m_serieConsignePosition->setName("PID_4 consigne vitesse");

    QPen pen3(Qt::red);
    pen3.setWidth(1);
    m_serieConsigneVitesse->setPen(pen3);
    m_serieConsigneVitesse->setName("PID_1 position");

    QPen pen4(Qt::green);
    pen4.setWidth(1);
    m_serieVitesse->setPen(pen4);
    m_serieVitesse->setName("PID_4 position");

    QPen pen5(Qt::blue);
    pen5.setWidth(1);
    m_seriePosition->setPen(pen5);
    m_seriePosition->setName("PID_1 vitesse");

    QPen pen6(Qt::gray);
    pen6.setWidth(1);
    m_seriePIDOutput->setPen(pen6);
    m_seriePIDOutput->setName("PID_4 vitesse");

    this->addSeries(m_serieVmax);
    this->addSeries(m_serieConsignePosition);
    this->addSeries(m_serieConsigneVitesse);
    this->addSeries(m_serieVitesse);
    this->addSeries(m_seriePosition);
    this->addSeries(m_seriePIDOutput);

    //m_serieVmax->hide();

    this->createDefaultAxes();

    axisX()->setRange(0,20.0);
    axisY()->setRange(-30.0, 50.0);

}

PID_Chart::~PID_Chart()
{

}


typedef union{
    int   integer;
    float floating;
    char  bytes[sizeof(int)]; //[4]
}type_u;

type_u decode_number(QByteArray::Iterator& it){
    type_u type;
    type.bytes[0] = *it; it++;
    type.bytes[1] = *it; it++;
    type.bytes[2] = *it; it++;
    type.bytes[3] = *it; it++;

    return type;
}

void PID_Chart::addPIDOutputPoint(QByteArray p_data)
{
    if(m_play == true){
        QByteArray::iterator byte_array_it = p_data.begin();

        type_u type;

        type = decode_number(byte_array_it);
        m_serieVmax->append(m_x_index, type.floating);

        type = decode_number(byte_array_it);
        m_serieConsignePosition->append(m_x_index, type.floating);

        type = decode_number(byte_array_it);
        m_serieConsigneVitesse->append(m_x_index, type.floating);

        type = decode_number(byte_array_it);
        m_serieVitesse->append(m_x_index, type.floating);

        type = decode_number(byte_array_it);
        m_seriePosition->append(m_x_index, type.floating);

        type = decode_number(byte_array_it);
        m_seriePIDOutput->append(m_x_index, type.floating);

        m_x_index += 0.05;


        qreal x = plotArea().width() / (20.0 / 0.05);
        if(m_x_index > 19.5) scroll(x,0);

    }
}

void PID_Chart::play_pause(bool p_play_pause)
{
    m_play = p_play_pause;
}



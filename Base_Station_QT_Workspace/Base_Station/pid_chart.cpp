#include "pid_chart.h"

#include <QtCharts/QAbstractAxis>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>
#include <QtCore/QDebug>

PID_Chart::PID_Chart(QGraphicsItem *parent, Qt::WindowFlags wFlags):
    QChart(QChart::ChartTypeCartesian, parent, wFlags),

    m_serieDisplacement(new QLineSeries(this)),
    m_serieSpeed(new QLineSeries(this)),
    m_serieAcceleration(new QLineSeries(this)),
    m_seriePIDOutput(new QLineSeries(this)),


    m_displacement_index(0.0),
    m_speed_index(0.0),
    m_acceleration_index(0.0),
    m_PIDOutput_index(0.0),
    x(0)



{

    QPen pen1(Qt::red);
    pen1.setWidth(1);
    m_serieDisplacement->setPen(pen1);
    m_serieDisplacement->setName("Displacement");

    QPen pen2(Qt::blue);
    pen2.setWidth(1);
    m_serieSpeed->setPen(pen2);
    m_serieSpeed->setName("Speed");

    QPen pen3(Qt::green);
    pen3.setWidth(1);
    m_serieAcceleration->setPen(pen3);
    m_serieAcceleration->setName("Acceleration");

    QPen pen4(Qt::black);
    pen4.setWidth(1);
    m_seriePIDOutput->setPen(pen4);
    m_seriePIDOutput->setName("PID output");



    this->addSeries(m_serieDisplacement);
    this->addSeries(m_serieSpeed);
    this->addSeries(m_serieAcceleration);
    this->addSeries(m_seriePIDOutput);
    this->createDefaultAxes();

    axisX()->setRange(0,1);
    axisY()->setRange(-5, 5);

}

PID_Chart::~PID_Chart()
{

}

void PID_Chart::addPIDOutputPoint(QByteArray p_data)
{

    x++;

    typedef union{
        int   integer;
        float floating;
        char  bytes[sizeof(int)]; //[4]
    }type_u;

    type_u t1;
    type_u t2;
    type_u t3;
    type_u t4;

    t1.bytes[0] = p_data.at(0);
    t1.bytes[1] = p_data.at(1);
    t1.bytes[2] = p_data.at(2);
    t1.bytes[3] = p_data.at(3);

    m_serieDisplacement->append(m_displacement_index,t1.floating);
    m_displacement_index += 0.05;

    t2.bytes[0] = p_data.at(4);
    t2.bytes[1] = p_data.at(5);
    t2.bytes[2] = p_data.at(6);
    t2.bytes[3] = p_data.at(7);

    m_serieSpeed->append(m_speed_index, t2.floating);
    m_speed_index += 0.05;

    t3.bytes[0] = p_data.at(8);
    t3.bytes[1] = p_data.at(9);
    t3.bytes[2] = p_data.at(10);
    t3.bytes[3] = p_data.at(11);

    m_serieAcceleration->append(m_acceleration_index, t3.floating);
    m_acceleration_index += 0.05;

    t4.bytes[0] = p_data.at(12);
    t4.bytes[1] = p_data.at(13);
    t4.bytes[2] = p_data.at(14);
    t4.bytes[3] = p_data.at(15);

    m_seriePIDOutput->append(m_PIDOutput_index, t4.floating);
    m_PIDOutput_index += 0.05;

    //m_x += 0.01;

    //qreal x = plotArea().width() / m_axis->tickCount();

    if(x > 10)scroll(17.35,0);




}



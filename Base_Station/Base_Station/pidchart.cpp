#include "pidchart.h"

#include <QtCharts/QAbstractAxis>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>
#include <QtCore/QDebug>

PIDChart::PIDChart(QGraphicsItem *parent, Qt::WindowFlags wFlags):
    QChart(QChart::ChartTypeCartesian, parent, wFlags),

    m_serie1(new QLineSeries(this)),
    m_serie2(new QLineSeries(this)),
    m_serie3(new QLineSeries(this)),
    m_serie4(new QLineSeries(this)),
    m_serie5(new QLineSeries(this)),
    m_serie6(new QLineSeries(this)),

    m_x_index(0.0),

    m_play(true)
{

    QPen pen1(Qt::black);
    pen1.setWidth(1);
    m_serie1->setPen(pen1);
    m_serie1->setName("Actual speed");

    QPen pen2(Qt::magenta);
    pen2.setWidth(1);
    m_serie2->setPen(pen2);
    m_serie2->setName("actual distance");

    QPen pen3(Qt::red);
    pen3.setWidth(1);
    m_serie3->setPen(pen3);
    m_serie3->setName("expected speed");

    QPen pen4(Qt::green);
    pen4.setWidth(1);
    m_serie4->setPen(pen4);
    m_serie4->setName("expected distance");

    QPen pen5(Qt::blue);
    pen5.setWidth(1);
    m_serie5->setPen(pen5);
    m_serie5->setName("distance error");

    QPen pen6(Qt::gray);
    pen6.setWidth(1);
    m_serie6->setPen(pen6);
    m_serie6->setName("speed error");

    this->addSeries(m_serie1);
    this->addSeries(m_serie2);
    this->addSeries(m_serie3);
    this->addSeries(m_serie4);
    this->addSeries(m_serie5);
    this->addSeries(m_serie6);


    this->createDefaultAxes();

    axisX()->setRange(0,20.0);
    axisY()->setRange(-30.0, 50.0);

}

PIDChart::~PIDChart()
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

void PIDChart::addPIDOutputPoint(QByteArray p_data)
{
    if(m_play == true){
        QByteArray::iterator byte_array_it = p_data.begin();

        type_u type;

        type = decode_number(byte_array_it);
        m_serie1->append(m_x_index, type.floating);

        type = decode_number(byte_array_it);
        m_serie2->append(m_x_index, type.floating);

        type = decode_number(byte_array_it);
        m_serie3->append(m_x_index, type.floating);

        type = decode_number(byte_array_it);
        m_serie4->append(m_x_index, type.floating);

        type = decode_number(byte_array_it);
        m_serie5->append(m_x_index, type.floating);

        type = decode_number(byte_array_it);
        m_serie6->append(m_x_index, type.floating);

        m_x_index += 0.05;


        qreal x = plotArea().width() / (20.0 / 0.05);
        if(m_x_index > 19.5) scroll(x,0);


    }
}

void PIDChart::play_pause(bool p_play_pause)
{
    m_play = p_play_pause;
}



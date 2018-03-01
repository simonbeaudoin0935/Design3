#ifndef PID_CHART_H
#define PID_CHART_H

#include <QtCharts/QChart>


QT_CHARTS_BEGIN_NAMESPACE
class QLineSeries;
class QValueAxis;
QT_CHARTS_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE

class PIDChart: public QChart
{
public:
    PIDChart(QGraphicsItem *parent = 0, Qt::WindowFlags wFlags = 0);
    virtual ~PIDChart();

public slots:
    void addPIDOutputPoint(QByteArray p_data);

    void play_pause(bool p_play_pause);

private:

    QLineSeries *m_serie1;
    QLineSeries *m_serie2;
    QLineSeries *m_serie3;
    QLineSeries *m_serie4;
    QLineSeries *m_serie5;
    QLineSeries *m_serie6;


    bool m_play;
    float m_x_index;


};

#endif // PID_CHART_H








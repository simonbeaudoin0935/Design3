#ifndef PID_CHART_H
#define PID_CHART_H

#include <QtCharts/QChart>


QT_CHARTS_BEGIN_NAMESPACE
class QLineSeries;
class QValueAxis;
QT_CHARTS_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE

class PID_Chart: public QChart
{
public:
    PID_Chart(QGraphicsItem *parent = 0, Qt::WindowFlags wFlags = 0);
    virtual ~PID_Chart();

public slots:
    void addPIDOutputPoint(QByteArray p_data);

    void play_pause(bool p_play_pause);

private:

    QLineSeries *m_serieVmax;
    QLineSeries *m_serieConsignePosition;
    QLineSeries *m_serieConsigneVitesse;
    QLineSeries *m_serieVitesse;
    QLineSeries *m_seriePosition;
    QLineSeries *m_seriePIDOutput;


    bool m_play;
    float m_x_index;


};

#endif // PID_CHART_H








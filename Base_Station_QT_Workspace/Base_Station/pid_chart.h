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

private:

    QLineSeries *m_serieDisplacement;


    QLineSeries *m_serieSpeed;


    QLineSeries *m_serieAcceleration;


    QLineSeries *m_seriePIDOutput;


    float m_displacement_index;
    float m_speed_index;
    float m_acceleration_index;
    float m_PIDOutput_index;

    int x;

};

#endif // PID_CHART_H






//private:
//    QTimer m_timer;
//    QSplineSeries *m_series;
//    QStringList m_titles;
//    QValueAxis *m_axis;
//    qreal m_step;
//    qreal m_x;
//    qreal m_y;


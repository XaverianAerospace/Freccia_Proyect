#ifndef WIDGET_H
#define WIDGET_H

#include "SensorManager.h"
class Graph3DWindow;

#include <QWidget>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QTimer>
#include <QDateTime>
#include <QVector3D>
#include <QtDataVisualization/Q3DScatter>
#include <QtDataVisualization/QScatter3DSeries>
#include <QtDataVisualization/QScatterDataProxy>
#include <QtDataVisualization/QScatterDataItem>

class Widget : public QWidget {
    Q_OBJECT

public:
    explicit Widget(SensorManager* manager, QWidget* parent = nullptr);
    ~Widget();

private:
    int xIndex = 0;

    // Referencias a SensorManager y Graph3DWindow
    SensorManager* m_sensorManager = nullptr;
    Graph3DWindow* m_graph3DWindow = nullptr;

    // === Gráficas individuales ===
    QChart *chartRoll, *chartPitch, *chartYaw;
    QChart *chartSats, *chartLat, *chartLon;
    QChart *chartAlt, *chartHdop;
    QChart *chartPresion, *chartTemp;

    // === Series ===
    QLineSeries *seriesRoll, *seriesPitch, *seriesYaw;
    QLineSeries *seriesSats, *seriesLat, *seriesLon;
    QLineSeries *seriesAlt, *seriesHdop;
    QLineSeries *seriesPressure, *seriesTemp;

    // === Vistas ===
    QChartView *viewRoll, *viewPitch, *viewYaw;
    QChartView *viewSats, *viewLat, *viewLon;
    QChartView *viewAlt, *viewHdop;
    QChartView *viewPressure, *viewTemp;

    // === Labels ===
    QLabel *labelRoll, *labelPitch, *labelYaw;
    QLabel *labelSats, *labelLat, *labelLon;
    QLabel *labelAlt, *labelHdop;
    QLabel *labelPressure, *labelTemp;

    // === Labels de servo y estado ===
    QLabel* labelServos[4];
    QLabel* labelStatus[6];

    // === Ejes dinámicos para cada gráfica ===
    QValueAxis *axisX_Roll, *axisY_Roll;
    QValueAxis *axisX_Pitch, *axisY_Pitch;
    QValueAxis *axisX_Yaw, *axisY_Yaw;
    QValueAxis *axisX_Sats, *axisY_Sats;
    QValueAxis *axisX_Lat, *axisY_Lat;
    QValueAxis *axisX_Lon, *axisY_Lon;
    QValueAxis *axisX_Alt, *axisY_Alt;
    QValueAxis *axisX_Hdop, *axisY_Hdop;
    QValueAxis *axisX_Pressure, *axisY_Pressure;
    QValueAxis *axisX_Temp, *axisY_Temp;

    QLabel* labelCom = nullptr;
    QLabel* labelBaud = nullptr;
    QLabel* labelRaw = nullptr;


};

#endif // WIDGET_H

#pragma once
#include <QWidget>
#include <QtWidgets>
#include <QObject>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include "wind_functions.h"
#include "algorithms.h"

class wind_class : public QWidget
{
    Q_OBJECT
public:
    wind_class(QWidget* pwgt = 0);
public slots:
    void m_RedButton2();
};


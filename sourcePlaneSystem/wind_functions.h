#pragma once
#include <QWidget>
#include <QtWidgets>
#include <QObject>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>

void m_SetSliderGray(QSlider* slider);
void m_SetSliderBlue(QSlider* slider);
void m_settext_lbl(QLabel* label, bool variable, QString str);
void m_settext_lbl(QLabel* label, int variable, QString str);
void m_settext_lbl(QLabel* label, double variable, QString str);
void m_settext_lbl(QLabel* label, QVector<bool> variable, QString str);
void m_settext_lbl(QLabel* label, QVector<double> variable, QString str);
void m_switch(bool* toggler, bool* toggling);
void m_DoubleTrue(bool* UpperToggler, bool* UnderToggler, bool* Trigger);
void m_DoubleTrueAnd(bool* UpperToggler, bool* UnderToggler, bool* Trigger);
void m_RedButton2(QPushButton *button, bool* clue);
void m_RadioButton2(QRadioButton *rbutton, int* holder, int value);


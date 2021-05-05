#pragma once
#include <QWidget>
#include <QtWidgets>
#include <QObject>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QTimer>

class interfacing : public QWidget
{
    Q_OBJECT
public:
    interfacing(QWidget *parent = nullptr);

public:
    QFont *btnFont;
    QFont *lblClueFontAct;
    QFont *lblClueFontInact;
    QFont *lblValueFontAct;
    QFont *lblValueFontInact;
    QGridLayout* layout_buttons;
    QVector<QPushButton*> btnsPool;
    QVector<QLabel*> lblsPoolClue;
    QVector<QLabel*> lblsPoolValue;
    QVector<QSlider*> slPool;
    QVector<bool*> btnClues;
    QVector<bool*> lblClues;
    QVector<double*> lblValues;
    QVector<double*> slValues;
    QVector<QButtonGroup*> rbGrPool;
    int btnID;
    int slID;
    int lblClueID;
    int lblValueID;
    int row, column;
    int wgtCount;
    QSignalMapper* signalMapperBtns;
    QSignalMapper* signalMapperSldrs;

    //rbuttons
    QSignalMapper* signalMapperRbtns;
    int rbGroupID;
    int rbID;
    int rbMappedValue;
    QVector<int*> rbTogglers;
    QVector<QRadioButton*> rbtnPool;
    void posOcupied();


signals:
    int digitClicked(int);
    int changeValue(int);
    int rbClicked(const QString);

public slots:
    void createRedButton(bool* clue, QString name);
    void createRadioButton(int* toggler, QString name, bool isnewgroup);
    void createLabelClue(bool* clue, QString name);
    void createLabelValue(double* clue, QString name);
    void createSlider(double* variable, int low_val, int high_val);
    void m_RedButton2(int);
    void setLbl();
    void setSlV(int);
    void setRB(const QString);
    void trigerButton();
    virtual void updateLogic();
};


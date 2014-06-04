#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <math.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QWidget * root_1;
    QScrollArea *root;
    QLabel *label_caption;
    QVBoxLayout * main_layout;
      QIntValidator * validator;
    //Task 1
    QSpinBox **spinarr_t1a;
    QSpinBox **spinarr_t1b;
    QLabel * label_t1va;
    QLabel * label_t1vb;
    //Task 2


    QSpinBox **spinarr_t2a;
    QSpinBox **spinarr_t2b;
    QLabel * label_t2v;
    //Task 3
    QLineEdit **le_t3a;
    QLineEdit **le_t3b;
    QSpinBox **spinarr_t3a;
    QSpinBox **spinarr_t3b;
    QLabel * label_t3vs;
    QLabel * label_t3vv;
    //Task 4
    QSpinBox ** spinarr_t4;
    QLabel ** la_t4v;
    //Task 5
    QSpinBox ** spinarr_t5;
    QLabel * label_t5_v; 
    //Task 6
    QSpinBox **spinarr_t6;
    QLabel * label_t6_v;
    //Task 7
    //Menu

    QMenuBar * menubar;
    QMenu * global_menu;
    QToolBar * toolbar;
    QAction * act_exit;
    QAction * act_about;
    QAction * act_license;
    

private:
    void createTask_1();
    void createTask_2();
    void createTask_3();
    void createTask_4();
    void createTask_5();
    void createTask_6();
    void createTask_7();
    void createTask_8();
    void createTask_9();

private slots:
    void slot_t1_m2(int value);
     void slot_t1_m3(int value );
     void slot_t2_ch(int value);
      void slot_t3_ch(int);
      void slot_t4_ch(int i);
      void slot_t5_ch(int i);
       void slot_t6_ch(int i);
       void slot_ActionOnExit(bool);


};

#endif // MAINWINDOW_H

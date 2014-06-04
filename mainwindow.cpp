#include "mainwindow.h"


QString calculateM2toString(int a,int b,int c,int d);
double calculateDeterminantM3(int * arr);
QString getStringForDeterminantExt(int * arr);
QString getStringForDeterminant(int * arr,QString prefix = QString());
double calculateArcR3(double * arr);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    //this->resize(500,700);
    root_1 = new QWidget(0);
root= new QScrollArea(0);


   // root->setWidgetResizable(true);
  root->setWidget(root_1);
    this->setCentralWidget(root);
 QScroller::grabGesture(root->viewport(),  QScroller::LeftMouseButtonGesture);


    this->main_layout = new QVBoxLayout(0);
    main_layout->setSizeConstraint(QLayout::SetMinimumSize);
    root_1->setLayout(main_layout);
    this->label_caption = new  QLabel("==================");/*("<center>Контрольна робота з №1 <br>з "
                                      "курсу математика для економістів (Вища Математика)<br>"
                                      "Викладач: Середа Володимир Юрійович </center> ");*/
    this->main_layout->addWidget(label_caption);
validator = new QIntValidator(-100,100);
createTask_1();
createTask_2();
createTask_3();
createTask_4();
createTask_5();
createTask_6();
createTask_7();
createTask_8();
createTask_9();
 QSpacerItem * verticalSpacer = new QSpacerItem(1, 1, QSizePolicy::Minimum, QSizePolicy::Expanding);
 this->main_layout->addItem(verticalSpacer);
this->menubar = menuBar();
this->global_menu = this->menubar->addMenu("file");

act_exit = this->global_menu->addAction("Exit");
connect(act_exit,&QAction::triggered,this,&MainWindow::slot_ActionOnExit);
QFile file_qss(":/main.qss");
if(file_qss.exists())
{
    if(file_qss.open(QIODevice::ReadOnly))
    {
        QString sss(file_qss.readAll());
        this->setStyleSheet(sss);

    }
}
}
MainWindow::~MainWindow()
{
    
}
void MainWindow::createTask_1()
{
     QSizePolicy sizePolicy_label(QSizePolicy::Maximum, QSizePolicy::Maximum);


  QGroupBox * group = new QGroupBox();


  QVBoxLayout * vbox = new QVBoxLayout;
    QGridLayout * grid_task_a = new QGridLayout;
    QGridLayout * grid_task_b = new QGridLayout;
    QLabel * label_number = new QLabel("a)");
    this->spinarr_t1a = new QSpinBox *[4];
    this->spinarr_t1b = new QSpinBox *[9];
    label_t1va = new QLabel;

label_t1va->setSizePolicy(sizePolicy_label);
    this->main_layout->addWidget(group);
    group->setTitle("Обчислити визначники ");
    group->setLayout(vbox);
    vbox->addLayout(grid_task_a);
    label_number->setSizePolicy(sizePolicy_label);
    grid_task_a->addWidget(label_number,0,0);
     for(int i=0;i<4;i++)
    {
         this->spinarr_t1a[i] = new QSpinBox();


         connect(spinarr_t1a[i],SIGNAL(valueChanged(int)),this,SLOT(slot_t1_m2(int)));
                 grid_task_a->addWidget(spinarr_t1a[i],i/2,(i%2)+1);
         this->spinarr_t1a[i]->setMinimum(-100);
         this->spinarr_t1a[i]->setMaximum(100);
     }



     grid_task_a->addWidget(label_t1va,0,3,2,1);
    QSpacerItem * horizontalSpacer = new QSpacerItem(1, 1, QSizePolicy::Expanding, QSizePolicy::Minimum);
    grid_task_a->addItem(horizontalSpacer,0,4,2,1);
     spinarr_t1a[0]->valueChanged(0);
     QFrame * f_line= new QFrame();
     f_line->setStyleSheet(QStringLiteral("background:white"));
     f_line->setFrameShape(QFrame::HLine);
     f_line->setFrameShadow(QFrame::Sunken);
     QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
     f_line->setSizePolicy(sizePolicy);
     vbox->addWidget(f_line);
     vbox->addLayout(grid_task_b);
     label_number = new QLabel("b)");
     label_number->setSizePolicy(sizePolicy_label);
     grid_task_b->addWidget(label_number,0,0);

     for(int i=0;i<9;i++)
     {
         spinarr_t1b[i] = new QSpinBox;
         this->spinarr_t1b[i]->setMinimum(-100);
         this->spinarr_t1b[i]->setMaximum(100);
         grid_task_b->addWidget(spinarr_t1b[i],i/3,(i%3)+1);
         connect(spinarr_t1b[i],SIGNAL(valueChanged(int)),this,SLOT(slot_t1_m3(int)));

     }


     label_t1vb= new QLabel("=");
     label_t1vb->setSizePolicy(sizePolicy_label);
    grid_task_b->addWidget(label_t1vb,0,4,3,1,Qt::AlignLeft|Qt::AlignVCenter);
horizontalSpacer = new QSpacerItem(1, 1, QSizePolicy::Expanding, QSizePolicy::Minimum);
 grid_task_b->addItem(horizontalSpacer,0,5,3,1);
 spinarr_t1b[0]->valueChanged(0);

}
void MainWindow::createTask_2()
{
    QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Ignored);

   QGroupBox *group = new QGroupBox("Знайти добуток матриць");
    this->main_layout->addWidget(group);
    QGridLayout * grid = new QGridLayout();
    group->setLayout(grid);
    this->spinarr_t2a = new QSpinBox * [6];
    this->spinarr_t2b = new QSpinBox * [6];

    QLabel * label_mn= new QLabel("\t<h1>*<h1>\t"); label_mn->setSizePolicy(sizePolicy);
    grid->addWidget(label_mn,0,3,2,1,Qt::AlignVCenter);
    for(int i=0;i<6;i++  )
    {
        spinarr_t2a[i] = new QSpinBox();spinarr_t2a[i]->setMinimum(-100);spinarr_t2a[i]->setMaximum(100);
        spinarr_t2b[i] = new QSpinBox();spinarr_t2b[i]->setMinimum(-100);spinarr_t2b[i]->setMaximum(100);
        connect(spinarr_t2a[i],(void (QSpinBox:: *)(int)) &QSpinBox::valueChanged ,this,&MainWindow::slot_t2_ch);
      connect(spinarr_t2b[i],(void (QSpinBox:: *)(int)) &QSpinBox::valueChanged ,this,&MainWindow::slot_t2_ch);

        grid->addWidget(spinarr_t2a[i],i%2,i/2);
        grid->addWidget(spinarr_t2b[i],i/2,i%2+4);

    }
    this->label_t2v = new QLabel("=====");
    grid->addWidget(label_t2v,1,6,1,1);
    QSpacerItem * horizontalSpacer = new QSpacerItem(1, 1, QSizePolicy::Expanding, QSizePolicy::Minimum);
    grid->addItem(horizontalSpacer,0,7,3,1);


    spinarr_t2b[0]->valueChanged( (spinarr_t2b[0]->value()));

}
void MainWindow::createTask_3()
{
    QGroupBox * group = new QGroupBox("Знайти скалярний та векторний добуток векторів ");
    QVBoxLayout * layout = new  QVBoxLayout();
    QGridLayout * grid = new QGridLayout();
    this->main_layout->addWidget(group);
    group->setLayout(layout);
    layout->addLayout(grid);
    spinarr_t3a = new QSpinBox * [3];
    spinarr_t3b = new QSpinBox * [3];

    le_t3a = new QLineEdit *[3];
    le_t3b = new QLineEdit *[3];
     QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);

   QLabel * label_tmp = new QLabel("<h3>a)</h3>");label_tmp->setSizePolicy(sizePolicy); ;grid->addWidget(label_tmp,0,0);
    label_tmp = new QLabel("<h3>b)</h3>");label_tmp->setSizePolicy(sizePolicy);grid->addWidget(label_tmp,1,0);


    for(int i=0;i<3;i++)
    {
        spinarr_t3a[i]= new QSpinBox;spinarr_t3a[i]->setMinimum(-100);spinarr_t3a[i]->setMaximum(100);
       spinarr_t3b[i]= new QSpinBox;spinarr_t3b[i]->setMinimum(-100);spinarr_t3b[i]->setMaximum(100);
        grid->addWidget(spinarr_t3a[i],0,i+1);
        grid->addWidget(spinarr_t3b[i],1,i+1);
        connect(spinarr_t3a[i],(void (QSpinBox:: *)(int)) &QSpinBox::valueChanged ,this,&MainWindow::slot_t3_ch);
        connect(spinarr_t3b[i],(void (QSpinBox:: *)(int)) &QSpinBox::valueChanged ,this,&MainWindow::slot_t3_ch);
    }
    this->label_t3vs = new QLabel();
     this->label_t3vv = new QLabel();
    layout->addWidget(label_t3vs);
     layout->addWidget(label_t3vv);
     QSpacerItem * horizontalSpacer = new QSpacerItem(1, 1, QSizePolicy::Expanding, QSizePolicy::Minimum);
     grid->addItem(horizontalSpacer,0,4,2,1);



spinarr_t3b[0]->valueChanged(0);




}
void MainWindow::createTask_4()
{

    QGroupBox * group = new QGroupBox("Розязати систему лінійних рівнянь");
    main_layout->addWidget(group);

    QVBoxLayout * vb_layout = new QVBoxLayout();
vb_layout->setSpacing(1);
    group->setLayout(vb_layout);
    QGridLayout * grid = new QGridLayout();
    grid->setSpacing(6);

    spinarr_t4 = new QSpinBox * [12];
    la_t4v = new QLabel*  [5];
    for(int i =0;i<12;i++)
    {
        spinarr_t4[i]= new QSpinBox();
        spinarr_t4[i]->setMinimum(-1000);
        spinarr_t4[i]->setMaximum(1000);
        grid->addWidget(spinarr_t4[i],i/4,(i%4)*2);

            connect( spinarr_t4[i], SIGNAL(valueChanged(int)), this, SLOT(slot_t4_ch(int))); //check
    }
QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    for(int i=0;i<3;i++)
    {

         QLabel * tmp= new QLabel(" + "); tmp->setSizePolicy(sizePolicy);
        grid->addWidget(tmp,i,1);
         tmp= new QLabel(" + ");tmp->setSizePolicy(sizePolicy);
         grid->addWidget(tmp,i,3);
         tmp= new QLabel(" = ");tmp->setSizePolicy(sizePolicy);
          grid->addWidget(tmp,i,5);



    }
    vb_layout->addLayout(grid);
    for(int i=0;i<5;i++)
    {
        la_t4v[i]= new QLabel();
        la_t4v[i]->setSizePolicy(sizePolicy);
        vb_layout->addWidget(la_t4v[i]);

    }

    QSpacerItem * horizontalSpacer = new QSpacerItem(1, 1, QSizePolicy::Expanding, QSizePolicy::Minimum);
    grid->addItem(horizontalSpacer,0,7,3,1);
    spinarr_t4[0]->valueChanged(0);


}
void MainWindow::createTask_5()
{
    QGroupBox * group = new QGroupBox("Написати рівняння прямої щ проходить через дві точки");
    QGridLayout  * grid = new QGridLayout;
    this->spinarr_t5 = new QSpinBox* [4];
    this->label_t5_v = new QLabel;
    this->main_layout->addWidget(group);
    group->setLayout(grid);
    int counter = 1;
    QLabel * label_tmp = new QLabel("a)");label_tmp->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    grid->addWidget(label_tmp,0,0,1,1);
    for(int i=0;i<4;i++)
    {
        spinarr_t5[i]=new QSpinBox;
        spinarr_t5[i]->setMinimum(-100);
        spinarr_t5[i]->setMaximum(100);
        if(i%2==0)
        { spinarr_t5[i]->setSuffix(" x");}
        else
        {spinarr_t5[i]->setSuffix(" y");}
        grid->addWidget(spinarr_t5[i],0,counter,1,1);
        connect( spinarr_t5[i], SIGNAL(valueChanged(int)), this, SLOT(slot_t5_ch(int)));
        counter++;
        if(i==1)
        {
            label_tmp = new QLabel("b)");label_tmp->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
            grid->addWidget(label_tmp,0,counter,1,1);
            counter++;
        }
    }
    grid->addWidget(label_t5_v,2,0,1,6);
    QSpacerItem * horizontalSpacer = new QSpacerItem(1, 1, QSizePolicy::Expanding, QSizePolicy::Minimum);
    grid->addItem(horizontalSpacer,0,6,2,1);
    spinarr_t5[0]->valueChanged(0);

}
void MainWindow::createTask_6()
{
    QGroupBox * group = new QGroupBox("Знайти кут між площинами A i B");
    QGridLayout  * grid = new QGridLayout;
    main_layout->addWidget(group);
    group->setLayout(grid);
    spinarr_t6 = new QSpinBox*[6];
    QLabel* tmp_label = new QLabel("A)");
    tmp_label->setSizePolicy(QSizePolicy( QSizePolicy::Maximum, QSizePolicy::Maximum));
    grid->addWidget(tmp_label,0,0,1,1,Qt::AlignLeft);
    tmp_label = new QLabel("B)");
    tmp_label->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    grid->addWidget(tmp_label,1,0);
    int n_row=0,n_col=1;
    for(int i=0;i<6;i++)
    {
        if(i==3)
        { n_row=n_col=1;}

        spinarr_t6[i]= new QSpinBox;spinarr_t6[i]->setMinimum(-100);spinarr_t6[i]->setMaximum(100);

        spinarr_t6[i]->setSuffix( QString(" ") + QChar(((int)'x')+i%3)   );
        connect(spinarr_t6[i],SIGNAL(valueChanged(int)),this,SLOT(slot_t6_ch(int)));
        grid->addWidget(spinarr_t6[i],n_row,n_col);
        n_col++;



    }
    label_t6_v=new  QLabel;
    grid->addWidget(label_t6_v,2,0,1,4);
    QSpacerItem * horizontalSpacer = new QSpacerItem(1, 1, QSizePolicy::Expanding, QSizePolicy::Minimum);
    grid->addItem(horizontalSpacer,0,4,2,1);
    spinarr_t6[0]->valueChanged(0);



}
void MainWindow::createTask_7()
{

}
void MainWindow::createTask_8()
{

}
void MainWindow::createTask_9()
{

}
void MainWindow::slot_t1_m2(int value)
{

    label_t1va->setText(calculateM2toString(spinarr_t1a[0]->value(),spinarr_t1a[1]->value(),spinarr_t1a[2]->value(),spinarr_t1a[3]->value()));

}
void MainWindow::slot_t1_m3(int value)
{
    int tmp_arr[9];
    for(int i=0;i<9;i++ )
    {
        tmp_arr[i]=spinarr_t1b[i]->value();

    }


    QString ss = QString("%0%0").arg(1);
    label_t1vb->setText(getStringForDeterminantExt(tmp_arr));

}
 void MainWindow::slot_t2_ch(int value)
 {

     int tmp_arr[2][2];
     for(int i=0;i<2;i++)
     {
         for(int ii=0;ii<2;ii++)
         {
             tmp_arr[i][ii] = (spinarr_t2a[i]->value()) * (spinarr_t2b[ii]->value())
                     +(spinarr_t2a[i+2]->value()) * (spinarr_t2b[ii+2]->value())
                     +(spinarr_t2a[i+4]->value()) * (spinarr_t2b[ii+4]->value()) ;

         }

     }
     label_t2v->setText(QString("%0,%1\n%2,%3").arg(tmp_arr[0][0]).arg(tmp_arr[0][1]).arg(tmp_arr[1][0]).arg(tmp_arr[1][1]));



 }
 void MainWindow::slot_t3_ch(int)
 {
    int x1 = spinarr_t3a[0]->value();
   int  x2 = spinarr_t3b[0]->value();
   int y1 = spinarr_t3a[1]->value();
    int y2 = spinarr_t3b[1]->value();
    int z1 = spinarr_t3a[2]->value();
    int z2 = spinarr_t3b[2]->value();

     this->label_t3vs->setText(QString("Скалярний добуток = %0*%1+%2*%3+%4*%5 = %6").arg(x1).arg(x2).
             arg(y1).arg(y2).arg(z1).arg(z2)
             .arg(x1*x2+y1*y2+z1*z2));
    this->label_t3vv->setText(QString("Векторний добуток = i(%2*%5-%4*%3)-j(%0*%5-%1*%4)+\n+k(%0*%3-%2*%1) = {%6;%7;%8} ").arg(x1).arg(x2).arg(y1).arg(y2).arg(z1).arg(z2).
                              arg(y1*z2-z1*y2).arg(-(x1*z2-z1*x2)).arg(x1*y2-y1*x2));


 }
 void MainWindow::slot_t4_ch(int i)
 {
     int arr_data[9]={}, arr_data_2[3]={},counter = 0,counter_2 = 0,detx,dety,detz ,det;
     for(int i=0;i<12;i++)
     {
         if((i+1)%4!=0)
         {
         arr_data[counter]= spinarr_t4[i]->value(); counter++;
         }
         else
         {
             arr_data_2[counter_2] = spinarr_t4[i]->value();
             counter_2++;
         }
}

     la_t4v[0]->setText(getStringForDeterminant(arr_data,"&nbsp;det &nbsp;&nbsp;= &nbsp;&nbsp;&nbsp;&nbsp;"));
     det=calculateDeterminantM3(arr_data);
  int tmp[9];
  for(int i=0;i<9;i++)
  {
      if((i%3)==0)
      {
          tmp[i]= arr_data_2[i/3];
          continue;

      }
      tmp[i]= arr_data[i];

  }
  la_t4v[1]->setText(getStringForDeterminant(tmp,"det(x)&nbsp;&nbsp; =&nbsp;&nbsp;"));
  detx = calculateDeterminantM3(tmp);

  for(int i=0;i<9;i++)
  {
      if((i%3)==1)
      {
          tmp[i]= arr_data_2[i/3];
          continue;
      }
      tmp[i]= arr_data[i];
  }
  la_t4v[2]->setText(getStringForDeterminant(tmp,"det(y)&nbsp;&nbsp;=&nbsp;&nbsp;"));
  dety = calculateDeterminantM3(tmp);

  for(int i=0;i<9;i++)
  {
      if((i%3)==2)
      {
          tmp[i]= arr_data_2[i/3];
          continue;
      }
      tmp[i]= arr_data[i];
  }
  la_t4v[3]->setText(getStringForDeterminant(tmp,"det(z)&nbsp;&nbsp;=&nbsp;&nbsp;"));
  detz = calculateDeterminantM3(tmp);
  if(det==0)
  {
      la_t4v[4]->setText("Рівняння не має розвязків ");
  }
else
  {
  la_t4v[4]->setText(QString("x = det(x)/det = %0/%1=%2    \ny = det(y)/det = %3/%4=%5   \nz=det(z)/det = %6/%7=%8"   ).
                     arg(detx).arg(det).arg((double)detx/det).arg(dety).arg(det).arg((double)dety/det).arg(detz).arg(det).arg((double)detz/det));
}


 }
 void MainWindow::slot_t5_ch(int i)
 {
     int tmparr[4];
     for(int i=0;i<4;i++)
     {
         tmparr[i]= spinarr_t5[i]->value();
     }

     label_t5_v->setText(QString("x - %0/ %1 = y - %2/ %3 ").arg(tmparr[0]).arg(tmparr[2]-tmparr[0]).
             arg(tmparr[1]).arg(tmparr[3]-tmparr[1]));


 }
 void MainWindow::slot_t6_ch(int i)
 {
     double tmparr[6];
     for(int i=0;i<6;i++)
     {
         tmparr[i]= spinarr_t6[i]->value();
     }
     double znam = tmparr[0]*tmparr[3]+tmparr[1]*tmparr[4]+tmparr[2]*tmparr[5];
     double chis = sqrt(tmparr[0]*tmparr[0]+tmparr[1]*tmparr[1]+tmparr[2]*tmparr[2])*
             sqrt(tmparr[3]*tmparr[3]+tmparr[4]*tmparr[4]+tmparr[5]*tmparr[5]);
     if(chis==0)
     {
         label_t6_v->setText("Рівняння прощини задано не вірно");
         return;
     }


     label_t6_v->setText(QString("cos A^B =  %0").arg(calculateArcR3(tmparr)));
 }
 void MainWindow::slot_ActionOnExit(bool b)
 {
    qApp->exit();
 }





 QString calculateM2toString(int a,int b,int c,int d)
 {
     QString str = QString(" = (%0*%3)-(%1*%2) = %4").arg(a).arg(b).arg(c).arg(d).arg(a*d -b*c);
     return str;

 }
 double calculateDeterminantM3(int * arr)
 {
     return arr[0]*arr[4]*arr[8]+arr[1]*arr[5]*arr[6]+arr[3]*arr[7]*arr[2]-arr[2]*arr[4]*arr[6]-arr[0]*arr[5]*arr[7]-arr[1]*arr[3]*arr[8];
 }
 QString getStringForDeterminant(int * arr,QString prefix)
 {
     QString str="<table VALIGN=middle><tr><td  ROWSPAN=3>"+prefix+"</td>";
 for(int i=0;i<9;i++)
 {
    str+=QString("<td>%0</td>").arg(arr[i]);
    if((i+1)%3==0)
    {
        if((i+1)==3)
        {
            str+=QString("<td ROWSPAN=3>&nbsp;&nbsp;=&nbsp;&nbsp;%0<td>").arg(calculateDeterminantM3(arr));
        }
        str+="</tr><tr>";
    }
 }
 str+="</tr></table>";
  return str;
 }
 double calculateArcR3(double * arr)
 {
     double znam = arr[0]*arr[3]+arr[1]*arr[4]+arr[2]*arr[5];
     double chis = sqrt(arr[0]*arr[0]+arr[1]*arr[1]+arr[2]*arr[2])*
             sqrt(arr[3]*arr[3]+arr[4]*arr[4]+arr[5]*arr[5]);
     if(chis==0)
     {return 0;}
     return znam/chis;
 }
QString getStringForDeterminantExt(int * arr)
{
return QString("<table VALIGN=middle><tr><td ROWSPAN=2>=&nbsp;&nbsp;</td><td>") +
                        QString("%0").arg(arr[0])+"*" +QString("%0").arg(arr[4])+"*"+QString("%0").arg(arr[8])+
            "+"+QString("%0").arg(arr[1])+"*"+QString("%0").arg(arr[5])+"*"+QString("%0").arg(arr[6])+"+"+QString("%0").arg(arr[3])+
            "*"+QString("%0").arg(arr[7])+"*"+QString("%0").arg(arr[2])+")-</td><td ROWSPAN=2 VALIGN=middle >"+QString("&nbsp;&nbsp;=&nbsp;&nbsp;%0").arg(calculateDeterminantM3(arr))+ " </td></tr><tr><td>("
            +QString("%0").arg(arr[6])+"*"+QString("%0").arg(arr[4])+"*"+QString("%0").arg(arr[2])
            +"+"+QString("%0").arg(arr[3])+"*"+QString("%0").arg(arr[1])+"*"+QString("%0").arg(arr[8])
            +"+"+QString("%0").arg(arr[7])+"*"
            +QString("%0").arg(arr[5])+"*"
            +QString("%0").arg(arr[0])+
            ")</td></tr></table>" ;

}



















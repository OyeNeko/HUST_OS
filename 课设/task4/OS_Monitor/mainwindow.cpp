#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
: QMainWindow(parent)
, ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    cpu_usage=0;
    mem_usage=0;
    //ui->cpu_rate->setText(QString::number(usage,'f',10));

    QTimer*timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(update_current_time()));
    show_host_name();
    connect(timer,SIGNAL(timeout()),this,SLOT(show_cpu_info()));
    connect(timer,SIGNAL(timeout()),this,SLOT(show_mem_info()));

    timer->start(1000);
}



MainWindow::~MainWindow()
{
delete ui;
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    if(index==0){
        show_host_name();
    }
    if(index==1)
    {
        show_mem_info();
    }
    if(index==2)
    {

        show_cpu_info();
    }
    if(index==3)
    {
        show_proc_info();
    }
}


void MainWindow::update_current_time()
{
    //打印现在时间和运行时间
    QDateTime time;
    time.currentDateTime();
    QString strFormat="yyyy.M.d h:m:s";
    ui->now_time->setText(time.currentDateTime().toString(strFormat));
    int index=ui->tabWidget->currentIndex();
    if(index==0){
        struct sysinfo info;
        sysinfo(&info);
        struct tm *ptm=nullptr;
        ptm=gmtime(&info.uptime);
        char time_buf[30];
        sprintf(time_buf,"%02d:%02d:%02d",ptm->tm_hour,ptm->tm_min,ptm->tm_sec);
        ui->run_time->setText(QString(time_buf));

    }
}
void MainWindow::show_host_name()
{
    QString tempStr; //读取文件信息字符串
    QFile tempFile; //用于打开系统文件
    int pos; //读取文件的位置
    //int ok;
    tempFile.setFileName("/proc/cpuinfo"); //打开CPU信息文件
    if ( !tempFile.open(QIODevice::ReadOnly) )
    {
        QMessageBox::warning(this, tr("warning"), tr("The cpuinfo file can not open!"), QMessageBox::Yes);
        return;
    }
    char hostname[30];
    gethostname(hostname,30);
    ui->host_name->setText(hostname);

    struct sysinfo info;
    time_t cur_time=0;
    time_t boot_time=0;
    struct tm *ptm=nullptr;
    if(sysinfo(&info)) return;
    time(&cur_time);
    boot_time=cur_time-info.uptime;
    ptm=localtime(&boot_time);
    char start_time_buf[30];
    sprintf(start_time_buf,"%d.%d.%d %02d:%02d:%02d",ptm->tm_year+1900,ptm->tm_mon+1,ptm->tm_mday,
            ptm->tm_hour,ptm->tm_min,ptm->tm_sec);
    ui->start_time->setText(QString(start_time_buf));


    //循环读取文件内容，查找需要的信息
    while (1)
    {
        tempStr = tempFile.readLine();
        if (pos = tempStr.indexOf("model name"), pos != -1)
        {
            pos += 13;
            QString *cpu_name = new QString( tempStr.mid(pos, tempStr.length()-12) );
            ui->CPU_name->setText(*cpu_name);
            break;
        }
    }
    tempFile.close();


    tempFile.setFileName("/proc/version");
    if ( !tempFile.open(QIODevice::ReadOnly) )
    {
        QMessageBox::warning(this, tr("warning"), tr("The version file can not open!"), QMessageBox::Yes);
        return ;
    }
    tempStr = tempFile.readLine();

    int pos1 = tempStr.indexOf("(");
    QString *os_type = new QString( tempStr.mid(14, pos1-pos-2) );
    ui->sys_version->setText(*os_type);

    tempFile.close(); //关闭操作系统信息文件


}

void MainWindow::show_proc_info()
{
    QString tempStr; //读取文件信息字符串
    QFile tempFile; //用于打开系统文件
    int pos; //读取文件的位置

    ui->listWidget_process->clear();
    QDir qd("/proc");
    QStringList qsList = qd.entryList();
    QString qs = qsList.join("\n");
    QString id_of_pro;
    bool ok;
    int find_start = 3;
    int a, b;
    int nProPid; //进程PID
    QString proName; //进程名
    QString proState; //PPID
    QString proPri; //进程优先级
    QString proMem; //进程占用内存
    QListWidgetItem *title = new QListWidgetItem("PID\t" + QString::fromUtf8("名称") + "\t\t" +
                                                 QString::fromUtf8("PPID") + "\t" +
                                                 QString::fromUtf8("优先级") + "\t" +
                                                 QString::fromUtf8("占用内存"), ui->listWidget_process);
    //循环读取进程
    while (1)
    {
        //获取进程PID
        a = qs.indexOf("\n", find_start);
        b = qs.indexOf("\n", a+1);
        find_start = b;
        id_of_pro = qs.mid(a+1, b-a-1);
        nProPid = id_of_pro.toInt(&ok, 10);
        if(!ok)
        {
            break;
        }

        //打开PID所对应的进程状态文件
        tempFile.setFileName("/proc/" + id_of_pro + "/stat");
        if ( !tempFile.open(QIODevice::ReadOnly) )
        {
            QMessageBox::warning(this, tr("warning"), tr("The pid stat file can not open!"), QMessageBox::Yes);
            return;
        }
        tempStr = tempFile.readLine();
        if (tempStr.length() == 0)
        {
            break;
        }
        a = tempStr.indexOf("(");
        b = tempStr.indexOf(")");
        proName = tempStr.mid(a+1, b-a-1);
        proName.trimmed(); //删除两端的空格
        proState = tempStr.section(" ", 3, 3);
        proPri = tempStr.section(" ", 17, 17);
        proMem = tempStr.section(" ", 22, 22);

        QListWidgetItem *item = new QListWidgetItem(id_of_pro + "\t" +
                                                    proName + "\t" +
                                                    proState + "\t" +
                                                    proPri + "\t" +
                                                    proMem, ui->listWidget_process);
    tempFile.close();
    }

    //tempFile.close(); //关闭该PID进程的状态文件

}
void MainWindow::show_cpu_info()
{
    //读取CPU信息
    QProcess process;
    process.start("cat /proc/stat");
    process.waitForFinished();
    double used=0;
    double total=0;
    QString CPUStr=process.readLine(); //读取文件信息字符串
    CPUStr.replace('\n',' ');
    int head_pos=5;
    for(int i=0;i<10;i++)
    {

        int tail_pos=CPUStr.indexOf(' ',head_pos);
        QString tempstr=CPUStr.mid(head_pos,tail_pos-head_pos);
        total+=tempstr.toDouble();
        if(i<3||i>5)used+=tempstr.toDouble();
        head_pos=tail_pos+1;
    }
    if(total-cpu_total>0)
    {
        cpu_usage=(used-cpu_used)/(total-cpu_total)*100.0;
        //ui->cpu_rate->setText(QString::number(usage,'f',10));
        ui->progressBar_cpu->setValue(cpu_usage);
        cpu_used=used;
        cpu_total=total;
    }
    Add_CPU_Point();
    Update_CPU_Line();
}
void   MainWindow::Add_CPU_Point()
{
    int i;
    int size = ylist.size();
    if(size == 60)
    {
        ylist.pop_front();
    }
    if(size == 0)
    {
        for(i = 0; i < 59; i++)
        {
            ylist.push_back(0);
        }
    }

     ylist.push_back(cpu_usage);
}
void MainWindow::Update_CPU_Line()
{
    int count = 0;
    QPixmap pix(720, 300);
    QPainter painter(&pix);
    QPainterPath path;
    pix.fill(Qt::gray);
    QPen pen0;
    pen0.setColor(Qt::lightGray);
    painter.setPen(pen0);
    for(int i = 1; i < 4; i++)
    {
        painter.drawLine(QPointF(0,i*75), QPointF(701,i*75));
    }
    QPen pen;
    pen.setColor(QColor(255,140,0));
    pen.setWidth(2);
    painter.setPen(pen);
    QBrush brush;
    brush.setColor(QColor(255,165,0));
    brush.setStyle(Qt::Dense2Pattern);
    painter.setBrush(brush);
    QPolygonF pts;
    while(count < ylist.size()-1)
    {
       pts.push_back(QPointF(12*count, 300));
       pts.push_back(QPointF(12*count, 300-3.0*(ylist.value(count))));
       pts.push_back(QPointF(12*(count+1), 300-3.0*(ylist.value(count+1))));
       pts.push_back(QPointF(12*(count+1), 300));
       count++;
    }
    path.addPolygon(pts);
    painter.drawPath(path);
    ui->cpu_line->setPixmap(pix);
}
void MainWindow::show_mem_info()
{
    QFile tempFile;
    QDateTime time;
    QString tempStr;
    int pos;

    tempFile.setFileName("/proc/meminfo"); //打开内存信息文件
    if ( !tempFile.open(QIODevice::ReadOnly) )
    {
        QMessageBox::warning(this, tr("warning"), tr("The meminfo file can not open!"), QMessageBox::Yes);
        return ;
    }
    QString memTotal;
    QString memFree;
    QString memUsed;
    int nMemTotal, nMemFree, nMemUsed;
    while (1)
    {
        tempStr = tempFile.readLine();
        pos = tempStr.indexOf("MemTotal");
        if (pos != -1)
        {
            memTotal = tempStr.mid(pos+10, tempStr.length()-13);
            memTotal = memTotal.trimmed();
            nMemTotal = memTotal.toInt()/1024;
        }
        else if (pos = tempStr.indexOf("MemFree"), pos != -1)
        {
            memFree = tempStr.mid(pos+9, tempStr.length()-12);
            memFree = memFree.trimmed();
            nMemFree = memFree.toInt()/1024;
            break;
        }
    }

    nMemUsed = nMemTotal - nMemFree;

    memUsed = QString::number(nMemUsed, 10);
    memFree = QString::number(nMemFree, 10);
    memTotal = QString::number(nMemTotal, 10);
    mem_usage=nMemUsed*100/nMemTotal;
    ui->progressBar_mem->setValue(mem_usage);
    Add_mem_Point();
    Update_Mem_Line();
}
void MainWindow::Add_mem_Point()
{
    int i;
    int size = ylistM.size();
    if(size == 60)
    {
        ylistM.pop_front();
    }
    if(size == 0)
    {
        for(i = 0; i < 59; i++)
        {
            ylistM.push_back(0);
        }
    }

     ylistM.push_back(mem_usage);
}
void MainWindow::Update_Mem_Line()
{
    int count = 0;
    QPixmap pix(720, 300);
    QPainterPath path;
    QPainter painter(&pix);
    pix.fill(Qt::gray);
    QPen pen0;
    pen0.setColor(Qt::lightGray);
    painter.setPen(pen0);
    for(int i = 1; i < 3; i++)
    {
        painter.drawLine(QPointF(0,i*150), QPointF(720,i*150));
    }
    QPen pen;
    pen.setColor(QColor(160,32,240));
    pen.setWidth(2);
    painter.setPen(pen);
    QBrush brush;
    brush.setColor(QColor(147,112,219));
    brush.setStyle(Qt::Dense2Pattern);
    painter.setBrush(brush);
    QPolygonF pts;
    while(count < (ylistM.size()-1))
    {
       pts.push_back(QPointF(12*count, 300));
       pts.push_back(QPointF(12*count, 300-3.0*(ylistM.value(count))));
       pts.push_back(QPointF(12*(count+1), 300-3.0*(ylistM.value(count+1))));
       pts.push_back(QPointF(12*(count+1), 300));
       count++;
    }
    path.addPolygon(pts);
    painter.drawPath(path);
    ui->mem_line->setPixmap(pix);
}
void MainWindow::on_pushButton_2_clicked()
{
    show_proc_info();
}

void MainWindow::on_pushButton_3_clicked()
{
    QString tmpQstr="kill -9 "+proc_pid;
    QByteArray tmpC=tmpQstr.toLatin1();
    char* command=tmpC.data();
    system(command);

}

void MainWindow::on_listWidget_process_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    if(current!=nullptr)
    {
        QString st=current->text();
        int pos =st.indexOf('\t');
        proc_pid=st.mid(0,pos);
    }
    return;
}

void MainWindow::on_pushButton_clicked()
{
    QMessageBox box;
    if(box.question(NULL,"question","Do you want to reboot?"
                    ,QMessageBox::Yes|QMessageBox::No
                    ,QMessageBox::No)==QMessageBox::Yes)
    {
        system("shutdown -h now");
    }

}

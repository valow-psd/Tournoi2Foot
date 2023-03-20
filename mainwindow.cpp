#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mydb = QSqlDatabase::addDatabase("QMYSQL");
    mydb.setHostName("localhost");
    mydb.setDatabaseName("teams");
    mydb.setUserName("root");
    mydb.setPassword("password");

    //QSqlQuery query(mydb);

    if (mydb.open())
       {
            ui->db_text->setText("DB Connectée");
            qDebug() << "Database: connection ok";

       }
       else
       {
            ui->db_text->setText("DB Non-connectée");
           qDebug() << "Error: connection with database failed";
       }

/*
    query.prepare("CREATE TABLE IF NOT EXISTS teams ("
                  "id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,"
                  "nom_equipe TEXT,"
                  "victoires INTEGER NOT NULL DEFAULT 0,"
                  "nuls INTEGER NOT NULL DEFAULT 0,"
                  "defaites INTEGER NOT NULL DEFAULT 0);"
                  "INSERT INTO teams (id,nom_equipe,victoires,nuls,defaites) VALUES (1,'Paris SG',1,1,1);"
                  "INSERT INTO teams (id,nom_equipe,victoires,nuls,defaites) VALUES (2,'Man. United',2,1,0);"
                  "INSERT INTO teams (id,nom_equipe,victoires,nuls,defaites) VALUES (3,'Leeds',0,0,3);"
                  "INSERT INTO teams (id,nom_equipe,victoires,nuls,defaites) VALUES (4,'AS Saint-Etienne',2,1,0);"
                  "INSERT INTO teams (id,nom_equipe,victoires,nuls,defaites) VALUES (5,'RB Leipzig',3,0,0);");
    query.exec();
    */




}

MainWindow::~MainWindow()
{
    delete ui;

    if (mydb.open())
       {
        mydb.close();
    }
}

void MainWindow::on_button_ajouter_equipe_clicked()
{
    QString t_nom_equipe = ui->lineEdit_nom_equipe->text();

    if (mydb.open())
       {
            QSqlQuery query;

            query.prepare("INSERT INTO teams(nom_equipe) VALUES ('" + t_nom_equipe +"');");

            query.exec();
            //ui->db_text->setText("DB Connectée 2");
            //qDebug() << "Database: connection ok 2";

       }
       else
       {
               //ui->db_text->setText("DB Non-connectée 2");
               qDebug() << "Error: connection with database failed 2";
               mydb.close();
       }


    QMessageBox::information(this, "Ajout équipe", QString("L'équipe " + t_nom_equipe + " a été ajoutée !"));
}


void MainWindow::on_loadTable_clicked()
{

    QSqlQueryModel *modal = new QSqlQueryModel();

    QSqlQuery* query = new QSqlQuery(mydb);


    query->prepare("SELECT nom_equipe, victoires, nuls, defaites, (victoires * 3 + nuls) as points FROM teams ORDER BY points DESC;");
    query->exec();

    modal->setQuery(*query);

    ui->tableView->setModel(modal);

    qDebug() << (modal->rowCount());


}

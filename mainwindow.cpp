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
    mydb.setDatabaseName("teams_ekip");
    mydb.setUserName("ekip");
    mydb.setPassword("lefootccool");

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

void MainWindow::on_button_ajouter_equipe_2_clicked()
{
    QString t_nom_equipe = ui->lineEdit_nom_equipe->text();

    if (mydb.open())
       {
            QSqlQuery query;

            query.prepare("DELETE FROM `teams` WHERE nom_equipe LIKE '" +t_nom_equipe +  "';");

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


    QMessageBox::information(this, "Suppression équipe", QString("L'équipe " + t_nom_equipe + " a été supprimée !"));
}

void MainWindow::on_pushButton_clicked()
{
   // QString t_nom_equipe = ui->lineEdit_nom_equipe->text();

    if (mydb.open())
       {
            QSqlQueryModel *modal = new QSqlQueryModel();

            QSqlQuery* q = new QSqlQuery(mydb);


            q->prepare("SELECT nom_equipe, victoires, nuls, defaites, (victoires * 3 + nuls) as points FROM teams ORDER BY points DESC;");
            q->exec();

            modal->setQuery(*q);

            ui->tableView->setModel(modal);

            int num = modal->rowCount();

            //qDebug() << (modal->rowCount());

            int random = rand() % num;
            //int random2 = rand() % num;

            QSqlQuery query;

            for(int i = 1; i <= num * 3; i++){
                if(random == 1){
                        query.prepare("UPDATE teams SET victoires = victoires +1 WHERE id = 1 OR id = 6; ");
                        query.exec();

                }
                else if(random == 2){
                        query.prepare("UPDATE teams SET victoires = victoires +1 WHERE id = 3 OR id = 5; ");
                        query.exec();
                }
                else if(random == 3){
                       query.prepare("UPDATE teams SET defaites = defaites +1 WHERE id = 3 OR id = 5; ");
                       query.exec();
                }
                else if(random == 5){
                    query.prepare("UPDATE teams SET victoires = victoires +1 WHERE id = 2 OR id = 4; ");
                    query.exec();
                }
                else if(random == 4){
                        query.prepare("UPDATE teams SET nuls = nuls +1 WHERE id = 3 OR id = 5; ");
                        query.exec();
                }
                else if(random == 6) {
                    query.prepare("UPDATE teams SET nuls = nuls +1 WHERE id = 1 OR id = 6; ");
                    query.exec();
                }
                else if(random == 7) {
                    query.prepare("UPDATE teams SET nuls = nuls +1 WHERE id = 2 OR id = 4; ");
                    query.exec();
                }
                else if(random == 8) {
                    query.prepare("UPDATE teams SET defaites = defaites +1 WHERE id = 1 OR id = 2; ");
                    query.exec();
                }
                else if(random == 9) {
                    query.prepare("UPDATE teams SET defaites = defaites +1 WHERE id = 4 OR id = 6; ");
                    query.exec();
                }
                else {
                    query.prepare("UPDATE teams SET victoires = victoires + 1 WHERE id = 5;" "UPDATE teams SET defaites = defaites + 1 WHERE id = 1;");
                    query.exec();
                }
            }

/*
            for(int i = 1; i < 6; i++){
                //i.toString();
                QSqlQuery query;
                if(i == 1){
                    qDebug() << "Victoires";
                    query.prepare("UPDATE teams SET victoires = victoires +1 WHERE id = 1 OR id = 6; ");
                    query.exec();
                    qDebug() << query.exec("UPDATE teams SET victoires = victoires +1 WHERE id = 1;");
                }
                else if(i == 2) {
                    qDebug() << "defaites";
                    query.prepare("UPDATE teams SET defaites = defaites +1 WHERE id = 2;");
                    query.exec();
                    qDebug() << query.exec("UPDATE teams SET defaites = defaites +1 WHERE id = 2;");
                }
                else{
                    qDebug() << "nuls";
                    query.prepare("UPDATE teams SET nuls = nuls +1 WHERE id = 3 OR id = 4 OR id = 5; ");
                    query.exec();
                    qDebug() << query.exec("UPDATE teams SET nuls = nuls +1 WHERE id = 3 OR id = 4 OR id = 5;");
                }


            }
            */

       }
       else
       {
               //ui->db_text->setText("DB Non-connectée 2");
               qDebug() << "Error: connection with database failed 2";
               mydb.close();
       }


    QMessageBox::information(this, "Tirage", QString("Le tournoi est fini !"));
}

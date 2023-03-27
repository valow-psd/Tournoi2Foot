#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QString>
#include <QDir>
#include <list>
#include <random>

bool MainWindow::in(std::list<int> mylist, int val)
{
    for (int ele : mylist)
    {
        if (ele == val)
        {
            return true;
        }
    }
    return false;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QDir dir;
    qDebug() << dir.absoluteFilePath("teams.db");

    // Si utilisation de SQLite en local
    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName(dir.absoluteFilePath("teams.db"));

    if (mydb.open())
    {
        ui->db_text->setText("DB Connectée");
        qDebug() << "Database: connection ok";
        MainWindow::on_loadTable_clicked();

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

        query.prepare("INSERT INTO teams(nom_equipe) VALUES ('" + t_nom_equipe + "');");

        query.exec();
        MainWindow::on_loadTable_clicked();
        // ui->db_text->setText("DB Connectée 2");
        // qDebug() << "Database: connection ok 2";
    }
    else
    {
        // ui->db_text->setText("DB Non-connectée 2");
        qDebug() << "Error: connection with database failed 2";
        mydb.close();
    }

    QMessageBox::information(this, "Ajout équipe", QString("L'équipe " + t_nom_equipe + " a été ajoutée !"));
}

void MainWindow::on_loadTable_clicked()
{

    QSqlQueryModel *modal = new QSqlQueryModel();

    QSqlQuery *query = new QSqlQuery(mydb);

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

        query.prepare("DELETE FROM `teams` WHERE nom_equipe LIKE '" + t_nom_equipe + "';");

        query.exec();

        MainWindow::on_loadTable_clicked();
        // ui->db_text->setText("DB Connectée 2");
        // qDebug() << "Database: connection ok 2";
    }
    else
    {
        // ui->db_text->setText("DB Non-connectée 2");
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

        QSqlQuery *q = new QSqlQuery(mydb);

        q->prepare("SELECT nom_equipe, victoires, nuls, defaites, (victoires * 3 + nuls) as points FROM teams ORDER BY points DESC;");
        q->exec();

        modal->setQuery(*q);

        ui->tableView->setModel(modal);

        int num = modal->rowCount();

        // qDebug() << num;
        // qDebug() << (modal->rowCount());
        if (num % 2 != 0)
        {
            QMessageBox::information(this, "Tirage", QString("Impossible de lancer un tournoi , il faut un nombre paire d'equipe"));
            return;
        }
        srand(time(NULL));
        // qDebug() << time(NULL);
        QSqlQuery query;
        query.prepare("SELECT id FROM teams");
        query.exec();
        std::list<int> ids;
        std::list<int> tirer;

        // ajout de tous les id dans une liste
        while (query.next())
        {
            int id = query.value(0).toInt();
            ids.push_back(id);
            // qDebug() << id << "toto";
        }
        // creation du random et tirage aléatoire
        std::random_device rd;  // Will be used to obtain a seed for the random number engine
        std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
        std::uniform_int_distribution<> distrib(0, ids.size());
        std::uniform_int_distribution<> distrib_nul(0, 1);
        for (int i = 0; i < num / 2; i++)
        {

            if (distrib_nul(gen) == 0)
            { // cas d'une victoire et d'une defaite
                // ajout de la vicoire
                std::list<int>::iterator it = ids.begin();
                std::advance(it, distrib(gen));
                // ajout des point a la bdd
                int id_winner = int(*it);
                qDebug() << MainWindow::in(tirer, id_winner) << tirer << id_winner;
                while (MainWindow::in(tirer, id_winner))
                {
                    it = ids.begin();
                    std::advance(it, distrib(gen));
                    id_winner = int(*it);

                }
                query.prepare("UPDATE teams SET victoires = victoires +1 WHERE id = ?; ");
                query.bindValue(0, id_winner);
                query.exec();
                tirer.push_back(id_winner);

                // ajoute de la defaite
                it = ids.begin();
                std::advance(it, distrib(gen));
                // ajout des point a la bdd
                int id_defaite = int(*it);
                qDebug() << MainWindow::in(tirer, id_defaite) << tirer << id_defaite;
                while (MainWindow::in(tirer, id_defaite))
                {
                    it = ids.begin();
                    std::advance(it, distrib(gen));
                    id_defaite = int(*it);

                }
                // qDebug() << id_winner ;
                query.prepare("UPDATE teams SET defaites = defaites +1 WHERE id = ?; ");
                query.bindValue(0, id_defaite);
                query.exec();
                tirer.push_back(id_defaite);
            }
            else
            { // cas de l'egaliter
                for (int i = 0; i < 2; i++)
                {
                    std::list<int>::iterator it = ids.begin();
                    std::advance(it, distrib(gen));
                    // ajout des point a la bdd
                    int id_premier = int(*it);
                    qDebug() << MainWindow::in(tirer, id_premier) << tirer << id_premier;

                    while (MainWindow::in(tirer, id_premier))
                    {
                        it = ids.begin();
                        std::advance(it, distrib(gen));
                        id_premier = int(*it);

                    }
                    query.prepare("UPDATE teams SET nuls = nuls +1 WHERE id = ?; ");
                    query.bindValue(0, id_premier);
                    query.exec();
                    tirer.push_back(id_premier);
                }
            }

    }
    }else
    {
        // ui->db_text->setText("DB Non-connectée 2");
        qDebug() << "Error: connection with database failed 2";
        mydb.close();
    }
    MainWindow::on_loadTable_clicked();

    // QMessageBox::information(this, "Tirage", QString("Le tournoi est fini !"));
}




void MainWindow::on_pushButton_2_clicked()
{
    QSqlQuery query;
    query.prepare("UPDATE teams SET victoires =0 , defaites=0 , nuls=0; ");
    query.exec();
    MainWindow::on_loadTable_clicked();


}

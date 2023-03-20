#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QVariant>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE



class MainWindow : public QMainWindow
{

       Q_OBJECT


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_button_ajouter_equipe_clicked();

    void on_loadTable_clicked();

    void on_button_ajouter_equipe_2_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase mydb;
};
#endif // MAINWINDOW_H

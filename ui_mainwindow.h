/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QLabel *label;
    QLineEdit *lineEdit_nom_equipe;
    QPushButton *button_ajouter_equipe;
    QPushButton *loadTable;
    QLabel *db_text;
    QTableView *tableView;
    QPushButton *button_ajouter_equipe_2;
    QPushButton *pushButton_2;
    QMenuBar *menubar;
    QMenu *menuSoker;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(894, 371);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(150, 210, 151, 25));
        pushButton->setMaximumSize(QSize(151, 25));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(690, 50, 171, 17));
        label->setMaximumSize(QSize(171, 17));
        lineEdit_nom_equipe = new QLineEdit(centralwidget);
        lineEdit_nom_equipe->setObjectName(QString::fromUtf8("lineEdit_nom_equipe"));
        lineEdit_nom_equipe->setGeometry(QRect(690, 70, 171, 25));
        lineEdit_nom_equipe->setMaximumSize(QSize(171, 25));
        button_ajouter_equipe = new QPushButton(centralwidget);
        button_ajouter_equipe->setObjectName(QString::fromUtf8("button_ajouter_equipe"));
        button_ajouter_equipe->setGeometry(QRect(710, 110, 121, 25));
        button_ajouter_equipe->setMaximumSize(QSize(121, 25));
        loadTable = new QPushButton(centralwidget);
        loadTable->setObjectName(QString::fromUtf8("loadTable"));
        loadTable->setGeometry(QRect(330, 210, 131, 25));
        loadTable->setMaximumSize(QSize(131, 25));
        db_text = new QLabel(centralwidget);
        db_text->setObjectName(QString::fromUtf8("db_text"));
        db_text->setGeometry(QRect(20, 300, 191, 17));
        db_text->setMaximumSize(QSize(191, 17));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(40, 10, 541, 192));
        tableView->setMaximumSize(QSize(541, 192));
        button_ajouter_equipe_2 = new QPushButton(centralwidget);
        button_ajouter_equipe_2->setObjectName(QString::fromUtf8("button_ajouter_equipe_2"));
        button_ajouter_equipe_2->setGeometry(QRect(700, 140, 151, 25));
        button_ajouter_equipe_2->setMaximumSize(QSize(151, 25));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(770, 300, 83, 25));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 894, 22));
        menuSoker = new QMenu(menubar);
        menuSoker->setObjectName(QString::fromUtf8("menuSoker"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuSoker->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Ligue 2 - Cochonou", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "Simuler le tournoi", nullptr));
        label->setText(QApplication::translate("MainWindow", "Entrez le nom de l'\303\251quipe", nullptr));
        button_ajouter_equipe->setText(QApplication::translate("MainWindow", "+ Ajouter \303\251quipe", nullptr));
        loadTable->setText(QApplication::translate("MainWindow", "Synchroniser", nullptr));
        db_text->setText(QApplication::translate("MainWindow", "[DB connexion ...]", nullptr));
        button_ajouter_equipe_2->setText(QApplication::translate("MainWindow", "- Supprimer \303\251quipe", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        menuSoker->setTitle(QApplication::translate("MainWindow", "Soker", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

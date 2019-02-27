#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <taskorganizercontroller.h>
#include <QHash>
#include <QPushButton>

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class QListWidgetItem;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(TaskOrganizerController *controller ,QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void createEntry();
    void deleteEntry();
    void editEntry();
    void saveEntry();
    void discardEntry();
    void resetEntry();

private:
    Ui::MainWindow *ui;
    TaskOrganizerController *m_controller;
    QHash<QListWidgetItem*, TaskOrganizerEntry*> m_entryMap;

    void setupConnections();
};

#endif // MAINWINDOW_H

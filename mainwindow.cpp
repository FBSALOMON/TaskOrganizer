#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(TaskOrganizerController *controller, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_controller(controller)
{
    Q_ASSERT(controller != nullptr);
    ui->setupUi(this);
    setupConnections();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createEntry()
{
    auto entry = m_controller->createEntry();
    if (entry) {
        ui->listWidget->addItem(entry->name());
        auto listItem = ui->listWidget->item(ui->listWidget->count() - 1);
        m_entryMap.insert(listItem, entry);
    }
}

void MainWindow::deleteEntry()
{
    auto listItem = ui->listWidget->currentItem();
    if (listItem) {
        auto entry = m_entryMap.value( listItem );
        if(entry) {
            if( m_controller->deleteEntry(entry)) {
                m_entryMap.remove(listItem);
                delete listItem;
            }
        }
    }
}

void MainWindow::editEntry()
{
    auto listItem = ui->listWidget->currentItem();
    if (listItem) {
        auto entry = m_entryMap.value( listItem );
        if(entry) {
            ui->stackedWidget->setCurrentWidget(ui->detailPage);
            ui->menuEntries->setEnabled( false );
            resetEntry();
        }
    }
}

void MainWindow::saveEntry()
{
    auto listItem = ui->listWidget->currentItem();
    if (listItem) {
        auto entry = m_entryMap.value( listItem );
        if(entry) {
            entry->setName(ui->nameEdit->text());
            entry->setDate(ui->dateEdit->date());
            entry->setExam(ui->examEdit->currentText());
            entry->setPhone(ui->phoneEdit->text());
            entry->setStatus(ui->statusEdit->currentText());
            entry->setEmail(ui->emailEdit->text());
            entry->setCE(ui->ceEdit->isChecked());
            entry->setCO(ui->coEdit->isChecked());
            entry->setEE(ui->eeEdit->isChecked());
            entry->setEO(ui->eoEdit->isChecked());
            entry->setQCM(ui->qcmEdit->isChecked());
            listItem->setText(entry->name() +  "     " + entry->exam() + "     " + entry->status());
            discardEntry();
        }
    }
}

void MainWindow::discardEntry()
{
    ui->stackedWidget->setCurrentWidget(ui->listPage);
    ui->menuEntries->setEnabled(true);
}

void MainWindow::resetEntry()
{
    auto listItem = ui->listWidget->currentItem();
    if (listItem) {
        auto entry = m_entryMap.value( listItem );
        if(entry) {
            ui->nameEdit->setText(entry->name());
            ui->dateEdit->setDate(entry->date());
            ui->examEdit->setCurrentIndex(ui->examEdit->findText(entry->exam()));
            ui->phoneEdit->setText(entry->phone());
            ui->statusEdit->setCurrentIndex(ui->statusEdit->findText(entry->status()));
            ui->emailEdit->setText(entry->email());
            ui->ceEdit->setChecked(entry->CE());
            ui->eeEdit->setChecked(entry->EE());
            ui->coEdit->setChecked(entry->CO());
            ui->eoEdit->setChecked(entry->EO());
            ui->qcmEdit->setChecked(entry->QCM());
        }
    }
}

void MainWindow::setupConnections()
{
    connect(ui->actionAdd, SIGNAL(triggered(bool)),this, SLOT(createEntry()));
    connect( ui->actionRemove, &QAction::triggered, this, &MainWindow::deleteEntry);
    connect(ui->actionEdit, &QAction::triggered,this, &MainWindow::editEntry);
    connect(ui->buttonBox->button(QDialogButtonBox::Save), &QPushButton::clicked, this , &MainWindow::saveEntry);
    connect(ui->buttonBox->button(QDialogButtonBox::Discard), &QPushButton::clicked, this , &MainWindow::discardEntry);
    connect(ui->buttonBox->button(QDialogButtonBox::Reset), &QPushButton::clicked, this , &MainWindow::resetEntry);
}

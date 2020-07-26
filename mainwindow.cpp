#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <fstream>
#include <vector>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    updateDotFile();
    updateImage();
    renderImage();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateDotFile()
{
    std::ofstream myFile;
    QDir::setCurrent(QCoreApplication::applicationFilePath());
    myFile.open
    (
        "file.dot"
    );

    std::string textToFile = "digraph g{";
    textToFile += "head[shape=none fontcolor=blue];";
    textToFile += "tail[shape=none fontcolor=blue];";

    textToFile += "{rank=same; head tail};";

    std::string names;

    auto vec = queue.getElementsAsVector();
    for (int index = 0; index < vec.size(); ++index)
    {
        auto entry = vec.at(index);
        textToFile += entry;
        names += entry+" ";

        if (index < vec.size()-1)
            textToFile += "->";
    }

    if (vec.size() == 0)
    {
        textToFile += "NULL [ fontcolor=red ];head -> NULL; tail -> NULL";
        textToFile += ";";
    }
    else
    {
        textToFile += ";";
        textToFile += "head -> "+vec.at(0)+";";
        textToFile += "tail -> "+vec.at(vec.size()-1)+";";

        textToFile += "{rank=same; ";
        textToFile += names;
        textToFile += "}";
    }

    textToFile += "}";

    myFile << textToFile;
    myFile.close();
}

void MainWindow::updateImage()
{
    std::string message =
                "dot -Tpng file.dot > file.png";
    QDir::setCurrent(QCoreApplication::applicationFilePath());
    system(message.c_str());
}

void MainWindow::renderImage()
{
    QDir::setCurrent(QCoreApplication::applicationFilePath());
    QPixmap image("file.png");
    ui->labelOfImage->setPixmap(image);
    ui->labelOfImage->show();
}

void MainWindow::on_pushButton_clicked()
{
    std::string data = ui->lineEdit->text().toStdString();

    queue.insert(data);

    updateDotFile();
    updateImage();
    renderImage();

    ui->lineEdit->setText("");
}

void MainWindow::on_pushButton_2_clicked()
{
    NodeOfQueue * node = queue.remove();
    if (node != nullptr)
        delete node;

    updateDotFile();
    updateImage();
    renderImage();
}

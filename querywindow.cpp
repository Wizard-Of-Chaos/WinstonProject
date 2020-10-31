#include "querywindow.h"
#include <QWidget>
#include <QPushButton>
#include <QtSql>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QTableWidget>

QueryWindow::QueryWindow() : QWidget()
{
	authorEdit = new QLineEdit;
	titleEdit = new QLineEdit;
	callEdit = new QLineEdit;
	submitButton = new QPushButton(tr("Submit"));
	authorLabel = new QLabel(tr("Author: "));
	titleLabel = new QLabel(tr("Title: "));
	callLabel = new QLabel(tr("Call : "));
	fullView = new QTableWidget;

	gridLayout = new QGridLayout;
	gridLayout->addWidget(authorLabel, 0, 0);
	gridLayout->addWidget(titleLabel, 1, 0);
	gridLayout->addWidget(callLabel, 2, 0);

	gridLayout->addWidget(authorEdit, 0, 1);
	gridLayout->addWidget(titleEdit, 1, 1);	
	gridLayout->addWidget(callEdit, 2, 1);

	gridLayout->addWidget(submitButton, 3, 1);
	gridLayout->addWidget(fullView, 0, 2, 3, 1);
       	setLayout(gridLayout);

	QTableWidgetItem* header1 = new QTableWidgetItem ("ISBN");
	QTableWidgetItem* header2 = new QTableWidgetItem ("Title");
	QTableWidgetItem* header3 = new QTableWidgetItem ("Author");
	QTableWidgetItem* header4 = new QTableWidgetItem ("Call #");
	QTableWidgetItem* header5 = new QTableWidgetItem ("Pages");
		
	fullView->setColumnCount(5);
	fullView->setHorizontalHeaderItem(0, header1);
	fullView->setHorizontalHeaderItem(1, header2);
	fullView->setHorizontalHeaderItem(2, header3);
	fullView->setHorizontalHeaderItem(3, header4);
	fullView->setHorizontalHeaderItem(4, header5);
	
	connect(submitButton, SIGNAL(clicked()), this, SLOT(submit()));
}

QueryWindow::~QueryWindow()
{
	delete authorEdit; 
	delete titleEdit;
	delete callEdit;
	delete submitButton;
	delete authorLabel;
	delete titleLabel;
	delete callLabel;
	delete fullView;
	delete gridLayout;
}

void QueryWindow::submit()
{
  	int count = 0;
        QSqlQuery* window_query = new QSqlQuery;
	QString title = titleEdit->text();
	QString author = authorEdit->text();
	QString callNum = callEdit->text();
	if (title.isEmpty() == false)
	{
        	window_query->prepare("SELECT ISBN, Title, Author, Call_Number, Pages FROM Book WHERE Title = ?;");
		window_query->addBindValue(title);
	}
	else if (author.isEmpty() == false)
	{	
        	window_query->prepare("SELECT ISBN, Title, Author, Call_Number, Pages FROM Book WHERE Author = ?;");
		window_query->addBindValue(author);
	}
	else if (callNum.isEmpty() == false)
	{
        	window_query->prepare("SELECT ISBN, Title, Author, Call_Number, Pages FROM Book WHERE Call_Number = ?;");
		window_query->addBindValue(callNum);
	}
	window_query->exec();
	while(window_query->next())
	{
		QTableWidgetItem* isbnItem = new QTableWidgetItem(window_query->value(0).toString());
		QTableWidgetItem* titleItem = new QTableWidgetItem(window_query->value(1).toString());
		QTableWidgetItem* authorItem = new QTableWidgetItem(window_query->value(2).toString());
		QTableWidgetItem* callNumItem = new QTableWidgetItem(window_query->value(3).toString());
		QTableWidgetItem* pagesItem = new QTableWidgetItem(window_query->value(4).toString());
		fullView->insertRow(count);
		fullView->setItem(count, 0, isbnItem);
		fullView->setItem(count, 1, titleItem);
		fullView->setItem(count, 2, authorItem);
		fullView->setItem(count, 3, callNumItem);
		fullView->setItem(count, 4, pagesItem);
		++count;
		qDebug() << "got here" << count;
	}
}

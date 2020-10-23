#include <iostream>
#include "window.h"
#include "query.h"
#include <QVBoxLayout>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QAction>
#include <QInputDialog>
#include <QLineEdit>
#include <QMessageBox>
#include <QtGui>
#include <QApplication>
#include <QLabel>
#include <QDockWidget>

//Include tower mark three. Direct all complaints about its height to:
//Alexander Wiecking, Michael Eddins, or Grant Kelly

Window::Window() : QMainWindow()
{
	m_layout = new QVBoxLayout;
	m_toolbar = new QToolBar(this);
	addToolBar(m_toolbar);
	m_submit = new QAction(tr("Submit"));
	m_query = new QAction(tr("Query"));
	m_quit = new QAction(tr("Quit"));
	m_forward = new QAction(tr("Next"));
	m_back = new QAction(tr("Previous"));

	m_toolbar->addSeparator();
	m_toolbar->addAction(m_submit);
	m_toolbar->addAction(m_query);
	m_toolbar->setMovable(false);
	m_toolbar->addSeparator();
	m_toolbar->addAction(m_forward);
	m_toolbar->addAction(m_back);
	m_toolbar->addSeparator();
	m_toolbar->addAction(m_quit);
	m_toolbar->addSeparator();

	m_db = QSqlDatabase::addDatabase("QSQLITE");
	m_db.setDatabaseName("library.db");
	m_db.open();
	m_type = "Book";
	QSqlQuery q;
	q.exec("SELECT ISBN, Title, Author, Call_Number, Pages FROM Book;");
	q.first();
	m_f1 = new QLabel(q.value(0).toString());
	m_f2 = new QLabel(q.value(1).toString());
	m_f3 = new QLabel(q.value(2).toString());
	m_f4 = new QLabel(q.value(3).toString());
	m_f5 = new QLabel(q.value(4).toString());
	Query* display = new Query(m_f1, m_f2, m_f3, m_f4, m_f5);
	m_pos = 0;

	connect(m_submit, SIGNAL(triggered()), this, SLOT(submit()));
	connect(m_query, SIGNAL(triggered()), this, SLOT(query()));
	connect(m_quit, SIGNAL(triggered()), this, SLOT(close()));
	connect(m_forward, SIGNAL(triggered()), this, SLOT(forward()));
	connect(m_back, SIGNAL(triggered()), this, SLOT(back()));
	this->layout()->setMenuBar(m_toolbar);
	setCentralWidget(display);
	this->show();
}

Window::~Window()
{
}
void Window::query()
{
}
void Window::submit()
{
}
void Window::forward()
{
	QSqlQuery q;
	q.exec("SELECT ISBN, Title, Author, Call_Number, Pages FROM Book;");
	q.first();
	++m_pos;
	int count = 0;
	while(q.next()) {
		++count;
		if (count == m_pos) break;
	}
	if(count != m_pos) return;
	m_f1 = new QLabel(q.value(0).toString());
	m_f2 = new QLabel(q.value(1).toString());
	m_f3 = new QLabel(q.value(2).toString());
	m_f4 = new QLabel(q.value(3).toString());
	m_f5 = new QLabel(q.value(4).toString());
	Query* display = new Query(m_f1, m_f2, m_f3, m_f4, m_f5);
	setCentralWidget(display);
}
void Window::back()
{
	QSqlQuery q;
	q.exec("SELECT ISBN, Title, Author, Call_Number, Pages FROM Book;");
	q.first();
	--m_pos;
	if (m_pos < 0) {
		m_pos = 0;
	}
	int count = 0;
	while(q.next()) {
		if (count == m_pos) break;
		++count;
	}
	if(count != m_pos) return;
	m_f1 = new QLabel(q.value(0).toString());
	m_f2 = new QLabel(q.value(1).toString());
	m_f3 = new QLabel(q.value(2).toString());
	m_f4 = new QLabel(q.value(3).toString());
	m_f5 = new QLabel(q.value(4).toString());
	Query* display = new Query(m_f1, m_f2, m_f3, m_f4, m_f5);
	setCentralWidget(display);
}

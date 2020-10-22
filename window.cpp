#include <iostream>
#include "window.h"
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
	
	m_toolbar->addSeparator();
	m_toolbar->addAction(m_submit);
	m_toolbar->addAction(m_query);
	m_toolbar->setMovable(false);
	m_toolbar->addSeparator();
	m_toolbar->addAction(m_quit);
	m_toolbar->addSeparator();

	m_forward = new QPushButton(tr("Next"));
	m_back = new QPushButton(tr("Previous"));
	
	connect(m_submit, SIGNAL(triggered()), this, SLOT(submit()));
	connect(m_query, SIGNAL(triggered()), this, SLOT(query()));
	connect(m_forward, SIGNAL(clicked()), this, SLOT(forward()));
	connect(m_back, SIGNAL(clicked()), this, SLOT(back()));
	this->layout()->setMenuBar(m_toolbar);
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
}
void Window::back()
{
}

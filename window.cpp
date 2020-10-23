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
#include <QDialogButtonBox>
#include <QFormLayout>

//Include tower mark three. Direct all complaints about its height to:
//Alexander Wiecking, Michael Eddins, or Grant Kelly

Window::Window() : QMainWindow()
{
	m_layout = new QVBoxLayout;
	m_toolbar = new QToolBar(this);
	addToolBar(m_toolbar);
	m_submit = new QAction(tr("Submit"));
	m_querybutton = new QAction(tr("Query"));
	m_quit = new QAction(tr("Quit"));

	m_forward = new QAction(tr("Next"));
	m_back = new QAction(tr("Previous"));

	m_toolbar->addSeparator();
	m_toolbar->addAction(m_submit);
	m_toolbar->addAction(m_querybutton);
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
	m_query = new QSqlQuery;
	m_query->exec("SELECT ISBN, Title, Author, Call_Number, Pages FROM Book;");
	m_query->first();
	m_f1 = new QLabel(m_query->value(0).toString());
	m_f2 = new QLabel(m_query->value(1).toString());
	m_f3 = new QLabel(m_query->value(2).toString());
	m_f4 = new QLabel(m_query->value(3).toString());
	m_f5 = new QLabel(m_query->value(4).toString());
	m_display = new Query(m_f1, m_f2, m_f3, m_f4, m_f5);
	m_pos = 0;

	connect(m_submit, SIGNAL(triggered()), this, SLOT(submit()));
	connect(m_querybutton, SIGNAL(triggered()), this, SLOT(query()));
	connect(m_quit, SIGNAL(triggered()), this, SLOT(close()));
	connect(m_forward, SIGNAL(triggered()), this, SLOT(forward()));
	connect(m_back, SIGNAL(triggered()), this, SLOT(back()));
	this->layout()->setMenuBar(m_toolbar);
	setCentralWidget(m_display);
	this->show();
}

Window::~Window()
{
}
void Window::query()
{
	bool ok;
	QString search_val = QInputDialog::getText(this, tr("Search"), tr("Enter in the name, isbn, author, call number or pagecount of a book and we'll try and find it for you. [UNIMPLEMENTED]"), QLineEdit::Normal, QDir::home().dirName(), &ok);
	//do some stuff with the search value later
}
void Window::submit() //This is gonna be some arcane shenanigans.
{
	QDialog dialog(this);
	QFormLayout val_submit(&dialog);
	QList<QLineEdit*> fields;
	QLineEdit* isbn_val = new QLineEdit(&dialog);
	QLineEdit* title_val = new QLineEdit(&dialog);
	QLineEdit* author_val = new QLineEdit(&dialog);
	QLineEdit* call_val = new QLineEdit(&dialog);
	QLineEdit* page_val = new QLineEdit(&dialog);

	val_submit.addRow(tr("ISBN:"), isbn_val);
	val_submit.addRow(tr("Title:"), title_val);
	val_submit.addRow(tr("Author:"), author_val);
	val_submit.addRow(tr("Call number:"), call_val);
	val_submit.addRow(tr("Pagecount:"), page_val);
	QDialogButtonBox buttons(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal, &dialog);
	val_submit.addRow(&buttons);
	QObject::connect(&buttons, SIGNAL(accepted()), &dialog, SLOT(accept()));
	QObject::connect(&buttons, SIGNAL(rejected()), &dialog, SLOT(reject()));

	if(dialog.exec() == QDialog::Accepted) {
		int isbn = isbn_val->text().toInt();
		QString title = title_val->text();
		QString author = author_val->text();
		QString call = call_val->text();
		int page = isbn_val->text().toInt();
		QSqlQuery q;
		q.prepare("INSERT INTO Book(ISBN, Title, Author, Call_Number, Pages)"
			"VALUES(?, ?, ?, ?, ?);");
		q.addBindValue(isbn);
		q.addBindValue(title);
		q.addBindValue(author);
		q.addBindValue(call);
		q.addBindValue(page);
		q.exec();
	}
}
void Window::forward()
{
	if(!m_query->next()) return;
	m_f1->setText(m_query->value(0).toString());
	m_f2->setText(m_query->value(1).toString());
	m_f3->setText(m_query->value(2).toString());
	m_f4->setText(m_query->value(3).toString());
	m_f5->setText(m_query->value(4).toString());
}
void Window::back()
{
	if(!m_query->previous()) return;
	m_f1->setText(m_query->value(0).toString());
	m_f2->setText(m_query->value(1).toString());
	m_f3->setText(m_query->value(2).toString());
	m_f4->setText(m_query->value(3).toString());
	m_f5->setText(m_query->value(4).toString());
}

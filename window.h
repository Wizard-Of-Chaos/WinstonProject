#include <QMainWindow>
#include <QWidget>
#include <QToolBar>
#include <QAction>
#include <QPushButton>
#include <QtSql>
#include <string>
#include "query.h"

#ifndef __WINDOW_H
#define __WINDOW_H

class QueryWindow;
class QVBoxLayout;
class QMouseEvent;
class QMenuBar;
class QMenu;
class QLabel;

class Window : public QMainWindow
{
	Q_OBJECT
	private:
		QToolBar* m_toolbar;
		QAction* m_submit;
		QAction* m_querybutton;
		QAction* m_quit;
		QAction* m_forward;
		QAction* m_back;
		QVBoxLayout* m_layout;
		QSqlDatabase m_db;
		QLabel* m_f1;
		QLabel*	m_f2;
		QLabel* m_f3;
		QLabel* m_f4;
		QLabel* m_f5;
		Query* m_display;
		QSqlQuery* m_query;
		int m_pos;
		std::string m_type;	

	private slots:
		void query();
		void submit();
		void forward();
		void back();
		
	public:
		Window();
		~Window();
};


#endif


#include <QMainWindow>
#include <QWidget>
#include <QToolBar>
#include <QAction>
#include <QPushButton>

#ifndef __WINDOW_H
#define __WINDOW_H

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
		QAction* m_query;
		QAction* m_quit;
		QPushButton* m_forward;
		QPushButton* m_back;
		QVBoxLayout* m_layout;

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


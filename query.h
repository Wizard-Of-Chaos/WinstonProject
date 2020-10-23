#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

#ifndef __QUERY_H
#define __QUERY_H

class Query : public QWidget
{
	Q_OBJECT 

	private:
		QLabel* m_f1;
		QLabel* m_f2;
		QLabel* m_f3;
		QLabel* m_f4;
		QLabel* m_f5;
	public:
		Query(QLabel* f1, QLabel* f2, QLabel* f3, QLabel* f4, QLabel* f5);
		Query(QLabel* f1, QLabel* f2);
		~Query();
};

#endif

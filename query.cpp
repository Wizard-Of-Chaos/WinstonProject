#include "query.h"
#include <QVBoxLayout>
#include <QLabel>

Query::Query(QLabel* f1, QLabel* f2)
{
	m_f1 = f1;
	m_f2 = f2;
	m_f3 = new QLabel(" ");
	m_f4 = new QLabel(" ");
	m_f5 = new QLabel(" ");
	QVBoxLayout* layout = new QVBoxLayout;
	layout->addWidget(m_f1);
	layout->addWidget(m_f2);
	layout->addWidget(m_f3);
	layout->addWidget(m_f4);
	layout->addWidget(m_f5);
	setLayout(layout);
}

Query::Query(QLabel* f1, QLabel* f2, QLabel* f3, QLabel* f4, QLabel* f5)
{
	m_f1 = f1;
	m_f2 = f2;
	m_f3 = f3;
	m_f4 = f4;
	m_f5 = f5;
	QVBoxLayout* layout = new QVBoxLayout;
	layout->addWidget(m_f1);
	layout->addWidget(m_f2);
	layout->addWidget(m_f3);
	layout->addWidget(m_f4);
	layout->addWidget(m_f5);
	setLayout(layout);
}

Query::~Query()
{
}

#include "query.h"
#include <QVBoxLayout>

Query::Query(QTableWidgetItem* f1, QTableWidgetItem* f2, QPushButton* next, QPushButton* prev)
{
	m_table = new QTableWidget;
	QVBoxLayout* layout = new QVBoxLayout;
	m_table->setColumnCount(2);
	m_table->setHorizontalHeaderItem(0, f1);
	m_table->setHorizontalHeaderItem(1, f2);
	layout->addWidget(m_table);
	layout->addWidget(next);
	layout->addWidget(prev);
	setLayout(layout);
}

Query::Query(QTableWidgetItem* f1, QTableWidgetItem* f2, QTableWidgetItem* f3, QTableWidgetItem* f4, QTableWidgetItem* f5, QPushButton* next, QPushButton* prev)
{
	m_table = new QTableWidget;
	QVBoxLayout* layout = new QVBoxLayout;
	m_table->setColumnCount(5);
	m_table->setHorizontalHeaderItem(0, f1);
	m_table->setHorizontalHeaderItem(1, f2);
	m_table->setHorizontalHeaderItem(2, f3);
	m_table->setHorizontalHeaderItem(3, f4);
	m_table->setHorizontalHeaderItem(4, f5);
	layout->addWidget(m_table);
	layout->addWidget(next);
	layout->addWidget(prev);
	setLayout(layout);
}

Query::~Query()
{
	delete m_table;
}

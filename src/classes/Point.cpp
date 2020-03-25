#include "Point.h"
#include "Board.h"
#include <iostream>


using namespace std;

Point::Point()
{
    m_x = m_y = 10;
	m_char ='*';            //@ a mettre ici apres 
}
Point::Point(int x, int y)
{
    this->m_x = x;
    this->m_y = y;
	m_char = '*';
}

Point::Point(int x, int y, char caractere)
{
    this->m_x = x;
    this->m_y = y;
	m_char = caractere;
}

Point::Point(char caractere)
{
	m_char = caractere;
}



void Point::setPoint(int x, int y)
{
    this->m_x = x;
    this->m_y = y;
}

void Point::moveDown()
{
    m_y++;
}

void Point::moveUp()
{
    m_y--;
}

void Point::moveRight()
{
    m_x++;
}
void Point::moveLeft()
{
    m_x--;
}

int Point::getX() const
{
    return m_x;
}


void Point::setX(int val)
{
    m_x = val;
}

int Point::getY() const
{
    return m_y;
}

void Point::setY(int val)
{
    m_y = val;
}

//Sert a mettre les points.
void Point::drawPoint()
{
    Board *b;
    b = Board::getInstance(); // dessine les points
    b->dessinerPoint(*this);
}

//Sert a effacer les points.
void Point::erasePoint()
{
    Board *b;
    b = Board::getInstance(); //efface les points
    b->effacerPoint(*this);
}

void Point::debug()
{
    cout << "(" << this->m_x << "," << this->m_y << ")";
}

//Setter du char
void Point::setChar(char caractere){
    m_char=caractere;
}

//Getter du char
char Point::getChar(){
    return m_char;
}    

Point::~Point()
{
    //dtor
}



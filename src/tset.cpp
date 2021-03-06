// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tset.cpp - Copyright (c) Гергель В.П. 04.10.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Множество - реализация через битовые поля

#include "tset.h"

TSet::TSet(int mp) : BitField(mp)
{
	maxPower = mp;
}

// конструктор копирования
TSet::TSet(const TSet &s) : BitField(s.BitField)
{
	maxPower = s.maxPower;
}

// конструктор преобразования типа
TSet::TSet(const TBitField &bf) : BitField (bf)
{
	maxPower = bf.GetLength();
}

TSet::operator TBitField()
{
	return BitField;
}

int TSet::GetMaxPower(void) const // получить макс. к-во эл-тов
{
	return maxPower;
}

int TSet::IsMember(const int Elem) const // элемент множества?
{
	return BitField.GetBit(Elem);
}

void TSet::InsElem(const int Elem) // включение элемента множества
{
	BitField.SetBit(Elem);
}

void TSet::DelElem(const int Elem) // исключение элемента множества
{
	BitField.ClrBit(Elem);
}

// теоретико-множественные операции

TSet& TSet::operator=(const TSet &s) // присваивание
{
	if (&s == this)
		return *this;
	BitField = s.BitField;
	maxPower = s.maxPower;
	return *this;
}

int TSet::operator==(const TSet &s) const // сравнение
{
	return BitField == s.BitField;
}

int TSet::operator!=(const TSet &s) const // сравнение
{
	return BitField != s.BitField;
}

TSet TSet::operator+(const TSet &s) // объединение
{
	TSet temp(BitField | s.BitField);
	return temp;
}

TSet TSet::operator+(const int Elem) // объединение с элементом
{
	if ((Elem < 0) || (Elem > maxPower))
		throw "Element doesn't belong to the set";
	TSet temp(BitField);
	temp.BitField.SetBit(Elem);
	return temp;

}

TSet TSet::operator-(const int Elem) // разность с элементом
{
	if ((Elem < 0) || (Elem > maxPower))
		throw "Element doesn't belong to the set";
	TSet temp(BitField);
	temp.BitField.ClrBit(Elem);
	return temp;
}

TSet TSet::operator*(const TSet &s) // пересечение
{
	TSet temp(BitField);
	temp.BitField = temp.BitField & s.BitField;
	return temp;

}

TSet TSet::operator~(void) // дополнение
{
	TSet temp(maxPower);
	temp.BitField = ~BitField;
	return temp;
}

// перегрузка ввода/вывода

istream &operator>>(istream &istr, TSet &s) // ввод
{
	int i;
	istr >> i;
	while ((i > -1) && (i < s.maxPower)) {
		s.BitField.SetBit(i);
		istr >> i;
	}
	return istr;
}

ostream& operator<<(ostream &ostr, const TSet &s) // вывод
{
	for (int i = 0; i < s.maxPower; i++) {
		if (s.BitField.GetBit(i) == 1)
			ostr << i << endl; 
	}
	return ostr;
}

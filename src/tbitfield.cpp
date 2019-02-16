// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#include "tbitfield.h"

TBitField::TBitField(int len)
{
	if (len < 0)
		throw ("Lenght is incorrect");
	bitLen = len;
	memLen = (len + 31) >> 5;
	pMem = new TELEM[memLen];
	for (int i = 0; i < memLen; i++) {
		pMem[i] = 0;
	}
}

TBitField::TBitField(const TBitField &bf) // конструктор копирования
{
	bitLen = bf.bitLen;
	memLen = bf.memLen;
	pMem = new TELEM[memLen];
	for (int i = 0; i < memLen;i++)
		pMem[i] = bf.pMem[i];
}

TBitField::~TBitField()
{
	delete[] pMem;
	bitLen = 0;
	memLen = 0;

}

int TBitField::GetMemIndex(const int n) const // индекс Мем для бита n
{
	return n >> 5;
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
	return 1 << (n & 31);
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
  return bitLen;
}

void TBitField::SetBit(const int n) // установить бит
{
	if ((n < 0) || (n > bitLen))
		throw ("Number is incorrect");
	if ((n > -1) && (n < bitLen)) {
		pMem[GetMemIndex(n)] |= GetMemMask(n);
	}
}

void TBitField::ClrBit(const int n) // очистить бит
{
	if ((n < 0) || (n > bitLen))
		throw ("Number is incorrect");
	if ((n > -1) && (n < bitLen)) {
		pMem[GetMemIndex(n)] &= ~GetMemMask(n);
	}
}

int TBitField::GetBit(const int n) const // получить значение бита
{
	if ((n < 0) || (n > bitLen))
		throw ("Number is incorrect");
	if ((n > -1) && (n < bitLen)) {
		return (pMem[GetMemIndex(n)] & GetMemMask(n))>>(n & 31);
	}
}

// битовые операции

TBitField& TBitField::operator=(const TBitField &bf) // присваивание
{
	if (&bf == this)
		return *this;
	bitLen = bf.bitLen;
	if (memLen != bf.memLen)
	{
		memLen = bf.memLen;
		if (pMem != NULL)
			delete [] pMem;
		pMem = new TELEM[memLen];
	}
	if (pMem != NULL)
		for (int i = 0; i < memLen; i++)
			pMem[i] = bf.pMem[i];
	return *this;
}

int TBitField::operator==(const TBitField &bf) const // сравнение
{
	if (bitLen != bf.bitLen)
		return 0;
	for (int i = 0; i < memLen; i++) {
		if (pMem[i] != bf.pMem[i])
			return 0;
	}
	return 1;
}

int TBitField::operator!=(const TBitField &bf) const // сравнение
{
	return !(*this == bf);
}

TBitField TBitField::operator|(const TBitField &bf) // операция "или"
{
	int i, len = bitLen;
	if (bf.bitLen > len)
		len = bf.bitLen;
	TBitField tmp(len);
	for (i = 0; i < memLen; i++)
		tmp.pMem[i] = pMem[i];
	for (i = 0; i < bf.memLen; i++)
		tmp.pMem[i] |= bf.pMem[i];
	return tmp;
}

TBitField TBitField::operator&(const TBitField &bf) // операция "и"
{
	int i, len = bitLen;
	if (bf.bitLen > len)
		len = bf.bitLen;
	TBitField tmp(len);
	for (i = 0; i < memLen; i++)
		tmp.pMem[i] = pMem[i];
	for (i = 0; i < bf.memLen; i++)
		tmp.pMem[i] &= bf.pMem[i];
	return tmp;
}

TBitField TBitField::operator~(void) // отрицание
{
	TBitField tmp(bitLen);
	for (int i = 0; i < bitLen; i++) {
		if (this->GetBit(i) == 0)
			tmp.SetBit(i);
	}
	return tmp;
}

// ввод/вывод

istream &operator>>(istream &istr, TBitField &bf) // ввод
{
	char* s = new char[bf.bitLen];
	istr >> s;
	for (int k = 0; k < bf.bitLen; k++)
		bf.ClrBit(k);
	int i = 0;
	while (s[i] != '\0') {
		if (s[i] == '1')
			bf.SetBit(i);
		i++;
	}
	delete[] s;
	return istr;
}

ostream &operator<<(ostream &ostr, const TBitField &bf) // вывод
{
	for (int i = 0; i < bf.bitLen; i++) {
		if (i % 8 == 0)
			ostr << " ";
		if (i % 32 == 0)
			ostr << endl;
		ostr << bf.GetBit(i);
	}
	return ostr;
}
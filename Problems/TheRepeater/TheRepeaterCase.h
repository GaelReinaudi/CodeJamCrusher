#ifndef TheRepeaterCase_H
#define TheRepeaterCase_H

#include "GoogleCase.h"
#include <QTextStream>

class TheRepeaterCase;

QString SolveCase(const TheRepeaterCase & Case);
///dont forget to add 1, 2, 3 manually
class Pal012 
{
public:
	Pal012(int firstdig = 0)
		: pal(26, 0)
		, even(firstdig == 0 ? true : false)
		, sum2(2)
		, needSkimToEven(false)
		, has2rest(false)
	{
		if(firstdig == 0)
			pal[0] = 1;
		else
			pal[0] = firstdig;
	}
	char SumSq() {
		char m = pal[0];
 		return sum2 - (even?0:(m*m));
		char s = 0;
		for(int i = 0; i < 26 ; i++) {
			s += pal[i] << 1;
		}
		return 2 * s - even?0:(pal[0]<<1);
	}

	void beNext() {
		if(even) {
			for(int i = 0; i < 26 ; i++) {
				{
					switch(pal[i])
					{
					case 0:{
						if(SumSq() > 7)
							break;
						pal[i] = 1;
						sum2 += 2;
						return;
						   }
					case 1:{
						if(SumSq() > 3){
							pal[i] = 0;
							sum2 -= 2;
							break;
						}
						pal[i] = 2;
						sum2 += 6;
						has2rest = true;
						return;
						   }
					case 2:{
						pal[i] = 0;
						sum2 -= 8;
						even = false;
						has2rest = false;
						break;
						   }
					}
				}
			}
		}
		else {
			switch(pal[0])
			{
			case 0:{
				if(SumSq() > 8)
					break;
				pal[0] = 1;
				sum2 += 2;
				return;
				   }
			case 1:{
				if(SumSq() > 6){
					pal[0] = 0;
					sum2 -= 2;
					break;
				}
				pal[0] = 2;
				sum2 += 6;
				return;
				   }
			case 2:{
				pal[0] = 0;
				sum2 -= 8;
				break;
				   }
			}
			for(int i = 1; i < 26 ; i++) {
				{
					switch(pal[i])
					{
					case 0:{
						if(SumSq() > 7)
							break;
						pal[i] = 1;
						sum2 += 2;
						goto skim;
						   }
					case 1:{
						if(SumSq() > 3){
							pal[i] = 0;
							sum2 -= 2;
							break;
						}
						pal[i] = 2;
						sum2 += 6;
						has2rest = true;
						return;
						   }
					case 2:{
						pal[i] = 0;
						sum2 -= 8;
						even = true;
						has2rest = false;
						needSkimToEven = true;
						break;
						   }
					}
				}
			}
skim:
			if(needSkimToEven) {
				needSkimToEven = false;
				for(int i = 0; i < 25 ; i++) {
					pal[i] = pal[i+1];
				}
			}
		}
	}
	bool done() {return pal[26];}

	quint64 debug() {
		quint64 pten = 1;
		quint64 ret = 0;
		for(int i = 0; i < 26 ; i++) {
			ret += pal[i] * pten;
			pten *= 10;
		}
		return ret;
	}
	
	QByteArray thePal() {
		QByteArray aa(50, 0);
		for(int i = 0; i < 25 ; i++) {
			if(even) {
				aa[24 - i] = pal[i];
				aa[25 + i] = pal[i];
			}
			else {
				aa[24 - i] = pal[i];
				aa[24 + i] = pal[i];
			}
		}
		QByteArray ret(50, 0);
		bool zerosSoFar = true;
		int retJ = 0;
		for(int i = 0; i < 50 ; i++) {
			if(aa[i] || !zerosSoFar) {
				zerosSoFar = false;
				ret[retJ] = aa[i];
				retJ++;
			}
		}
		return ret;
	}

	bool needSkimToEven;
	bool has2rest;
	QByteArray pal;
	bool even;
	char sum2;
};

typedef int Line[4];
typedef Line Grid[4];

class TheRepeaterCase : public GoogleCase
{
public:
	TheRepeaterCase();
	~TheRepeaterCase() {}

	//! Re-implemented
	void ParseCase(QTextStream & inputStream);
	QString Solve() const;

	mutable QString m_SolString;
	void compute(QTextStream & out) const;
	bool pair(int val) const {return val % 2 == 0;}

	inline bool Calc(qulonglong n) const;
	inline bool CanDo() const;
	inline qulonglong BinarySearch( long double Min, long double Max ) const;
	int r,t;
	mutable int N;
	mutable QStringList strings;
};

#endif // TheRepeaterCase_H

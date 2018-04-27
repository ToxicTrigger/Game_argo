#pragma once

#ifndef _SWAP
#define swap(a,b,t){ t = a; a = b; b = t;}
#endif

class Sort
{
private:
public:
	virtual void sort(int* Datas, int Size) = 0;
};
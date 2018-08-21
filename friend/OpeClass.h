//OpeClass.h
#pragma once
class OpeClass
{
    friend OpeClass& operator <<(const OpeClass& xx);
public:
    OpeClass(void);
    OpeClass(int x,int y);
    ~OpeClass(void);
private:
    int width;
    int height;
};


#include <iostream>
#include <cmath>

using namespace std;

const int NtoU=30,NtoE=40;

class bankacc
{
public:
    bankacc(const int ntd,const int usd,const int eud);
    bankacc operator+(const bankacc&);
    bankacc operator-(const bankacc&);
    bankacc operator*(const bankacc&);
    bankacc operator%(const bankacc&);
    bankacc operator/(const bankacc&);
    int setNTD(const int ntd);
    int setUSD(const int usd);
    int setEUD(const int eud);
    double valueINNTD();
    double valueINUSD();
    double valueINEUD();
    void output();
private:
    int ntd,usd,eud;
};

bankacc bankacc::operator+(const bankacc&that)
{
    return(this->ntd+that.ntd,
           this->usd+that.usd,
           this->eud+that.eud);
}
bankacc bankacc::operator-(const bankacc&that)
{
    return(this->ntd-that.ntd,
           this->usd-that.usd,
           this->eud-that.eud);
}
bankacc bankacc::operator%(const bankacc&that)
{
    return(abs(this->ntd-that.ntd),
           abs(this->usd-that.usd),
           abs(this->eud-that.eud));
}
bankacc bankacc::operator*(const bankacc&that)
{
    return(this->ntd+0.99*that.ntd,
           this->usd+0.99*that.usd,
           this->eud+0.99*that.eud);
}
bankacc bankacc::operator/(const bankacc&that)
{
    return(this->ntd-1.01*that.ntd,
           this->usd-1.01*that.usd,
           this->eud-1.01*that.eud);
}
int bankacc::setNTD(const int ntd)
{
    this->ntd=ntd;
}
int bankacc::setUSD(const int usd)
{
    this->usd=usd;
}
int bankacc::setEUD(const int eud)
{
    this->eud=eud;
}
void bankacc::output()
{
    valueINNTD();
    valueINUSD();
    valueINEUD();
}
double bankacc::valueINNTD()
{
    int vntd;
    vntd=this->ntd+this->usd*NtoU+this*NtoE;
}
double bankacc::valueINUSD()
{

}
double bankacc::valueINEUD()
{

}

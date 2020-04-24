#include <iostream>
#include <cmath>

using namespace std;
const int UtoN=30,EtoN=40;
double vntd,vusd,veud;

class bankacc
{
public:
    bankacc(const int ntd,const int usd,const int eud)
    {
        setNTD(ntd);
        setUSD(usd);
        setEUD(eud);
    }
    bankacc operator+(const bankacc& that);
    bankacc operator-(const bankacc& that);
    bankacc operator*(const bankacc& that);
    bankacc operator%(const bankacc& that);
    bankacc operator/(const bankacc& that);
    int reset(const int ntd,const int usd,const int eud);
    int setNTD(const int ntd);
    int setUSD(const int usd);
    int setEUD(const int eud);
    double valueINNTD();
    double valueINUSD();
    double valueINEUD();
    void output();
private:
    double ntd=0,usd=0,eud=0;
};

bankacc bankacc::operator+(const bankacc& that)
{
    this->ntd+=that.ntd;
    this->usd+=that.usd;
    this->eud+=that.eud;
    return bankacc(this->ntd,this->usd,this->eud);
}
bankacc bankacc::operator-(const bankacc& that)
{
    this->ntd-=that.ntd;
    this->usd-=that.usd;
    this->eud-=that.eud;
    return bankacc(this->ntd,this->usd,this->eud);
}
bankacc bankacc::operator%(const bankacc& that)
{
    this->ntd=abs(this->ntd-that.ntd);
    this->usd=abs(this->usd-that.usd);
    this->eud=abs(this->eud-that.eud);
    return bankacc(this->ntd,this->usd,this->eud);
}
bankacc bankacc::operator*(const bankacc& that)
{
    this->ntd+=0.99*that.ntd;
    this->usd+=0.99*that.usd;
    this->eud+=0.99*that.eud;
    return bankacc(this->ntd,this->usd,this->eud);
}
bankacc bankacc::operator/(const bankacc& that)
{
    this->ntd-=1.01*that.ntd;
    this->usd-=1.01*that.usd;
    this->eud-=1.01*that.eud;
    return bankacc(this->ntd,this->usd,this->eud);
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
    cout << "NTD:";
    valueINNTD();
    cout << " USD:";
    valueINUSD();
    cout << " EUD:";
    valueINEUD();
    cout << endl;
}
double bankacc::valueINNTD()
{
    vntd=this->ntd+this->usd*UtoN+this->eud*EtoN;
    cout << vntd;
}
double bankacc::valueINUSD()
{
    vusd=vntd/30;
    cout << vusd;
}
double bankacc::valueINEUD()
{

    veud=vntd/40;
    cout << veud;
}
int bankacc::reset(const int ntd,const int usd,const int eud)
{
    setNTD(ntd);
    setUSD(usd);
    setEUD(eud);
}

int main()
{
    double x, y, z, a, b, c;
    cin >> x >> y >> z >> a >> b >> c;
    bankacc acct1(x,y,z),acct2(a,b,c);
    acct1.output();
    acct2.output();

    acct1 + acct2;
    cout << "+:";
    acct1.output();

    acct1.reset(x,y,z);
    acct1 - acct2;
    cout << "-:";
    acct1.output();

    acct1.reset(x,y,z);
    acct1%acct2;
    cout << "%:";
    acct1.output();

    acct1.reset(x,y,z);
    acct1*acct2;
    cout << "*:";
    acct1.output();

    acct1.reset(x,y,z);
    acct1/acct2;
    cout << "/:";
    acct1.output();

    return 0;
}

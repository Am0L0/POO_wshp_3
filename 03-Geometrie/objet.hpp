#ifndef OBJET_HPP
#define OBJET_HPP

class Objet
{
public:
    virtual ~Objet() {}
    virtual double aire() const = 0;
    virtual double perimetre() const = 0;
    virtual void afficheInfo() const = 0;
};

#endif
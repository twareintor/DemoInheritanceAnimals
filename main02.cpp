//g++  4.9.3
//clang 3.7.0
//Microsoft (R) C/C++ Optimizing Compiler Version 19.00.23506 for x86

#include <iostream>
#include <string.h>

class CAnimal
{
public:
    virtual void eat(){}
    virtual void speak(){}
    virtual void setName(const char*){}
    virtual const char* getName(){return 0;}
    virtual void setId(int id){}
    virtual int getId(){return 0;}
    virtual bool isDangerous(){return false;}
    virtual bool isEndangered(){return false;}
    
   
};

class CHerbivore: public virtual CAnimal
{
public:
    void eat() override {std::cout<<"I am eating vegetal food"<<std::endl;}
   
};

class CCarnivore: public virtual CAnimal
{
public:
    void eat() override {std::cout<<"I am eating animal food"<<std::endl;}
   
};

class COmnivore: public virtual CHerbivore, public virtual CCarnivore
{
public:
    void eat() override {std::cout<<"I am eating any kind of food"<<std::endl;}
   
};

class CWild: public virtual CAnimal
{
protected:
    bool m_bEndangered;
    bool m_bDangerous;
public:
    virtual bool isDangerous(){return m_bDangerous;}
    virtual bool isEndangered(){return m_bEndangered;}
   
};

class CDomestic: public virtual CAnimal
{
protected:
    int m_id;
public:
    CDomestic(): m_id(0){}
    virtual void setId(int id){m_id = id;}
    virtual int getId(){return m_id;}
   
};

class CPet: public virtual CAnimal
{
protected:
    char* m_szName;
public:
    CPet(): m_szName(new char[0xff]){}
    ~CPet(){if(m_szName) delete[] m_szName;}
    virtual void setName(const char* szName){strcpy(m_szName, szName);}
    virtual const char* getName(){return m_szName;}
   
};

class CDog final: public CCarnivore, public CPet, public CDomestic
{
public:
    void speak(){std::cout<<"Woh woh!"<<std::endl;}
   
};

class CPig final: public COmnivore, CDomestic
{
public:
    void speak(){std::cout<<"Groh groh!"<<std::endl;}
};

class CWolf final: public virtual CWild, public virtual CCarnivore
{
public:
    CWolf(){m_bDangerous = true; m_bEndangered = false;}
    void speak(){std::cout<<"Huuuuu, uuu!"<<std::endl;}
};


int main()
{
    int i = 0;
    CAnimal* myAnimal = new CDog();
    myAnimal->setName("Dixi");
    goto SUB_SHOW_20192 ;
    
DEF_ANIMAL001:
    myAnimal = new CPig();
    myAnimal->setName("Gixi");
    goto SUB_SHOW_20192 ;
    
DEF_ANIMAL002:
    myAnimal = new CWolf();
    myAnimal->setName("Wixi");
    goto SUB_SHOW_20192 ;

SUB_SHOW_20192:    
    myAnimal->eat();
    myAnimal->speak();
    myAnimal->setId(24);
    if(myAnimal->isDangerous()) std::cout<<"Beware!"<<std::endl;
    if(myAnimal->isEndangered()) std::cout<<"Help my species!"<<std::endl;
    if(myAnimal->getId()) std::cout<<"My ID is "<<myAnimal->getId()<<std::endl;
    if(myAnimal->getName()) std::cout<<"My name is "<<myAnimal->getName()<<std::endl;
    std::cout<<"$$$ $$$ $$$"<<std::endl;
    i++;
    if(1==i) goto DEF_ANIMAL001 ;
    if(2==i) goto DEF_ANIMAL002 ;
    
    delete myAnimal;
    std::cout << "Hello, world!\n";
}


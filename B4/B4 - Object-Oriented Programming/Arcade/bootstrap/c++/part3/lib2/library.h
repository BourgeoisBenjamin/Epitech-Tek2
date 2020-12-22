#ifndef LIB2_LIBRARY_H
#define LIB2_LIBRARY_H

#include "../lib1/library.h"

class lib2 : public IDisplayModule
{
public:
    lib2();
    ~lib2();
    virtual void init();
    virtual void stop();
    virtual const std::string &getName() const;
private:
    const std::string _name;
    lib2 *test;
};

#endif //LIB2_LIBRARY_H

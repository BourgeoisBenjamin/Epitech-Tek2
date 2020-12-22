#ifndef LIB1_LIBRARY_H
#define LIB1_LIBRARY_H

#include <string>

class IDisplayModule
{
    public :
        virtual ~IDisplayModule() = default;
        virtual void init() = 0;
        virtual void stop() = 0;
        virtual const std::string &getName() const = 0;
};

#include "../lib2/library.h"

class lib1 : public IDisplayModule
{
    public:
        lib1();
        ~lib1();
        virtual void init();
        virtual void stop();
        virtual const std::string &getName() const;
    private:
        const std::string _name;
        lib2 *test;
};

#endif //LIB1_LIBRARY_H

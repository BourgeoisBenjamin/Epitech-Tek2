#include "graphics/NcursesMode.hpp"
#include "DateModule.hpp"
#include "UserModule.hpp"
#include "OSModule.hpp"
#include "CPUModule.hpp"

NcursesMode::NcursesMode()
{
}

NcursesMode::~NcursesMode()
{
}

void NcursesMode::displayCPUModule(CPUModule const &module)
{
    int i = 0;
    std::vector<CPUDataFinal> tmp= module.getCPUUsage();

    for (i = 0; i <= module.getCoreNumber(); i++) {
        mvwprintw(_cpu, i + 1, 1,"%s : %s", tmp[i].cpu.c_str(), tmp[i]._activepourcent.c_str());
        mvwprintw(_cpu, i + 1, 12, " / %s", tmp[i]._idlepourcent.c_str());
    }

    mvwprintw(_cpu, i + 2, 1,"Active tasks : %d", module.getActiveTasks());
    mvwprintw(_cpu, i + 3, 1,"Model CPU : %s", module.getModelName().c_str());
    box(_cpu, ACS_VLINE, ACS_HLINE);
    wnoutrefresh(_cpu);
}

void NcursesMode::displayDateModule(DateModule const &module)
{
    mvwprintw(_date, 1, 1,"%s", module.getDate().c_str());
    mvwprintw(_date, 2, 1,"%s", module.getTime().c_str());
    box(_date, ACS_VLINE, ACS_HLINE);
    wnoutrefresh(_date);
}

void NcursesMode::displayOSModule(OSModule const &module)
{
    mvwprintw(_os, 1, 1, "Operating System:");
    mvwprintw(_os, 2, 1, module.getOSName().c_str());
    mvwprintw(_os, 3, 1, "Kernel:");
    mvwprintw(_os, 4, 1, module.getKernelVersion().c_str());
    box(_os, ACS_VLINE, ACS_HLINE);
    wnoutrefresh(_os);
}

void NcursesMode::displayRAMModule(RAMModule const &module)
{
    mvwprintw(_ram, 1, 1,"RAM (GB): %s / %s", module.getRamUsed().c_str(), module.getRamTotal().c_str());
    mvwprintw(_ram, 2, 1,"RAM (%): %s", module.getPcRamUsed().c_str());
    mvwprintw(_ram, 3, 1,"SWAP (GB): %s / %s", module.getSwapUsed().c_str(), module.getSwapTotal().c_str());
    box(_ram, ACS_VLINE, ACS_HLINE);
    wnoutrefresh(_ram);
}

void NcursesMode::displayUserModule(UserModule const &module)
{
    mvwprintw(_identity, 1, 1, "User name:");
    mvwprintw(_identity, 2, 1, module.getUsername().c_str());
    mvwprintw(_identity, 3, 1, "Hostname:");
    mvwprintw(_identity, 4, 1, module.getHostname().c_str());
    mvwprintw(_identity, 5, 1, "Home:");
    mvwprintw(_identity, 6, 1, module.getHome().c_str());
    mvwprintw(_identity, 7, 1, "Uptime:");
    mvwprintw(_identity, 8, 1, module.getUptime().c_str());
    box(_identity, ACS_VLINE, ACS_HLINE);

    wnoutrefresh(_identity);
}

void NcursesMode::setWindow()
{
    this->setDate(subwin(stdscr, 4, COLS / 8, 0, 0));
    this->setIdentity(subwin(stdscr, 14, COLS / 8, 4, 0));
    this->setOs(subwin(stdscr, 18, COLS / 8, 0, COLS - COLS / 8));
    this->setCPU(subwin(stdscr, 18, COLS - (COLS / 8 ) - (COLS / 8), 0, (COLS / 8 )));
    this->setRam(subwin(stdscr, 5, COLS, 18, 0));
}

void NcursesMode::setDate(WINDOW* tmp)
{
    _date = tmp;
}

void NcursesMode::setIdentity(WINDOW *tmp)
{
    _identity = tmp;
}

void NcursesMode::setOs(WINDOW *tmp)
{
    _os = tmp;
}

void NcursesMode::setCPU(WINDOW *tmp)
{
    _cpu = tmp;
}

void NcursesMode::setRam(WINDOW *tmp)
{
    _ram = tmp;
}
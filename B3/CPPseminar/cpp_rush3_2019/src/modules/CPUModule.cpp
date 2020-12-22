/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** TODO: add description
*/

#include "../../include/CPUModule.hpp"
#include <vector>
#include <fstream>
#include <iomanip>
#include <chrono>
#include <thread>

#include <iostream>

CPUModule::CPUModule() : _name("CPU")
{
    this->setCPUUsage();
}

CPUModule::~CPUModule()
{
}

CPUModule::CPUModule(const CPUModule &copy) : _name(copy._name)
{
    this->setCPUUsage();
}

CPUModule& CPUModule::operator=(const CPUModule &rhs)
{
    (void)rhs;
    this->setCPUUsage();
    return *this;
}

const std::string & CPUModule::getModuleName() const
{
    return _name;
}

bool CPUModule::refreshInfoModule()
{
    this->setCPUUsage();
    return true;
}

void CPUModule::readStatsCPU1()
{
    std::ifstream fileStat("/proc/stat");
    std::string line;

    const std::string STR_CPU("cpu");
    const std::size_t LEN_STR_CPU = STR_CPU.size();
    const std::string STR_TOT("tot");

    while(std::getline(fileStat, line)) {
        if(!line.compare(0, LEN_STR_CPU, STR_CPU)) {
            std::istringstream ss(line);

            _cores1.emplace_back(CPUData());
            CPUData & core = _cores1.back();

            ss >> core.cpu;

            if(core.cpu.size() > LEN_STR_CPU)
                core.cpu.erase(0, LEN_STR_CPU);
            else
                core.cpu = STR_TOT;

            for(int i = 0; i < NUM_CPU_STATES; i++)
                ss >> core.times[i];

            core._idle = core.times[S_IDLE] + core.times[S_IOWAIT];
            core._active = core.times[S_USER] + core.times[S_NICE] + core
                .times[S_SYSTEM] + core.times[S_IRQ] + core.times[S_SOFTIRQ]
                + core.times[S_STEAL] + core.times[S_GUEST] + core
                .times[S_GUESTNICE];
        }
    }
}

void CPUModule::readStatsCPU2()
{
    std::ifstream fileStat("/proc/stat");
    std::string line;

    const std::string STR_CPU("cpu");
    const std::size_t LEN_STR_CPU = STR_CPU.size();
    const std::string STR_TOT("tot");

    while(std::getline(fileStat, line)) {
        if(!line.compare(0, LEN_STR_CPU, STR_CPU)) {
            std::istringstream ss(line);

            _cores2.emplace_back(CPUData());
            CPUData & core = _cores2.back();

            ss >> core.cpu;

            if(core.cpu.size() > LEN_STR_CPU)
                core.cpu.erase(0, LEN_STR_CPU);
            else
                core.cpu = STR_TOT;

            for(int i = 0; i < NUM_CPU_STATES; i++)
                ss >> core.times[i];

            core._idle = core.times[S_IDLE] + core.times[S_IOWAIT];
            core._active = core.times[S_USER] + core.times[S_NICE] + core
                .times[S_SYSTEM] + core.times[S_IRQ] + core.times[S_SOFTIRQ]
                           + core.times[S_STEAL] + core.times[S_GUEST] + core
                               .times[S_GUESTNICE];
        }
    }
}

void CPUModule::setPourcentageUsage()
{
    const size_t NUM_ENTRIES = _cores1.size();
    std::ostringstream out;
    for(size_t i = 0; i < NUM_ENTRIES; i++) {
        const CPUData &e1 = _cores1[i];
        const CPUData &e2 = _cores2[i];
        const float ACTIVE_TIME = static_cast<float>(e2._active - e1._active);
        const float IDLE_TIME = static_cast<float>(e2._idle - e1._idle);
        const float TOTAL_TIME = ACTIVE_TIME + IDLE_TIME;

        _CPUUsage.emplace_back(CPUDataFinal());
        CPUDataFinal &coreUsage = _CPUUsage.back();

        coreUsage.cpu = e1.cpu;

        if (100.f * ACTIVE_TIME / TOTAL_TIME > 100)
            coreUsage._activepourcent = std::string("100%");
        else {
            out << std::setprecision(2) << (100.f * ACTIVE_TIME / TOTAL_TIME);
            coreUsage._activepourcent = std::string(out.str() + "%");
        }
        out.str("");
        if (100.f * IDLE_TIME / TOTAL_TIME)
            coreUsage._idlepourcent = std::string("100%");
        else {
            out << std::setprecision(2) << (100.f * IDLE_TIME / TOTAL_TIME);
            coreUsage._idlepourcent = std::string(out.str() + "%");
        }
        out.str("");
    }
}

void CPUModule::setCPUUsage()
{
    _coreNumber = std::thread::hardware_concurrency();
    this->setActiveTasks();
    this->setModelName();
    _cores1.clear();
    _cores2.clear();
    _CPUUsage.clear();
    this->readStatsCPU1();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    this->readStatsCPU2();
    this->setPourcentageUsage();
}

std::vector<CPUDataFinal> CPUModule::getCPUUsage() const
{
    return _CPUUsage;
}

int CPUModule::getCoreNumber() const
{
    return _coreNumber;
}

int CPUModule::getActiveTasks() const
{
    return _activeTasks;    
}

void CPUModule::setActiveTasks()
{
    std::ifstream activeFile("/proc/loadavg");
    std::string activeTasks;

    if (!activeFile.is_open()) {
        _activeTasks = 0;
        return;
    }
    std::getline(activeFile, activeTasks);
    activeTasks = activeTasks.substr(activeTasks.find(" ") + 1);
    activeTasks = activeTasks.substr(activeTasks.find(" ") + 1);
    activeTasks = activeTasks.substr(activeTasks.find(" ") + 1);
    activeTasks = activeTasks.substr(0, activeTasks.find("/"));
    _activeTasks = std::stoi(activeTasks);
    activeFile.close();
}

void CPUModule::setModelName()
{
    std::ifstream CpuFile("/proc/cpuinfo");
    std::string CpuModel;

    if (!CpuFile.is_open()) {
        _modelName = std::string("Unknow processor model");
        return;
    }
    std::getline(CpuFile, CpuModel);
    std::getline(CpuFile, CpuModel);
    std::getline(CpuFile, CpuModel);
    std::getline(CpuFile, CpuModel);
    std::getline(CpuFile, CpuModel);
    CpuModel = CpuModel.substr(CpuModel.find(":") + 2);
    _modelName = std::string(CpuModel);
    CpuFile.close();
}

const std::string CPUModule::getModelName() const
{
    return _modelName;
}
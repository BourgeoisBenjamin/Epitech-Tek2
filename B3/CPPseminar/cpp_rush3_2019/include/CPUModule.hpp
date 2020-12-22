/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** TODO: add description
*/

#ifndef CPP_RUSH3_2019_CPUMODULE_HPP
#define CPP_RUSH3_2019_CPUMODULE_HPP

#include "interfaces/IMonitorModule.hpp"
#include <vector>

#define NUM_CPU_STATES 10

enum TIMECPUSTATES
{
    S_USER,
    S_NICE,
    S_SYSTEM,
    S_IDLE,
    S_IOWAIT,
    S_IRQ,
    S_SOFTIRQ,
    S_STEAL,
    S_GUEST,
    S_GUESTNICE
};

typedef struct CPUData
{
    std::string cpu;
    size_t times[NUM_CPU_STATES];
    double _active;
    double _idle;
    std::string _activepourcent;
    std::string _idlepourcent;
} CPUData;

typedef struct CPUDataFinal
{
    std::string cpu;
    std::string _activepourcent;
    std::string _idlepourcent;
} CPUDataFinal;

class CPUModule : public IMonitorModule
{
public:
    CPUModule();
    ~CPUModule();
    CPUModule(const CPUModule &);
    CPUModule&operator=(const CPUModule& rhs);

    const std::string &getModuleName() const;
    bool refreshInfoModule();

    std::vector<CPUDataFinal> getCPUUsage() const;

    int getCoreNumber() const;
    int getActiveTasks() const;
    const std::string getModelName() const;

private:
    const std::string _name;
    int _coreNumber;
    int _activeTasks;
    std::string _modelName;
    std::vector<CPUData> _cores1;
    std::vector<CPUData> _cores2;
    std::vector<CPUDataFinal> _CPUUsage;

private:
    void setCPUUsage();
    void readStatsCPU1();
    void readStatsCPU2();
    void setPourcentageUsage();
    void setActiveTasks();
    void setModelName();
};

#endif //CPP_RUSH3_2019_CPUMODULE_HPP

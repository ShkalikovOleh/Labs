#include "ViewModel.h"

ViewModel::ViewModel(ILog* logger)
{
    this->logger = logger;
};

void ViewModel::subscribe(void (*OnChange)(const ViewModel*))
{
    if(OnChange)
        subscribers.push_back(OnChange);
};

void ViewModel::broadcast()
{
    for (auto &&subscriber : subscribers)
    {
        subscriber(this);
    }    
};
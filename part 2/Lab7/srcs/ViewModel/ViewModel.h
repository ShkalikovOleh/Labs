#ifndef VIEW_MODEL_H
#define VIEW_MODEL_H

#include "../Log.h"
#include <vector>

class ViewModel
{
public:
    ViewModel(ILog*);
    void subscribe(void (*)(const ViewModel*));
protected:
    ILog* logger;
    std::vector<void (*)(const ViewModel*)> subscribers;
    void broadcast();
};

#endif
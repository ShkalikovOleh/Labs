#ifndef VIEW_MODEL_H
#define VIEW_MODEL_H

#include "../Log.h"
#include <functional>
#include <vector>

class ViewModel
{
public:
    ViewModel(ILog*);
    void subscribe(std::function<void(const ViewModel*)>);
protected:
    ILog* logger;
    std::vector<std::function<void(const ViewModel*)> > subscribers;
    void broadcast();
};

#endif
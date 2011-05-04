#ifndef DRUGMODEL_H
#define DRUGMODEL_H

#include "lib/DbModel.h"

class DrugModel : public DbModel
{
public:
    DrugModel();

    void addItem();
};

#endif // DRUGMODEL_H

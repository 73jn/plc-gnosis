/*

Copyright (C) 2013 Donald Harris (dharris.ubc@gmail.com)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>

*/

#ifndef NODECONFIGURATION_H
#define NODECONFIGURATION_H

#include <QDialog>

#include "nodemodel.h"
#include "plcdatainputwidget.h"

#include <QListWidget>
#include <QGroupBox>

class NodeConfiguration : public QDialog
{
    Q_OBJECT
public:

    explicit NodeConfiguration(NodeModel* node, QDialog *parent = 0);
    void setModel(NodeModel * newModel);

signals:

protected:
    virtual void closeEvent(QCloseEvent * event);
    
public slots:
    void editNetDevices(QListWidgetItem* item);
    void editNoiseSources(QListWidgetItem* item);
    void saveAndClose();



private:
    NodeModel* nodeModel;

    QGroupBox* outletSettings;

    PLCDataInputWidget* outletImpedanceInput;

    QListWidget* netDevicesView;
    QListWidget* noiseSourcesView;

    void populateFromModel();
};

#endif // NODECONFIGURATION_H
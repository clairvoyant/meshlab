/*****************************************************************************
 * MeshLab                                                           o o     *
 * A versatile mesh processing toolbox                             o     o   *
 *                                                                _   O  _   *
 * Copyright(C) 2005-2021                                           \/)\/    *
 * Visual Computing Lab                                            /\/|      *
 * ISTI - Italian National Research Council                           |      *
 *                                                                    \      *
 * All rights reserved.                                                      *
 *                                                                           *
 * This program is free software; you can redistribute it and/or modify      *
 * it under the terms of the GNU General Public License as published by      *
 * the Free Software Foundation; either version 2 of the License, or         *
 * (at your option) any later version.                                       *
 *                                                                           *
 * This program is distributed in the hope that it will be useful,           *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of            *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
 * GNU General Public License (http://www.gnu.org/licenses/gpl.txt)          *
 * for more details.                                                         *
 *                                                                           *
 ****************************************************************************/

#ifndef FILTERDIRTPLUGIN_H
#define FILTERDIRTPLUGIN_H

#include <QObject>
#include <QString>
#include <QStringList>
#include <common/plugins/interfaces/filter_plugin.h>
#include <vcg/complex/complex.h>
#include <vector>

using namespace vcg;

class FilterDirt : public QObject, public FilterPlugin
{
	Q_OBJECT
	MESHLAB_PLUGIN_IID_EXPORTER(FILTER_PLUGIN_IID)
	Q_INTERFACES(FilterPlugin)

public:
	enum { FP_DIRT, FP_CLOUD_MOVEMENT };

	FilterDirt();
	~FilterDirt() {};

	QString         pluginName() const;
	virtual QString filterName(ActionIDType filter) const;
	virtual QString filterInfo(ActionIDType filter) const;
	virtual int     getRequirements(const QAction*);
	virtual bool    autoDialog(QAction*) { return true; }
	//      virtual void initParameterSet(QAction* filter,MeshModel &,RichParameterSet &){};
	RichParameterList               initParameterList(const QAction*, const MeshDocument& /*m*/);
	std::map<std::string, QVariant> applyFilter(
		const QAction* action,
		const RichParameterList& /*parent*/,
		MeshDocument&     md,
		unsigned int&     postConditionMask,
		vcg::CallBackPos* cb);
	virtual int         postCondition(const QAction*) const;
	virtual FilterClass getClass(const QAction*) const;
	FilterArity         filterArity(const QAction*) const { return SINGLE_MESH; }
};

#endif

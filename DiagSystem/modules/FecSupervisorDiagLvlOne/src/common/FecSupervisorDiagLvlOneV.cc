
/*************************************************************************
 * XDAQ Components for Distributed Data Acquisition                      *
 * Copyright (C) 2000-2004, CERN.			                 *
 * All rights reserved.                                                  *
 * Authors: J. Gutleber and L. Orsini					 *
 *                                                                       *
 * For the licensing terms see LICENSE.		                         *
 * For the list of contributors see CREDITS.   			         *
 *************************************************************************/

#include "toolboxV.h"
#include "xoap/version.h"
#include "xdaqV.h"
#include "FecSupervisorDiagLvlOneV.h"

GETPACKAGEINFO(FecSupervisorDiagLvlOne)

void FecSupervisorDiagLvlOne::checkPackageDependencies() throw (toolbox::PackageInfo::VersionException)
{
/*
        CHECKDEPENDENCY(toolbox)
        CHECKDEPENDENCY(xoap)
	CHECKDEPENDENCY(xdaq)
*/
}

set<string, less<string> > FecSupervisorDiagLvlOne::getPackageDependencies()
{
    set<string, less<string> > dependencies;
/*
    ADDDEPENDENCY(dependencies,toolbox);
    ADDDEPENDENCY(dependencies,xoap);
    ADDDEPENDENCY(dependencies,xdaq);
*/
    return dependencies;
}	
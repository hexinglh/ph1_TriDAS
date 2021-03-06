# $Id: Makefile,v 1.23 2012/01/21 17:36:11 kreis Exp $

#########################################################################
# XDAQ Components for Distributed Data Acquisition                      #
# Copyright (C) 2000-2004, CERN.			                #
# All rights reserved.                                                  #
# Authors: J. Gutleber and L. Orsini					#
#                                                                       #
# For the licensing terms see LICENSE.		                        #
# For the list of contributors see CREDITS.   			        #
#########################################################################

##
#
# This is the example Makefile
#
# make Library=ExampleName
#
##
##################################################################
include $(ENV_CMS_TK_ONLINE_ROOT)/FecHeader.linux
include $(ENV_CMS_TK_ONLINE_ROOT)/config/FecRules.linux
##################################################################


##################################################################
#SBSINCLUDEDIR:=/usr/local/SBS/1003/v2p3p0/include
##################################################################

include $(XDAQ_ROOT)/config/mfAutoconf.rules
include $(XDAQ_ROOT)/config/mfDefs.$(XDAQ_OS)



##################################################################
# Packages to be built
#
FECSOFTWARE_ROOT:=${ENV_CMS_TK_ONLINE_ROOT}
##################################################################
Project=pixel
Package=PixelTKFECSupervisor

Sources=PixelTKFECSupervisor.cc DiagWrapper.cc

IncludeDirs = \
        $(BUILD_HOME)/$(Project) \
	$(FECSOFTWARE_ROOT)/generic/include \
        $(FECSOFTWARE_ROOT)/ThirdParty/APIConsoleDebugger/include \
	${FECSOFT_INCLUDE} \
        $(XDAQ_ROOT)/include \
	$(XDAQ_ROOT)/include/hal \
        $(ENV_CMS_TK_DIAG_ROOT)/tools/soapdiagappender/include \
        $(ENV_CMS_TK_DIAG_ROOT)/tools/xmldiagappender/include \
        $(ENV_CMS_TK_DIAG_ROOT)/tools/diagbag/include \
        $(ENV_CMS_TK_DIAG_ROOT)/toolbox \
        $(ENV_CMS_TK_DIAG_ROOT)



LibraryDirs = 

UserSourcePath = \
	$(XDAQ_ROOT)/daq/xdaq/src/linux/common/

UserCFlags = -O
UserCCFlags = -g -O -Wno-long-long -DBT1003 ${BUSADAPTERC++FLAG} -std=c++0x
UserDynamicLinkFlags =
UserStaticLinkFlags =
UserExecutableLinkFlags =

# These libraries can be platform specific and
# potentially need conditional processing
#

ROOTLibs = AfterImage ASImageGui ASImage \
         Core Cint New Ged GeomPainter Geom Gpad \
         Gui GuiBld GX11 GX11TTF freetype Graf Graf3d Hist HistPainter \
         Matrix Minuit Postscript Tree TreePlayer TreeViewer \
         Rint RGL X3d EG Thread

DependentLibraryDirs = $(BUILD_HOME)/pixel/lib \
                       $(ENV_CMS_TK_ONLINE_ROOT)/lib \
                       $(ENV_CMS_TK_DIAG_ROOT)/tools/lib \
                       $(shell root-config --libdir) \
                       $(XDAQ_ROOT)/lib
#$(ROOTSYS)/lib \

DependentLibraries = SiPixelObjects TkDiagBagWizard xmldiagappender PixelGUIUtilities PixelTKFECDataTools PixelSupervisorConfiguration PixelCalibrations PixelTestStandUtilities PixelFEDInterface Pixelb2inUtilities PixelDCSUtilities occi nnz11 clntsh

DependentLibraries += $(ROOTLibs)


ifeq ($(VMEDUMMY), yes)
UserCCFlags += -DVMEDUMMY
BusAdapter:=VMEDummyBusAdapter
else
BusAdapter:=CAENLinuxBusAdapter
endif


Libraries = 
ExternalObjects = -L$(XDAQ_ROOT)/lib  \
	-l$(BusAdapter) -lGenericHAL -lHALUtilities \
        -L$(ENV_CMS_TK_CAEN_ROOT) -lCAENVME \
        -L$(BUILD_HOME)/FecSoftwareV3_0/lib \
	-lAPIFecVme -lDeviceAccess 


#
# Compile the source files and create a shared library
#

DynamicLibrary= PixelTKFECSupervisor


StaticLibrary=

ifdef Executable
Libraries=toolbox xdata xcept xoap xerces-c log4cplus mimetic
Executables= $(Executable).cc
endif

include $(XDAQ_ROOT)/config/Makefile.rules
include $(BUILD_HOME)/$(Project)/RPM.version
include $(XDAQ_ROOT)/config/mfRPM.rules

//---------------------------------------------------------------------------//
//                        RODFFrame.cpp -
//  Some helping methods for usage within sumo and sumo-gui
//                           -------------------
//  project              : SUMO - Simulation of Urban MObility
//  begin                : Sept 2002
//  copyright            : (C) 2002 by Daniel Krajzewicz
//  organisation         : IVF/DLR http://ivf.dlr.de
//  email                : Daniel.Krajzewicz@dlr.de
//---------------------------------------------------------------------------//

//---------------------------------------------------------------------------//
//
//   This program is free software; you can redistribute it and/or modify
//   it under the terms of the GNU General Public License as published by
//   the Free Software Foundation; either version 2 of the License, or
//   (at your option) any later version.
//
//---------------------------------------------------------------------------//
namespace
{
    const char rcsid[] =
    "$Id$";
}
// $Log$
// Revision 1.1  2005/12/08 12:59:41  ericnicolay
// *** empty log message ***
//
// Revision 1.6  2005/11/29 13:33:08  dkrajzew
// debugging
//
// Revision 1.5  2005/10/07 11:42:28  dkrajzew
// THIRD LARGE CODE RECHECK: patched problems on Linux/Windows configs
//
// Revision 1.4  2005/09/23 06:04:48  dkrajzew
// SECOND LARGE CODE RECHECK: converted doubles and floats to SUMOReal
//
// Revision 1.3  2005/09/15 12:05:23  dkrajzew
// LARGE CODE RECHECK
//
// Revision 1.2  2005/05/04 08:57:12  dkrajzew
// level 3 warnings removed; a certain SUMOTime time description added
//
// Revision 1.1  2004/11/23 10:26:27  dkrajzew
// debugging
// Revision 1.2  2005/02/17 09:27:35  dksumo
// code beautifying;
// some warnings removed;
// compileable under linux
//
// Revision 1.1  2004/10/22 12:50:28  dksumo
// initial checkin into an internal, standalone SUMO CVS
//
/* =========================================================================
 * compiler pragmas
 * ======================================================================= */
#pragma warning(disable: 4786)


/* =========================================================================
 * included modules
 * ======================================================================= */
#ifdef HAVE_CONFIG_H
#ifdef WIN32
#include <windows_config.h>
#else
#include <config.h>
#endif
#endif // HAVE_CONFIG_H

#include <iostream>
#include <fstream>
#include <ctime>
#include <utils/options/OptionsCont.h>
#include <utils/options/Option.h>
#include <utils/common/MsgHandler.h>
#include <utils/common/UtilExceptions.h>
#include <utils/common/ToString.h>
#include "RODFFrame.h"
#include <router/ROFrame.h>

#ifdef _DEBUG
#include <utils/dev/debug_new.h>
#endif // _DEBUG


/* =========================================================================
 * used namespaces
 * ======================================================================= */
using namespace std;


/* =========================================================================
 * method definitions
 * ======================================================================= */
void
RODFFrame::fillOptions_basicImport(OptionsCont &oc)
{
	ROFrame::fillOptions(oc);
	addDFOptions(oc);
}


void
RODFFrame::fillOptions_fullImport(OptionsCont &oc)
{
	ROFrame::fillOptions(oc);
	addImportOptions(oc);
	addDFOptions(oc);
}


void
RODFFrame::addImportOptions(OptionsCont &oc)
{
    oc.doRegister("cell-input", new Option_FileName());
    oc.doRegister("artemis-input", new Option_FileName());
    oc.doRegister("flow-definition", 'f', new Option_FileName());
    oc.doRegister("sumo-input", 's', new Option_FileName());
    oc.doRegister("trip-defs", 't', new Option_FileName());
    oc.addSynonyme("flow-definition", "flows");
    oc.addSynonyme("artemis", "artemis-input");
    oc.addSynonyme("cell", "cell-input");
    oc.addSynonyme("sumo", "sumo-input");
    oc.addSynonyme("trips", "trip-defs");
    oc.doRegister("save-cell-rindex", new Option_Bool(false));
    oc.doRegister("intel-cell", new Option_Bool(false));
    oc.doRegister("no-last-cell", new Option_Bool(false));
}


void
RODFFrame::addDFOptions(OptionsCont &oc)
{
    //oc.doRegister( "supplementary-weights", 'S', new Option_FileName() );
    //oc.addSynonyme("supplementary-weights", "add");
    //oc.doRegister("scheme", 'x', new Option_String("traveltime"));
    // register Gawron's DUE-settings
    //oc.doRegister("gBeta", new Option_Float(SUMOReal(0.3)));
    //oc.doRegister("gA", new Option_Float((SUMOReal) 0.05));
}


bool
RODFFrame::checkOptions(OptionsCont &oc)
{
	return ROFrame::checkOptions(oc);
}


/**************** DO NOT DEFINE ANYTHING AFTER THE INCLUDE *****************/

// Local Variables:
// mode:C++
// End:



///////////////////////////////////////////////////////////////////////////////
// FILE:          ALC_REV_ILEActiveBlankingManagementWrapper.h
// PROJECT:       Micro-Manager
// SUBSYSTEM:     DeviceAdapters
//-----------------------------------------------------------------------------

#ifndef _ALC_REV_ILEACTIVEBLANKINGMGTWRAPPER_H_
#define _ALC_REV_ILEACTIVEBLANKINGMGTWRAPPER_H_

#include "ALC_REV.h"

class CALC_REV_ILEActiveBlankingManagementWrapper : public IALC_REV_ILEActiveBlankingManagement
{
public:
  CALC_REV_ILEActiveBlankingManagementWrapper( IALC_REV_ILEActiveBlankingManagement* ALC_REV_ILEActiveBlankingManagement );
  ~CALC_REV_ILEActiveBlankingManagementWrapper();

  // IALC_REV_ILEActiveBlankingManagement
  bool IsActiveBlankingManagementPresent( bool *Present );
  bool GetNumberOfLines( int *NumberOfLines );
  bool GetActiveBlankingState( int *EnabledPattern );
  bool SetActiveBlankingState( int EnabledPattern );
 
private:
  IALC_REV_ILEActiveBlankingManagement* ALC_REV_ILEActiveBlankingManagement_;
};

#endif

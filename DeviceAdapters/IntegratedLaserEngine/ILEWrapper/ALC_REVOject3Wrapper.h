///////////////////////////////////////////////////////////////////////////////
// FILE:          ALC_REVObject3Wrapper.h
// PROJECT:       Micro-Manager
// SUBSYSTEM:     DeviceAdapters
//-----------------------------------------------------------------------------

#ifndef _ALC_REVOBJECT3WRAPPER_H_
#define _ALC_REVOBJECT3WRAPPER_H_

#include "ALC_REV.h"
#include <string>

class CALC_REV_ILEWrapper;
class CALC_REV_Laser2Wrapper;
class CALC_REV_PortWrapper;

class CALC_REVObject3Wrapper : public IALC_REVObject3
{
public:
  CALC_REVObject3Wrapper( HMODULE DLL, const char* UnitID );
  ~CALC_REVObject3Wrapper();

  IALC_REVObject3* GetILEObject() { return ALC_REVObject3_; }

  // IALC_REVObject3
  IALC_REV_Laser3* GetLaserInterface3();
  IALC_REV_ILE* GetILEInterface();

  // IALC_REVObject2
  IALC_REV_Laser* GetLaserInterface();
  IALC_REV_Laser2* GetLaserInterface2();
  IALC_REV_Piezo* GetPiezoInterface();
  IALC_REV_DIO* GetDIOInterface();
  IALC_REV_Port* GetPortInterface();

private:
  HMODULE DLL_;
  IALC_REVObject3* ALC_REVObject3_;
  std::string UnitID_;

  CALC_REV_ILEWrapper* ALC_REV_ILEWrapper_;
  CALC_REV_Laser2Wrapper* ALC_REV_Laser2Wrapper_;
  CALC_REV_PortWrapper* ALC_REV_PortWrapper_;

  typedef bool( __stdcall *TCreate_ILE_REV3 )( IALC_REVObject3 **ALC_REVObject3, const char *UnitID );
  typedef bool( __stdcall *TDelete_ILE_REV3 )( IALC_REVObject3 *ALC_REVObject3 );

  TCreate_ILE_REV3 Create_ILE_REV3_;
  TDelete_ILE_REV3 Delete_ILE_REV3_;
};

#endif

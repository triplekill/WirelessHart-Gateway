/*
* Copyright (C) 2013 Nivis LLC.
* Email:   opensource@nivis.com
* Website: http://www.nivis.com
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, version 3 of the License.
* 
* Redistribution and use in source and binary forms must retain this
* copyright notice.

* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
*/

//
// C++ Interface: AppDeviceHealthReportCmd
//
// Description: 
//
//
// Author: Catrina Mihailescu <catrina@r2d2>, (C) 2010
//
//
//

#ifndef __APPDEVICEHEALTHREPORTCMD_H_
#define __APPDEVICEHEALTHREPORTCMD_H_

#include <WHartHost/applicationcmds/AbstractAppCommand.h>
#include <WHartHost/database/DevicesManager.h>
#include <WHartHost/model/reports/DeviceHealth.h>


namespace hart7 {
namespace hostapp {

class IAppCommandVisitor;
class AppDeviceHealthReportCmd;

typedef boost::shared_ptr<AppDeviceHealthReportCmd> AppDeviceHealthReportCmdPtr;

class AppDeviceHealthReportCmd: public AbstractAppCommand
{
public:
	AppDeviceHealthReportCmd(std::list<std::pair<int, MAC> > &list);
	virtual bool Accept(IAppCommandVisitor& visitor);

protected:
	void DumpToStream(std::ostream& p_rStream) const;

public:
	void ReportReceived();
	bool ReceivedAllReports();
	std::vector<DeviceHealth>& GetDevicesHealth();

 private:
	int m_nNbOfNeededReports;

private:
	std::vector<DeviceHealth> m_oDevicesHealth;
};

}
}

#endif // _APPDEVICEHEALTHREPORTCMD_H_

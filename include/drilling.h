/*
** Copyright 2014-2018 The Earlham Institute
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/
/*
 * drilling.h
 *
 *  Created on: 23 Jul 2018
 *      Author: billy
 */

#ifndef SERVICES_DFW_FIELD_TRIAL_SERVICE_INCLUDE_DRILLING_H_
#define SERVICES_DFW_FIELD_TRIAL_SERVICE_INCLUDE_DRILLING_H_


#include "typedefs.h"
#include "dfw_field_trial_service_library.h"
#include "germplasm.h"
#include "coordinate.h"


typedef struct Drilling
{
	uint32 dr_plot_id;

	uint32 dr_field_id;

	Germplasm *dr_germplasm_p;

	uint32 dr_date;

	Coordinate *dr_gps_north_east_p;

	Coordinate *dr_gps_south_west_p;

} Drilling;


#ifdef __cplusplus
extern "C"
{
#endif


#ifdef __cplusplus
}
#endif

#endif /* SERVICES_DFW_FIELD_TRIAL_SERVICE_INCLUDE_DRILLING_H_ */
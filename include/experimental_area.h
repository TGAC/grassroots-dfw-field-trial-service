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
 * experimental_area.h
 *
 *  Created on: 11 Sep 2018
 *      Author: billy
 */

#ifndef SERVICES_DFW_FIELD_TRIAL_SERVICE_INCLUDE_EXPERIMENTAL_AREA_H_
#define SERVICES_DFW_FIELD_TRIAL_SERVICE_INCLUDE_EXPERIMENTAL_AREA_H_


#include "field_trial.h"


typedef struct ExperimentalArea
{
	uint32 ea_id;

	FieldTrial *ea_parent_p;

	char *ea_location_s;

	char *ea_soil_type_s;

	char *ea_name_s;

	uint32 ea_year;

} ExperimentalArea;


#endif /* SERVICES_DFW_FIELD_TRIAL_SERVICE_INCLUDE_EXPERIMENTAL_AREA_H_ */

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

#ifndef SERVICES_DFW_FIELD_TRIAL_SERVICE_INCLUDE_STUDY_H_
#define SERVICES_DFW_FIELD_TRIAL_SERVICE_INCLUDE_STUDY_H_


#include <time.h>

#include "dfw_field_trial_service_data.h"
#include "dfw_field_trial_service_library.h"
#include "field_trial.h"
#include "location.h"
#include "jansson.h"

#include "typedefs.h"
#include "address.h"


#ifndef DOXYGEN_SHOULD_SKIP_THIS

#ifdef ALLOCATE_STUDY_TAGS
	#define STUDY_PREFIX DFW_FIELD_TRIAL_SERVICE_LOCAL
	#define STUDY_VAL(x)	= x
	#define STUDY_CONCAT_VAL(x,y)	= x y
#else
	#define STUDY_PREFIX extern
	#define STUDY_VAL(x)
	#define STUDY_CONCAT_VAL(x,y)
#endif

#endif 		/* #ifndef DOXYGEN_SHOULD_SKIP_THIS */


STUDY_PREFIX const char *ST_ID_S STUDY_VAL ("id");

STUDY_PREFIX const char *ST_NAME_S STUDY_CONCAT_VAL (CONTEXT_PREFIX_SCHEMA_ORG_S, "name");

STUDY_PREFIX const char *ST_LOCATION_ID_S STUDY_VAL ("address_id");

STUDY_PREFIX const char *ST_LOCATION_S STUDY_VAL ("address");


STUDY_PREFIX const char *ST_SOIL_S STUDY_VAL ("soil");

STUDY_PREFIX const char *ST_SOWING_DATE_S STUDY_VAL ("sowing_date");

STUDY_PREFIX const char *ST_HARVEST_DATE_S STUDY_VAL ("harvest_date");


STUDY_PREFIX const char *ST_PARENT_FIELD_TRIAL_S STUDY_VAL ("parent_field_trial_id");

STUDY_PREFIX const char *ST_PLOTS_S STUDY_VAL ("plots");

STUDY_PREFIX const char *ST_DATA_LINK_S STUDY_CONCAT_VAL (CONTEXT_PREFIX_SCHEMA_ORG_S, "url");


typedef struct Study
{
	bson_oid_t *st_id_p;

	FieldTrial *st_parent_p;

	//char *st_location_s;
	struct Location *st_location_p;

	//Address *st_address_p;

	char *st_soil_type_s;

	char *st_name_s;

	char *st_data_url_s;

	struct tm *st_sowing_date_p;

	struct tm *st_harvest_date_p;

	/**
	 * A LinkedList of PlotNodes
	 * for all of the Plots in this
	 * Study.
	 */
	LinkedList *st_plots_p;

} Study;



typedef struct StudyNode
{
	ListItem stn_node;

	Study *stn_study_p;

} StudyNode;



#ifdef __cplusplus
extern "C"
{
#endif


DFW_FIELD_TRIAL_SERVICE_LOCAL Study *AllocateStudy (bson_oid_t *id_p, const char *name_s, const char *soil_s, const char *data_url_s, const struct tm *sowing_date_p, const struct tm *harvest_date_p, struct Location *location_p, FieldTrial *parent_field_trial_p, const DFWFieldTrialServiceData *data_p);

DFW_FIELD_TRIAL_SERVICE_LOCAL void FreeStudy (Study *study_p);

DFW_FIELD_TRIAL_SERVICE_LOCAL StudyNode *AllocateStudyNode (Study *study_p);

DFW_FIELD_TRIAL_SERVICE_LOCAL void FreeStudyNode (ListItem *node_p);

DFW_FIELD_TRIAL_SERVICE_LOCAL json_t *GetStudyAsJSON (Study *study_p, const ViewFormat format, const DFWFieldTrialServiceData *data_p);

DFW_FIELD_TRIAL_SERVICE_LOCAL Study *GetStudyFromJSON (const json_t *json_p, const ViewFormat format, const DFWFieldTrialServiceData *data_p);

DFW_FIELD_TRIAL_SERVICE_LOCAL bool GetStudyPlots (Study *study_p, const DFWFieldTrialServiceData *data_p);

DFW_FIELD_TRIAL_SERVICE_LOCAL bool SaveStudy (Study *study_p, DFWFieldTrialServiceData *data_p);

DFW_FIELD_TRIAL_SERVICE_LOCAL Study *GetStudyByIdString (const char *arst_id_s, const ViewFormat format, const DFWFieldTrialServiceData *data_p);

DFW_FIELD_TRIAL_SERVICE_LOCAL Study *GetStudyById (bson_oid_t *arst_id_p, const ViewFormat format, const DFWFieldTrialServiceData *data_p);


#ifdef __cplusplus
}
#endif


#endif /* SERVICES_DFW_FIELD_TRIAL_SERVICE_INCLUDE_STUDY_H_ */
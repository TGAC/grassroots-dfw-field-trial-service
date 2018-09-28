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
 * row.h
 *
 *  Created on: 11 Sep 2018
 *      Author: billy
 */

#ifndef SERVICES_DFW_FIELD_TRIAL_SERVICE_INCLUDE_ROW_H_
#define SERVICES_DFW_FIELD_TRIAL_SERVICE_INCLUDE_ROW_H_


#include "plot.h"
#include "material.h"


typedef struct Row
{
	bson_oid_t *ro_id_p;

	Plot *ro_plot_p;

	uint32 ro_index;

	Material *ro_material_p;
} Row;


typedef struct RowNode
{
	ListItem rn_node;

	Row *rn_row_p;
} RowNode;


#ifdef __cplusplus
extern "C"
{
#endif


DFW_FIELD_TRIAL_SERVICE_LOCAL Row *AllocateRow (bson_oid_t *id_p, const uint32 index, Material *material_p, Plot *parent_plot_p);

DFW_FIELD_TRIAL_SERVICE_LOCAL void FreeRow (Row *row_p);

DFW_FIELD_TRIAL_SERVICE_LOCAL RowNode *AllocateRowNode (Row *row_p);

DFW_FIELD_TRIAL_SERVICE_LOCAL void FreeRowNode (ListItem *node_p);


DFW_FIELD_TRIAL_SERVICE_LOCAL json_t *GetRowAsJSON (const Row *row_p);


#ifdef __cplusplus
}
#endif


#endif /* SERVICES_DFW_FIELD_TRIAL_SERVICE_INCLUDE_ROW_H_ */